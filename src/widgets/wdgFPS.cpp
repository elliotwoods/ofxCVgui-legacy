//
//  wdgFPS.cpp
//  similarColours
//
//  Created by Elliot Woods on 18/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "wdgFPS.h"

wdgFPS::wdgFPS() :
wdgBase("FPS")
{
    _height = 15;
}

void wdgFPS::draw()
{

    float fps = ofGetFrameRate();
    
	string numDisplay = ofToString(fps, 0);
	
	ofPushStyle();
	ofSetColor(255, 255, 255);
	
	ofDrawBitmapString("FPS:", _x, _y+10);
	ofDrawBitmapString(numDisplay, _x+_width - numDisplay.length()*8, _y+10);
	
	ofPopStyle();
}
