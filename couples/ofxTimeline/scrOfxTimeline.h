//
//  scrOfxTimeline.h
//  timelineExample
//
//  Created by Elliot Woods on 17/10/2011.
//  Copyright 2011 Kimchi and Chips.
//
//	Distrubuted under the MIT license
//	http://www.opensource.org/licenses/mit-license.php

#pragma once

#include "scrViewport.h"
#include "ofxTimeline.h"

class scrOfxTimeline : public scrViewport {
public:
	scrOfxTimeline(string caption, ofxTimeline &timeline);
	
	void	mousePressed(float x, float y, int button);
	void	mouseMoved(float x, float y);
	void	mouseReleased(float x, float y, int button);
	void	mouseDragged(float x, float y, float dx, float dy, int button);
	
	void	keyPressed(int key);
	
	void	doResize();
	
protected:
	void	drawInsideViewport();
	
	ofxTimeline *t;
};