//
//  scrOfxTimeline.cpp
//  timelineExample
//
//  Created by Elliot Woods on 17/10/2011.
//  Copyright 2011 Kimchi and Chips.
//
//	Distrubuted under the MIT license
//	http://www.opensource.org/licenses/mit-license.php

#include "scrOfxTimeline.h"

scrOfxTimeline::scrOfxTimeline(string caption, ofxTimeline &timeline) :
scrViewport(caption) {
	t = &timeline;
}

void scrOfxTimeline::mousePressed(float x, float y, int button) {
	ofMouseEventArgs m;
	ofRectangle b = this->getLiveBounds();
	m.x = x;
	m.y = y;
	m.x -= b.x;
	m.y -= b.y;
	m.button = button;
	
	scrBase::mousePressed(x, y, button);
	
	if (b.inside(x,y))
		t->mousePressed(m);
}

void scrOfxTimeline::mouseMoved(float x, float y) {
	ofMouseEventArgs m;
	ofRectangle b = this->getLiveBounds();
	m.x = x;
	m.y = y;
	m.x -= b.x;
	m.y -= b.y;
	
	scrBase::mouseMoved(x, y);
	
	if (b.inside(x,y))
		t->mouseMoved(m);
}

void scrOfxTimeline::mouseReleased(float x, float y, int button) {
	ofMouseEventArgs m;
	ofRectangle b = this->getLiveBounds();
	m.x = x;
	m.y = y;
	m.x -= b.x;
	m.y -= b.y;
	m.button = button;
	
	scrBase::mouseReleased(x, y, button);
	if (b.inside(x,y))
		t->mouseReleased(m);
}

void scrOfxTimeline::mouseDragged(float x, float y, float dx, float dy, int button) {
	ofMouseEventArgs m;
	ofRectangle b = this->getLiveBounds();
	m.x = x;
	m.y = y;
	m.x -= b.x;
	m.y -= b.y;
	m.button = button;
	
	scrBase::mouseDragged(x, y, dx, dy, button);
	t->mouseDragged(m);
}

void scrOfxTimeline::keyPressed(int key) { 
	ofKeyEventArgs k;
	k.key = key;
	t->keyPressed(k);
}

void scrOfxTimeline::doResize() {
	ofResizeEventArgs w;
	ofRectangle b = this->getLiveBounds();
	
	w.width = b.width;
	w.height = b.height;
	
	t->setWidth(w.width);
	t->windowResized(w);
}

void scrOfxTimeline::drawInsideViewport() {
	//just incase we do this every frame
	//internally it should instantly reject the call
	//if we're not using events.
	t->disableEvents();
	t->draw();
}