//
//  scrViewport.cpp
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 27/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrViewport.h"


scrViewport::scrViewport(string _caption) :
scrBase(_caption)
{
	
}

void scrViewport::drawContent()
{
    if (evtDraw.empty())
        return;

    ofRectangle liveBounds = getLiveBounds();
    
    //save old view
    ofPushView();
    
    //move to new viewport
    ofViewport(liveBounds);
    
    //clear transforms
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	
    //apply screenspace transform
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //
    GLfloat orthoMatrix[16] = {
		2/liveBounds.width,     0,                      0,  0,
		0,                      -2/liveBounds.height,   0,  0,
		0,                      0,                      1,  0,
		-1,                     1,                      0,  1
    };
    glMultMatrixf(orthoMatrix);
	
    //draw event   
    ofNotifyEvent(evtDraw, liveBounds, this);
    
    //get out of view
    ofPopView();
}