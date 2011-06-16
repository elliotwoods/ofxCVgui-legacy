#pragma once
/*
 *  scrTexture.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"
#include "ofEvents.h"

class scrTexture : public scrBase {

public:
	scrTexture(enumShowCursor showCursor, bool hasCursorEvents, ofTexture &texture, string _caption);
	
protected:
	void			drawContent();
	
	ofTexture		& _texture;
	
	void			* _onMouseOver(float x, float y);
	
};