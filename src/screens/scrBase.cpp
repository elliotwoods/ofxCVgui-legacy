/*
 *  scrBase.cpp
 *  screen base class
 *	designed as part of pixel correlation project
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofxCVgui.h"

scrBase::scrBase(string _caption) :
isFullscreen(_isFullscreen) {
	_isFullscreen = false;
	
	_isMouseAttached = false;
	
	caption = _caption;
	
	_hasChrome = true;
	enabled = true;
	_lock = 0;
}

scrBase::~scrBase() {
	
}

bool scrBase::isHit(float x, float y) {
	return getLiveBounds().inside(x, y);
}

void scrBase::mousePressed(float x, float y, int button) {
    _isMouseAttached = true;
	ofVec2f m = normaliseMouse(x,y);
    ofNotifyEvent(evtMousePressed, m, this);
}

void scrBase::mouseMoved(float x, float y) {
	ofVec2f m = normaliseMouse(x,y);
    ofNotifyEvent(evtMouseMoved, m, this);
}

void scrBase::mouseDragged(float x, float y, float dx, float dy, int button) {
	ofVec2f m = normaliseMouse(x,y);
    ofNotifyEvent(evtMousePressed, m, this);
}

void scrBase::transformMouse(float mouseX, float mouseY, float &screenX, float &screenY) {
    ofRectangle liveBounds = getLiveBounds();
    
	screenX = (mouseX - float(liveBounds.x)) / liveBounds.width;
	screenY = (mouseY - float(liveBounds.y)) / liveBounds.height;
}

ofVec2f scrBase::normaliseMouse(float x, float y) {
	ofRectangle b = getLiveBounds();
    return ofVec2f((x-b.x) / b.width,
				   (y-b.y) / b.height);

}

void scrBase::setLock(ofMutex &m) {
	_lock = &m;
}

void scrBase::draw() {
	if (enabled) {
		
		if (_lock != 0)
			if (!_lock->tryLock())
				return;
		drawContent();
		
		ofRectangle liveBounds = getLiveBounds();
		ofNotifyEvent(evtDraw, liveBounds, this);
		
		if (_lock != 0)
			_lock->unlock();
		
	}
	
	if (_hasChrome && g_isInterfaceEnabled)
		drawChrome();
}

void scrBase::drawChrome() {
	int x, y, width, height;
	getLiveBounds(x, y, width, height);
	
	int x2, y2;
	x2 = x+width; y2 = y+height;
	
	
	//
	// BORDER
	//
	ofPushStyle();
	ofNoFill();
	ofSetLineWidth(GUI_INTERFACE_BORDER_LINE_WIDTH);
	ofSetColor(255,255,255);
	
	int inset=GUI_INTERFACE_BORDER_LINE_WIDTH/2;
	
	//top,bottom,left,right
	ofLine(x, y+inset, x2, y+inset);
	ofLine(x, y2-inset, x2, y2-inset);
	
	ofLine(x+inset, y, x+inset, y2);
	ofLine(x2-inset, y, x2-inset, y2);
	
	ofPopStyle();
	
		
	//
	//CAPTION
	//
	ofPushStyle();
	ofSetColor(255,255,255);
	ofSetLineWidth(0);
	ofFill();
	ofRectangle boundBox;
	boundBox.x = x;
	boundBox.y = y;
	boundBox.width = caption.length() * 10 + 6;
	boundBox.height = 16;
	ofRect(boundBox);
	ofPopStyle();
	
	ofPushStyle();
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(caption, x+3, y+14);
	ofPopStyle();
}

//---------------------------------------------------------------------------------
bool scrBase::hitMaximise(float x, float y) {
	_isFullscreen = !_isFullscreen;
	return _isFullscreen;
}

void scrBase::hitMaximise(float x, float y, bool input) {
	_isFullscreen = input;
}

void scrBase::setBounds(ofRectangle &bounds) {
    _bounds = bounds;
	
	doResize();
}

void scrBase::getLiveBounds(int &x, int &y, int &w, int &h) {
    ofRectangle liveBounds = getLiveBounds();
    
    x = liveBounds.x;
    y = liveBounds.y;
    w = liveBounds.width;
    h = liveBounds.height;
}

ofRectangle scrBase::getLiveBounds() {
    ofRectangle liveBounds;
    
    if (_isFullscreen)
	{
		liveBounds.x = 0;
		liveBounds.y = 0;
		liveBounds.width = ofGetWidth();
		liveBounds.height = ofGetHeight();
	} else
        liveBounds = _bounds;
    
    return liveBounds;
}

//---------------------------------------------------------------------------------
void scrBase::updateInterface() {
	_lastLocalInterfaceUpdate = ofGetElapsedTimef();
}

bool scrBase::isUserActive() {
	return (_lastLocalInterfaceUpdate + GUI_INTERFACE_DISPLAY_TIME) > ofGetElapsedTimef();
}
