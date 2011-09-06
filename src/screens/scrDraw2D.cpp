//
//  scrDraw2D.cpp
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrDraw2D.h"

scrDraw2D::scrDraw2D(string caption, ofBaseDraws& d) :
_draw(d),
scrBase(caption)
{
	
}

void scrDraw2D::drawContent()
{
	_draw.draw(getLiveBounds());
}