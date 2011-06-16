/*
 *  wdgBase.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgBase.h"

wdgBase::wdgBase(string _caption) :
height(_height), y(_y)
{
	caption = _caption;
	_height = 30;
}

void wdgBase::setBounds(int x, int y, int width)
{
	_x = x;
	_y = y;
	
	_width = width;
}

bool wdgBase::isHit(int x, int y)
{
	return (x>=_x && y>=_y &&
			x<=_x+_width && y<=_y+_height);
}

void wdgBase::setHeight(int newHeight)
{
	_height = newHeight;
}