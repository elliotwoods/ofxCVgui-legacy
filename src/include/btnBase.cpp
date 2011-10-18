/*
 *  btnBase.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 14/02/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "btnBase.h"

btnBase::btnBase(enumGUIButtonType type, ofImage &imgWait, ofImage &imgOver)
{
	_imgWait = &imgWait;
	_imgOver = &imgOver;
	_imgDown = &imgWait;
	_type = type;
}

void btnBase::mouseReleased()
{
	ofNotifyEvent(buttonHit, intNull, this);
}

void btnBase::draw(enumGUIButtonState state, float x, float y)
{
	
	switch (state) {
		case button_wait:
			_imgWait->draw(x, y);
			break;
		case button_over:
			_imgOver->draw(x, y);
			break;
		case button_down:
			_imgDown->draw(x, y);
			break;

		default:
			break;
	}
}

