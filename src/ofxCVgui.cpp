/*
 *  ofxCVGUI.cpp
 *  ofxCVgui
 *
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofxCVgui.h"

ofxCVgui::ofxCVgui() {
    isInitialised = false;
	_drawOnEvent = false;
}

void ofxCVgui::init(scrBase& mainScreen) {
    isInitialised = true;
	isMaximised = false;

    _bounds.x = 0;
    _bounds.y = 0;
    _bounds.width = ofGetWidth();
    _bounds.height = ofGetHeight();
	
	setMainScreen(mainScreen);
	
	assetLoad();
    
    ofAddListener(ofEvents.update, this, &ofxCVgui::update);
    ofAddListener(ofEvents.draw, this, &ofxCVgui::draw);
    ofAddListener(ofEvents.mouseMoved, this, &ofxCVgui::mouseMoved);
    ofAddListener(ofEvents.mousePressed, this, &ofxCVgui::mousePressed);
    ofAddListener(ofEvents.mouseReleased, this, &ofxCVgui::mouseReleased);
    ofAddListener(ofEvents.mouseDragged, this, &ofxCVgui::mouseDragged);

    ofAddListener(ofEvents.keyPressed, this, &ofxCVgui::keyPressed);
    
    ofAddListener(ofEvents.windowResized, this, &ofxCVgui::windowResized);
    
}

bool ofxCVgui::doFullscreen() {
	if (mainScreen->hitMaximise(_mousex, _mousey))
    {
        ofSetFullscreen(true);
        return true;
    } else {
        ofSetFullscreen(false);
        return false;
    }
}

void ofxCVgui::update(ofEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::update : not yet initialised");
        return;
    }
    
	g_updateIsUserActive();
	
	if (!mainScreen->isFullscreen || g_isUserActive)
		ofShowCursor();
	else
		ofHideCursor();
}

void ofxCVgui::draw()
{
	if (_drawOnEvent)
		ofLogError() << "ofxCVgui :: draw(). We're drawing on events, please don't try and draw manually. it'll happen automatically. Else use setDrawOnEvent(false) . ";
	else
		_draw();
}
void ofxCVgui::draw(ofEventArgs & args)
{
    draw();
}

void ofxCVgui::_draw()
{
	if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::draw : not yet initialised");
        return;
    }
    
	mainScreen->draw();

}

void ofxCVgui::setMainScreen(scrBase& s) {
	mainScreen = &s;
}

//------------------------------------------------------------------------------------------------
void ofxCVgui::mouseMoved(ofMouseEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::moseMoved : not yet initialised");
        return;
    }
    
	if (mainScreen->isHit(args.x, args.y))
		mainScreen->mouseMoved(args.x, args.y);
	
	updateMouse(args.x, args.y);
}

void ofxCVgui::mousePressed(ofMouseEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::mousePressed : not yet initialised");
        return;
    }
    
	if (mainScreen->isHit(args.x, args.y))
		mainScreen->mousePressed(args.x, args.y, args.button);
	
	updateMouse(args.x, args.y);
}

void ofxCVgui::mouseReleased(ofMouseEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::mouseReleased : not yet initialised");
        return;
    }
    
	if (mainScreen->getIsMouseAttached())
		mainScreen->mouseReleased(args.x, args.y, args.button);
	
	updateMouse(args.x, args.y);
}

void ofxCVgui::mouseDragged(ofMouseEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::mouseDragged : not yet initialised");
        return;
    }
    
	int dx = _mousex - args.x;
	int dy = _mousey - args.y;
	
	if (args.button==0)
	{
		if (mainScreen->getIsMouseAttached())
			mainScreen->mouseDragged(args.x, args.y, dx, dy, 0);
	} else {
		mainScreen->mouseDragged(args.x, args.y, dx, dy, 1);
	}

	updateMouse(args.x, args.y);
}

void ofxCVgui::updateMouse(float x, float y)
{
	interfaceNudge();
    
	_mousex = x;
	_mousey = y;
}

void ofxCVgui::setBounds(ofRectangle &bounds)
{
    _bounds = bounds;
    mainScreen->setBounds(_bounds);
}

void ofxCVgui::setDrawOnEvent(bool b)
{
	if (b == _drawOnEvent)
		return;
	
	if (b)
		ofAddListener(ofEvents.draw, this, &ofxCVgui::draw);
	
	if (!b)
		ofRemoveListener(ofEvents.draw, this, &ofxCVgui::draw);
	
	_drawOnEvent = b;
}

void ofxCVgui::setResizeOnEvent(bool b)
{
	if (b == _drawOnEvent)
		return;
	
	if (b)
		ofAddListener(ofEvents.windowResized, this, &ofxCVgui::windowResized);
	
	if (!b)
		ofRemoveListener(ofEvents.windowResized, this, &ofxCVgui::windowResized);
	
	_drawOnEvent = b;
}


//------------------------------------------------------------------------------------------------

void ofxCVgui::keyPressed(ofKeyEventArgs & args)
{
    if (args.key == 'f')
        doFullscreen();
	
	mainScreen->keyPressed(args.key);
}

void ofxCVgui::windowResized(ofResizeEventArgs & args)
{
    ofRectangle newBounds = _bounds;
    newBounds.width = args.width;
    newBounds.height = args.height;
    
    setBounds(newBounds);
}
