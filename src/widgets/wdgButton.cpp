/*
 *  wdgButton.cpp
 *  MapTools Structured Light
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
	
	_hasDrawn = true;
	
	_hotkey = 0;
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
	
	_hasDrawn = true;
	
	_hotkey = 0;
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
	
	string toWrite;
	//perhaps this could be put in a dictionary somewhere
	if (_hotkey!=0) {
		switch (_hotkey) {
			case ' ':
				toWrite = " [SPACE]";
				break;
			case OF_KEY_LEFT:
				toWrite = " [LEFT]";
				break;
			case OF_KEY_RIGHT:
				toWrite = " [RIGHT]";
				break;
			case OF_KEY_UP:
				toWrite = " [UP]";
				break;
			case OF_KEY_DOWN:
				toWrite = " [DOWN]";
				break;
			default:
				toWrite = (string("[") + char(_hotkey)) + "]";
		}
	}
	
	toWrite = caption + toWrite;
	ofDrawBitmapString(toWrite, _x+_width/2-4*caption.length(),
					   _y+_height/2+5);
	ofPopStyle();
	
	if (_wasBang>0)
		_wasBang--;
	
	_hasDrawn = true;

}
void wdgButton::mousePressed(float x, float y, int button) {
	if (_isBang)
		_valueBang = true;
	else
		*_valueToggle = !*_valueToggle;
	
	_hasNewValue = true;
	
	_hasDrawn=false;
}

void wdgButton::keyPressed(int key) {
	if (key == _hotkey)
		mousePressed(0,0,0);
}

void wdgButton::setHotKey(const char c) {
	_hotkey = c;
}

bool wdgButton::getBang() {
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

void wdgButton::setBang() {
    if (_isBang)
        _valueBang = true;
}