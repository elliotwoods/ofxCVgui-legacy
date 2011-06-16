//
//  wdgColour.cpp
//  similarColours
//
//  Created by Elliot Woods on 16/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "wdgColour.h"

wdgColour::wdgColour(string caption, ofColor &colour) : 
wdgBase(caption),
_colour(colour)
{
    
}

void wdgColour::draw()
{
    ofPushStyle();
    
    ofSetColor(_colour);
    ofFill();
    ofRect(_x, _y+13, _width, _height - 16);    
    
    ofSetColor(255,255,255);
    ofNoFill();
    ofDrawBitmapString(caption + ":", _x, _y+10);
    ofRect(_x, _y+13, _width, _height - 16);    
    
    ofPopStyle();
}