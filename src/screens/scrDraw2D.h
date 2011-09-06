//
//  scrDraw2D.h
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "ofMain.h"

#include "scrBase.h"

class scrDraw2D : public scrBase {
	
public:
	scrDraw2D(string caption, ofBaseDraws& d);
	
	float			pointSize;
	
	ofEasyCam		&getCamera() { return camera; }
protected:
	virtual void	drawContent();
	
	ofEasyCam		camera;
	ofBaseDraws&	_draw;
};