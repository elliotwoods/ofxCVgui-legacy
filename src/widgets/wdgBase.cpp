/*
 *  wdgBase.cpp
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgBase.h"

wdgBase::wdgBase(string _caption) :
height(_height), y(_y),
_isMouseAttached(false)
{
	caption = _caption;
	_height = 30;
	_hasNewValue = false;
	enabled = true;
}

void wdgBase::setBounds(float x, float y, int width)
{
	_x = x;
	_y = y;
	
	_width = width;
}

void wdgBase::mousePressed(float x, float y, int button)
{
    _isMouseAttached = true;
}

void wdgBase::mouseReleased(float x, float y, int button)
{
    _isMouseAttached = false;
}

bool wdgBase::isHit(float x, float y)
{
	return (x>=_x && y>=_y &&
			x<=_x+_width && y<=_y+_height);
}

bool wdgBase::getIsMouseAttached()
{
    return _isMouseAttached;
}

void wdgBase::setHeight(int newHeight)
{
	_height = newHeight;
}

bool wdgBase::isValueNew()
{
	bool temp = _hasNewValue;
	_hasNewValue = false;
	
	return temp;
}