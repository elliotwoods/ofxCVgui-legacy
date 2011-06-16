/*
 *  scrTexture.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrTexture.h"

scrTexture::scrTexture(ofTexture &texture, string _caption) :
scrBase(_caption),
_texture(texture)

{

}

void scrTexture::drawContent()
{
	int x, y, w, h;
	getLiveBounds(x, y, w, h);
	
	_texture.draw(x, y, w, h);
}
