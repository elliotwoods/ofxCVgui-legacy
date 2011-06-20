/*
 *  wdgSlider.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgSlider.h"

wdgSlider::wdgSlider(string caption,
							  float &myValue,
							  float min, float max,
							  float stepSize,
							  string units,
							  bool readOnly) :
wdgBase(caption),
_value(myValue)
{
	_min = min;
	_max = max;
	_stepSize = stepSize;
	_units = units;
	_hasNewValue = false;
	_readOnly = readOnly;
}

void wdgSlider::draw()
{
	float valRounded = round((_value-_min)/_stepSize) * _stepSize + _min;
	int nDecimals = max(0,int(-log((float)_stepSize)/log((float)10)));
	string measurement = ofToString(valRounded, nDecimals);
	measurement += " " + _units;
	
	ofPushStyle();
	ofDrawBitmapString(caption + ":", _x, _y+10);
	ofDrawBitmapString(measurement, _x+_width - measurement.length()*8, _y+10);
	
	ofNoFill();
	if (!_readOnly)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(100, 100, 100);
	ofSetLineWidth(2);
	ofRect(_x,_y+15,_width,10);
	
	ofFill();
	ofRect(_x,_y+15,
				ofMap(_value, _min, _max, 0, _width, true),
				10);
	ofPopStyle();
}

void wdgSlider::mousePressed(int x, int y, int button)
{
    mouseDown(x, y);
    wdgBase::mousePressed(x, y, button);
}

void wdgSlider::mouseDragged(int x, int y, int dx, int dy, int button)
{
    mouseDown(x, y);
}

void wdgSlider::mouseDown(int x, int y)
{
	if (_readOnly)
		return;
	
	_value = ofMap(x, _x, _x+_width, _min, _max, false);
	_value = round((_value-_min)/_stepSize) * _stepSize + _min;
	
    if (_value < _min)
        _value = _min;
    if (_value > _max)
        _value = _max;
    
	_hasNewValue = true;
}

bool wdgSlider::isValueNew()
{
	bool temp = _hasNewValue;
	_hasNewValue = false;
	
	return temp;
}