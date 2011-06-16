/*
 *  scrBase.cpp
 *  screen base class
 *	designed as part of pixel correlation project
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofxKCScreensGUI.h"

scrBase::scrBase(enumShowCursor showCursor, bool showMarkers, string _caption) :
isFullscreen(_isFullscreen)
{
	
	_showCursor = showCursor;
	_showMarkers = showMarkers;
	
	_btnMaximise = new btnBase(button_toggle, *_assetButtonPlus, *_assetButtonPlus_over);
	_vecInterfaceButtons.push_back(_btnMaximise);
//	ofAddListener(_btnMaximise->buttonHit, this, &scrBase::hitMaximise);
	_isFullscreen = false;
	
	hasCursorAttached = false;
	
	caption = _caption;
	
	_hasInterface = true;

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
	return (x>=_x && y>=_y &&
			x<=_x+_width && y <=_y+_height);
}

bool scrBase::transformMouse(float mouseX, float mouseY, float &screenX, float &screenY)
// transforms the mouse into screen coords
// returns 'true' if mouse is inside this screen
{
	screenX = (mouseX - float(_x)) / _width;
	screenY = (mouseY - float(_y)) / _height;
	
	if (screenX >= 0 && screenX <= 1)
		if (screenY >= 0 && screenY <= 1)
			return true;
	
	return false;
}

void scrBase::draw()
{
	drawContent();
	
	if (_hasInterface && g_isInterfaceEnabled)
		drawInterface();
}

void scrBase::drawInterface()
{
	int x, y, width, height;
	getLiveBounds(x, y, width, height);
	
	int x2, y2;
	x2 = x+width; y2 = y+height;
	
	//
	// MARKERS
	//
	
	if (_showMarkers)
	{
		drawMarkers(x,y,width,height);
	}
	
	
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
	
	
	if (_showCursor > cursor_none)
	{
		ofPushStyle();
		ofSetColor(255, 255, 255);		
		ofSetLineWidth(2);
		
		float fCursorX, fCursorY;
		fCursorX = width*_ptCursorPosition.x + x;
		fCursorY = height*_ptCursorPosition.y + y;


		
		if (_showCursor==cursor_x ||  _showCursor==cursor_xy)
			ofLine(fCursorX, y, fCursorX, y+height);
			
		if (_showCursor==cursor_y ||  _showCursor==cursor_xy)
			ofLine(x, fCursorY, x+width, fCursorY);

		ofPopStyle();
	}	
	
	//
	//CAPTION
	//
	
	ofPushStyle();
	ofSetColor(255,255,255);
	ofSetLineWidth(0);
	ofFill();
	ofRectangle boundBox = _typer->getStringBoundingBox(caption, x, y+GUI_FONT_SIZE);
	ofRect(boundBox.x, boundBox.y, boundBox.width, boundBox.height);
	ofPopStyle();
	
	ofPushStyle();
	ofSetColor(0, 0, 0);
	_typer->drawString(caption, x, y+GUI_FONT_SIZE);
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

void scrBase::setBounds(int x, int y, int w, int h)
{
	_x = x;
	_y = y;
	_width = w;
	_height = h;
	
	doResize();
}

void scrBase::getLiveBounds(int &x, int &y, int &w, int &h)
{
	if (_isFullscreen)
	{
		x = 0;
		y = 0;
		w = ofGetWidth();
		h = ofGetHeight();
	} else {
		x = _x;
		y = _y;
		w = _width;
		h = _height;
	}
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
