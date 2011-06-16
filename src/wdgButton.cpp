/*
 *  wdgButton.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 03/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgButton.h"

wdgButton::wdgButton(string caption,
					 bool &myValue,
					 int inHeight) :
wdgBase(caption)
{
	_height = inHeight;
	
	//toggle constructor
	_isBang = false;
	_valueToggle = &myValue;
	
	_wasBang = 0;
	
	enabled = true;
	_hasDrawn = true;
}

wdgButton::wdgButton(string caption,
					 int inHeight) :
wdgBase(caption)
{
	_height = inHeight;
	
	//bang constructor
	_isBang = true;
	_valueBang = false;

	_wasBang = 0;
	
	enabled = true;
	_hasDrawn = true;
}

void wdgButton::draw()
{
	bool currentValue;
	
	currentValue = (_isBang ? _valueBang : *_valueToggle);
	currentValue |= _wasBang > 0;
	
	ofPushStyle();
	ofSetLineWidth(1);
	ofFill();
	
	if (currentValue)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(0, 0, 0);
	ofRect(_x, _y, _width, _height);
	
	//draw outline if not current value
	if (!currentValue)
	{
		ofPushStyle();
		ofSetLineWidth(1);
		ofNoFill();
		
		if (enabled)
			ofSetColor(255, 255, 255);
		else
			ofSetColor(100, 100, 100);
		
		ofRect(_x, _y, _width, _height);
		ofPopStyle();
	}
	
	if (currentValue)
		ofSetColor(0, 0, 0);
	else
		ofSetColor(255, 255, 255);
	
	if (!enabled)
		ofSetColor(100, 100, 100);
	
	ofDrawBitmapString(caption, _x+_width/2-4*caption.length(),
					   _y+_height/2+5);
	ofPopStyle();
	
	if (_wasBang>0)
		_wasBang--;
	
	_hasDrawn = true;

}
void wdgButton::mouseDown(int x, int y)
{
	if (enabled)
		if (_isBang)
			_valueBang = true;
		else
			*_valueToggle = !*_valueToggle;
	
	_hasDrawn=false;
}

bool wdgButton::getBang()
{
	if (_isBang && _hasDrawn)
	{
		if (_valueBang)
		{
			_valueBang=false;
			_wasBang=2;
			return true;
		} else
			return false;

	} else {
		return false;
	}
		
}