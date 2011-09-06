//
//  wdgXYZ.cpp
//  MapTools Structured Light
//
//  Created by Elliot Woods on 06/05/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "wdgXYZ.h"

wdgXYZ::wdgXYZ(string caption,
               float *myValuesXYZ,
               float min, float max,
               float stepSize,
               string units,
               bool readOnly) :
wdgBase(caption)
{
    _value = myValuesXYZ;
	_min = min;
	_max = max;
	_stepSize = stepSize;
	_units = units;
	_hasNewValue = false;
	_readOnly = readOnly;
}

void wdgXYZ::draw()
{
    string measurements[3];
	int nDecimals = max(0,int(-log((float)_stepSize)/log((float)10)));

    ofPushStyle();
    ofNoFill();
    
    //caption
    ofDrawBitmapString(caption + ":", _x, _y+10);
    
    
    //each control is 75px width
    //boxes are 10px width
    //buffer is 5px either side
    for (int i=0; i<3; i++)
    {
        measurements[i] = ofToString(_value[i],nDecimals);
        measurements[i] += _units;
        
        ofDrawBitmapString(measurements[i], _x - 5 + 75 - 10 - 5 + 75*i - measurements[i].length()*8, _y+30);
        
        // -
        ofRect(_x + 4 + 75*i, _y+20, 10, 10);
        ofDrawBitmapString("-", _x + 1 + 5 + 75*i, _y+30);
        
        // +
        ofRect(_x + 75 - 10 - 5 + 75*i, _y+20, 10, 10);
        ofDrawBitmapString("+", _x + 1 + 75 - 10 - 5 + 75*i, _y+30);
        
    }
	ofPopStyle();
}

void wdgXYZ::mousePressed(int x, int y, int button)
{
	if (_readOnly)
		return;
    
    x -=3;
    
    int iDimension = x / 75;
    int xInDimension = x % 75;
    
    if (iDimension > 2)
        return;
    
    if (xInDimension < 37)
        _value[iDimension] -= _stepSize;
    else
        _value[iDimension] += _stepSize;
    
	_hasNewValue = true;
}

bool wdgXYZ::isValueNew()
{
	bool temp = _hasNewValue;
	_hasNewValue = false;
	
	return temp;
}