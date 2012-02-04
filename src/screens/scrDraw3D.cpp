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
	camera.setPosition(0,0,1.0f);
	camera.setNearClip(0.01f);
	gridSize = 0.0f;
}

void scrDraw3D::drawContent()
{
	ofRectangle viewport = getLiveBounds();
	
	camera.begin(viewport);
	ofRotate(180, 0, 1, 0);

	glEnable(GL_DEPTH_TEST);
	if (gridSize > 0)
		ofDrawGrid(gridSize);
	_node.draw();

	_node.transformGL();
	ofNotifyEvent(evtDraw3D, _node);
	_node.restoreTransformGL();
	
	glDisable(GL_DEPTH_TEST);
	
	camera.end();
}

void scrDraw3D::keyPressed(ofKeyEventArgs &args) {
	switch(args.key) {
		case OF_KEY_RIGHT:
			_node.truck(0.1f);
			break;
			
		case OF_KEY_LEFT:
			_node.truck(-0.1f);
			break;
			
		case OF_KEY_UP:
			_node.dolly(0.1f);
			break;
			
		case OF_KEY_DOWN:
			_node.dolly(-0.1f);
			break;
	}
}

ofNode& scrDraw3D::getNodeReference() {
	return _node;
}

void scrDraw3D::enableGrid(float size) {
	gridSize = size;
}