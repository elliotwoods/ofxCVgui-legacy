/*
 *  ofxCVGUI.cpp
 *  Kimchi and Chips' CV GUI (aka Screens)
 *
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofxCVgui.h"

ofxCVgui::ofxCVgui()
{
    isInitialised = false;
}

void ofxCVgui::init()
{
    isInitialised = true;
	isMaximised = false;

    _bounds.x = 0;
    _bounds.y = 0;
    _bounds.width = ofGetWidth();
    _bounds.height = ofGetHeight();
	
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

bool ofxCVgui::doFullscreen()
{
	return mainScreen->hitMaximise(_mousex, _mousey);
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

void ofxCVgui::draw(ofEventArgs & args)
{
    if (!isInitialised)
    {
        ofLog(OF_LOG_ERROR, "ofxCVgui::draw : not yet initialised");
        return;
    }
    
	mainScreen->draw();
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
    
	if (mainScreen->getIsCursorAttached())
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
		if (mainScreen->getIsCursorAttached())
			mainScreen->mouseDragged(args.x, args.y, dx, dy, 0);
	} else {
		mainScreen->mouseDragged(args.x, args.y, dx, dy, 1);
	}

	updateMouse(args.x, args.y);
}

void ofxCVgui::updateMouse(int x, int y)
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
//------------------------------------------------------------------------------------------------

void ofxCVgui::keyPressed(ofKeyEventArgs & args)
{
    if (args.key == 'f')
        doFullscreen();
}

void ofxCVgui::windowResized(ofResizeEventArgs & args)
{
    ofRectangle newBounds = _bounds;
    newBounds.width = args.width;
    newBounds.height = args.height;
    
    setBounds(newBounds);
}
