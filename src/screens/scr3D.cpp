//
//  scr3D.cpp
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "scr3D.h"

scr3D::scr3D(ofNode& node, string caption) :
_node(node),
scrBase(caption)
{
	
}

void scr3D::drawContent()
{
	camera.begin(getLiveBounds());
	
	_node.draw();
	
	camera.end();
}