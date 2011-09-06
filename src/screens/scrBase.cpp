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
isFullscreen(_isFullscreen)
{
	//_btnMaximise = new btnBase(button_toggle, *_assetButtonPlus, *_assetButtonPlus_over);
	//_vecInterfaceButtons.push_back(_btnMaximise);
//	ofAddListener(_btnMaximise->buttonHit, this, &scrBase::hitMaximise);
	_isFullscreen = false;
	
	_isCursorAttached = false;
	
	caption = _caption;
	
	_hasChrome = true;
	enabled = true;
	_lock = 0;

}

scrBase::~scrBase()
{
	for (int iButton=0; iButton<_vecInterfaceButtons.size(); iButton++) {
		delete _vecInterfaceButtons.at(iButton);
	}
	
	_vecInterfaceButtons.clear();
}

bool scrBase::isHit(int x, int y)
{
	return _bounds.inside(x, y);
}

void scrBase::mousePressed(int x, int y, int button)
{
    _isCursorAttached = true;
    
	ofRectangle b = getLiveBounds();
    ofPoint mouseXY = ofPoint((float(x)-b.x)/b.width, (float(y)-b.y)/b.height);
    ofNotifyEvent(evtCursorPressed, mouseXY, this);
}

void scrBase::mouseMoved(int x, int y)
{
    ofPoint mouseXY = ofPoint(x,y);
    ofNotifyEvent(evtCursorMove, mouseXY, this);
}

void scrBase::mouseDragged(int x, int y, int dx, int dy, int button)
{
    ofPoint mouseXY = ofPoint(x,y);
    ofNotifyEvent(evtCursorPressed, mouseXY, this);
}

bool scrBase::transformMouse(float mouseX, float mouseY, float &screenX, float &screenY)
// transforms the mouse into screen coords
// returns 'true' if mouse is inside this screen
{
    ofRectangle liveBounds = getLiveBounds();
    
	screenX = (mouseX - float(liveBounds.x)) / liveBounds.width;
	screenY = (mouseY - float(liveBounds.y)) / liveBounds.height;
	
	if (screenX >= 0 && screenX <= 1)
		if (screenY >= 0 && screenY <= 1)
			return true;
	
	return false;
}

void scrBase::setLock(ofMutex &m) {
	_lock = &m;
}

void scrBase::draw()
{
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

void scrBase::drawChrome()
{
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
	// BUTTONS
	//
	int button_x, button_y;
	button_y = y+height-GUI_INTERFACE_BUTTON_SIZE;
	
	for (int iButton = 0; iButton < _vecInterfaceButtons.size(); iButton++)
	{
		button_x = x+width-(GUI_INTERFACE_BUTTON_SIZE*(iButton+1));
		_vecInterfaceButtons.at(iButton)->draw(button_wait, button_x, button_y);
	}
	
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
bool scrBase::hitMaximise(int x, int y)
{
	_isFullscreen = !_isFullscreen;
	return _isFullscreen;
}

void scrBase::hitMaximise(int x, int y, bool input)
{
	_isFullscreen = input;
}

void scrBase::setBounds(ofRectangle &bounds)
{
    _bounds = bounds;
	
	doResize();
}

void scrBase::getLiveBounds(int &x, int &y, int &w, int &h)
{
    ofRectangle liveBounds = getLiveBounds();
    
    x = liveBounds.x;
    y = liveBounds.y;
    w = liveBounds.width;
    h = liveBounds.height;
}

ofRectangle scrBase::getLiveBounds()
{
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

void scrBase::moveCursor(float x, float y)
{
	
	_ptCursorPosition.x = x;
	_ptCursorPosition.y = y;

	ofNotifyEvent(evtCursorMove, _ptCursorPosition, this);
}

//---------------------------------------------------------------------------------
void scrBase::updateInterface()
{
	_lastLocalInterfaceUpdate = ofGetElapsedTimef();
}

bool scrBase::isUserActive()
{
	return (_lastLocalInterfaceUpdate + GUI_INTERFACE_DISPLAY_TIME) > ofGetElapsedTimef();
}
