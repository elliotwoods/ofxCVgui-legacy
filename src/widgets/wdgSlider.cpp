/*
 *  wdgSlider.cpp
 *  ofxCVgui
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgSlider.h"

//--------------------------------------------

wdgSlider::wdgSlider(string caption,
							  float &myValue,
							  float min, float max,
							  float stepSize,
							  string units) :
wdgBase(caption),
_value(&myValue),
_nValues(1) {
	_min = min;
	_max = max;
	_stepSize = stepSize;
	_units = units;
	
	_height = 15 + 10 * _nValues;
}

//--------------------------------------------

wdgSlider::wdgSlider(string caption,
					 ofVec2f &myValue,
					 float min, float max,
					 float stepSize,
					 string units) :
wdgBase(caption),
_value(&myValue.x),
_nValues(2) {
	_min = min;
	_max = max;
	_stepSize = stepSize;
	_units = units;
	
	_height = 15 + 10 * _nValues;
}

//--------------------------------------------

wdgSlider::wdgSlider(string caption,
					 ofVec3f &myValue,
					 float min, float max,
					 float stepSize,
					 string units) :
wdgBase(caption),
_value(&myValue.x),
_nValues(3) {
	_min = min;
	_max = max;
	_stepSize = stepSize;
	_units = units;
	
	_height = 15 + 10 * _nValues;
}

//--------------------------------------------

void wdgSlider::draw() {
	//find rounded value(s)
	float *valRounded = new float[_nValues];
	
	int nDecimals = max(0,int(-log((float)_stepSize)/log((float)10)));
	
	string measurement;
	for (int i=0; i<_nValues; i++)
	{
		valRounded[i] = round((_value[i]-_min)/_stepSize) * _stepSize + _min;
		
		if (i !=0)
			measurement += ", ";
		
			
		measurement += ofToString(valRounded[i], nDecimals);
	}
	
	measurement += " " + _units;
	
	ofPushStyle();
	if (enabled)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(100, 100, 100);
	
	ofDrawBitmapString(caption + ":", _x, _y+10);
	ofDrawBitmapString(measurement, _x+_width - measurement.length()*8, _y+10);
	
	//draw fill(s)
	ofPushStyle();
	ofFill();
	for (int i=0; i<_nValues; i++) {
		if (_iSelected == i && enabled)
			ofSetColor(255,255,255);
		else
			ofSetColor(100,100,100);
		ofRect(_x,_y+15 + i*10,
				ofMap(_value[i], _min, _max, 0, _width, true),
				10);
	}
	ofPopStyle();
	
	//draw outline
	ofNoFill();
	ofSetLineWidth(2);
	ofRect(_x,_y+15,_width,10 * _nValues);
	
	ofPopStyle();
	
	//delete arrays
	delete[] valRounded;
}

//--------------------------------------------

void wdgSlider::mousePressed(float x, float y, int button) {	
	
	mouseMoved(x, y);
    mouseDown(x, y);
    wdgBase::mousePressed(x, y, button);
}

//--------------------------------------------

void wdgSlider::mouseDragged(float x, float y, float dx, float dy, int button) {
    mouseDown(x, y);
}

//--------------------------------------------

void wdgSlider::mouseDown(float x, float y) {
	
	const int &i = _iSelected;
	
	_value[i] = ofMap(x, _x, _x+_width, _min, _max, false);
	_value[i] = round((_value[i]-_min)/_stepSize) * _stepSize + _min;
	
    if (_value[i] < _min)
        _value[i] = _min;
    if (_value[i] > _max)
        _value[i] = _max;
    
	_hasNewValue = true;
}

//--------------------------------------------

void wdgSlider::mouseMoved(float x, float y) {	
	_iSelected = (y - 15 - _y) / 10;
	
	if (_iSelected < 0 || _iSelected >= _nValues)
	{
		_iSelected = -1;
		return;
	}
}