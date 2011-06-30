//
//  scr3D.h
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofMain.h"

#include "scrBase.h"

class scr3D : public scrBase {
	
public:
	scr3D(ofNode& node, string caption);
	
	float			pointSize;
	
	ofEasyCam		&getCamera() { return camera; }
protected:
	virtual void	drawContent();
	
	ofEasyCam		camera;
	ofNode&			_node;
};