//
//  scrDraw3D.cpp
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrDraw3D.h"

scrDraw3D::scrDraw3D(string caption, ofNode& node) :
_node(node),
scrBase(caption)
{
	ofAddListener(ofEvents.keyPressed, this, &scrDraw3D::keyPressed);
}

void scrDraw3D::drawContent()
{
	ofRectangle viewport = getLiveBounds();
	
	camera.begin(viewport);
	glEnable(GL_DEPTH_TEST);
	_node.draw();

	ofNotifyEvent(evtDraw3D, _node);
	glDisable(GL_DEPTH_TEST);
	
	camera.end();
}