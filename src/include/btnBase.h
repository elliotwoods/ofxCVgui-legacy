/*
 *  btnBase.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 14/02/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */
#include "ofMain.h"
#include "GUIconstants.h"
#include "ofEvents.h"

class btnBase
{
public:
	btnBase(enumGUIButtonType type, ofImage &imgWait, ofImage &imgOver);
	
	void	mouseReleased();
	
	void	draw(enumGUIButtonState state, float x, float y);
	
	ofEvent<int> buttonHit;
	
private:
	ofImage		*_imgWait, *_imgOver, *_imgDown;
	enumGUIButtonType	_type; // bang, toggle, etc
	int			intNull;
};