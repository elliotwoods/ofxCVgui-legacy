//
//  wdgHistogram.cpp
//  similarColours
//
//  Created by Elliot Woods on 16/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "wdgHistogram.h"

template<typename ChannelType>
wdgHistogram<ChannelType>::wdgHistogram(string caption, ChannelType binCount) : 
wdgBase(caption),
initialised(false),
_binCount(binCount)
{
    initialise();
    
    matSwapXY.makeIdentityMatrix();
    matSwapXY(0,0) = 0;
    matSwapXY(1,0) = 1;
    matSwapXY(1,1) = 0;
    matSwapXY(0,1) = 1;
    
    _height = 70;
}

template<typename ChannelType>
wdgHistogram<ChannelType>::~wdgHistogram()
{
    uninitialise();
}
template<typename ChannelType>
void wdgHistogram<ChannelType>::update()
{
    // find max bin
    int maxCount = 1; // avoid div/0
    for (ChannelType i=0; i<_binCount; i++)
        maxCount = MAX(maxCount, _bins[i]);
    
    float maxCountF = maxCount;
    
    //clear image
    memset(image.getPixels(), 0, image.getWidth() * image.getHeight());
    
    //set white areas of image
    unsigned char* rowOfPixels = image.getPixels();
    int imWidth = image.getWidth();
    float imWidthF = imWidth;
    float barWidth;
    //
    for (ChannelType i=0; i<_binCount; i++)
    {
        barWidth = imWidthF * (float(_bins[i])/maxCountF);
        memset(rowOfPixels, 255, barWidth);
        rowOfPixels += imWidth;
    }
    
    if (*_selection < 0)
        _selection = 0;
    if (*_selection >= _binCount)
        *_selection = _binCount-1;
    
    image.update();
    
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::draw()
{
    
    ofRectangle drawBounds = ofRectangle(_x, _y+15, _width, 30);
    
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);

    //CAPTION
    ofSetColor(255,255,255);
    ofNoFill();
    ofDrawBitmapString(caption + ":", _x, _y+10);
    
    
    ////////////////
    // QUAD
    ////////////////
    //
    image.bind();
    glBindTexture (GL_TEXTURE_2D, 13);
    glBegin (GL_QUADS);

    glTexCoord2f (image.getWidth(), 0.0);
    glVertex2f (drawBounds.x, drawBounds.y);
    
    glTexCoord2f (image.getWidth(), image.getHeight());
    glVertex2f (drawBounds.x+drawBounds.width, drawBounds.y);
    
    glTexCoord2f (0.0, image.getHeight());
    glVertex2f (drawBounds.x+drawBounds.width, drawBounds.y+drawBounds.height);
    
    
    glTexCoord2f (0.0, 0.0);
    glVertex2f (drawBounds.x, drawBounds.y+drawBounds.height);
    
    glEnd();
    
    image.unbind();
    //
    ////////////////
    
    
    ////////////////
    // INDICATOR
    ////////////////
    //
    ofFill();
    float xIndicator = _x + (float(_width)*(*_selection)/float(_binCount));
    ofBeginShape();
    ofVertex(xIndicator, drawBounds.y+drawBounds.height + 2);
    ofVertex(xIndicator - 4, drawBounds.y+drawBounds.height+10);
    ofVertex(xIndicator + 4, drawBounds.y+drawBounds.height+10);
    ofEndShape();
    //
    ////////////////
    
    
    
    ofPopStyle();
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::initialise()
{
    if (initialised)
        uninitialise();
    
    image.allocate(30, _binCount, OF_IMAGE_GRAYSCALE);
    
    _bins = new ChannelType[_binCount];
    _selection = &_localSelection;
    
    initialised = true;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::uninitialise()
{
    delete[] _bins;
    
    initialised = false;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::clear()
{
    if (!initialised)
        initialise();
    
    for (ChannelType i=0; i<_binCount; i++)
        _bins[i] = 0;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::push(const ChannelType &channel)
{
    if (!initialised)
    {
        ofLogError() << "wdgHistogram::addTo(..) : not yet intiialised";
        return;
    }
    
    if (channel > _binCount || channel < 0)
    {
        ofLogError() << "wdgHistogram::Channel #" << channel << " is outside of range";
        return;
    }
    
    _bins[channel]++;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::setSelection(ChannelType &channel)
{    
    *_selection = channel;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::setSelection(ChannelType *channel)
{    
    _selection = channel;
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::mousePressed(int x, int y, int button)
{
    mouseDown(x, y);
    wdgBase::mousePressed(x,y,button);
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::mouseDragged(int x, int y, int dx, int dy, int button)
{
    mouseDown(x, y);
}

template<typename ChannelType>
void wdgHistogram<ChannelType>::mouseDown(int x, int y)
{
    float newSelection = float(x-_x)/float(_width) * float(_binCount);
    
    if (newSelection < 0)
        newSelection = 0;
    if (newSelection > _binCount-1)
        newSelection = _binCount-1;
    
    *_selection = newSelection;
    
    ofNotifyEvent(evtSelectionChange, *_selection, this);
}
template class wdgHistogram<unsigned char>;
template class wdgHistogram<unsigned int>;
template class wdgHistogram<int>;
