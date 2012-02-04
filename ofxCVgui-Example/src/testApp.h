#pragma once

#include "ofMain.h"

#include "ofxCVgui.h"

#define WIDTH 640
#define HEIGHT 480
class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);

	ofVideoGrabber	video;
	ofImage			inverted;
	ofMesh			histogram;
	
	ofxCVgui		gui;
};
