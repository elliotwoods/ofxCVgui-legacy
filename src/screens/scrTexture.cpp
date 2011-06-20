/*
 *  scrTexture.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrTexture.h"

scrTexture::scrTexture(ofTexture &texture, string _caption) :
scrBase(_caption),
_texture(texture)

{

}

void scrTexture::drawContent()
{
	int x, y, w, h;
	getLiveBounds(x, y, w, h);
	
	_texture.draw(x, y, w, h);
    
    if (!evtDraw.empty())
        drawEventContent();
}

void scrTexture::drawEventContent()
{
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