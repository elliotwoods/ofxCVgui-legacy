#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	////
	//setup some stuff
	////
	//
	ofBackground(100, 100, 100);
	ofEnableSmoothing();
	
	video.initGrabber(WIDTH, HEIGHT);
	inverted.allocate(WIDTH, HEIGHT, OF_IMAGE_COLOR);
	//
	////
	
	////
	//setup the gui
	////
	//
	gui.init();
	gui.push("Video", video);
	gui.push("Inverted", inverted);
	//gui.push("Histogram", histogram);
	//
	////
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();
	
	if (video.isFrameNew()) {
		unsigned char * in = video.getPixels();
		unsigned char * out = inverted.getPixels();
		for (int i=0; i<WIDTH*HEIGHT*3; i++) {
			*out++ = 255 - *in++;
		}
		inverted.update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

