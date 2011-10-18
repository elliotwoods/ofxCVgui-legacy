/*
 *  scrGroupTabbed.cpp
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 31/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupTabbed.h"

////////////////////////////////////////////////////////////

scrGroupTabbed::scrGroupTabbed(string caption, int _tabRegionHeight) :
scrGroupSwap(caption)
{
	tabRegionHeight = _tabRegionHeight;
}

////////////////////////////////////////////////////////////

void scrGroupTabbed::drawContent()
{	
	if (screens.size() == 0)
		return;
	
	//draw content
	screens[iSelection]->draw();
	
	//if we don't want the chrome
	//then let's stop drawing here
	if (!g_isInterfaceEnabled || screens[iSelection]->isFullscreen)
		return;
	
	//draw tabs
	bool selected;
	int textOffset = (tabRegionHeight>24 ? BORDER_OFFSET * 2 : 0);
	
	for (int i=0; i<screens.size(); i++)
	{
		selected = (i==iSelection);
		
		ofPushStyle();
		
		//draw background
		if (selected)
			ofSetColor(255, 255, 255);
		else
			ofSetColor(0, 0, 0);
		ofFill();
		ofSetLineWidth(1);
		
		ofRect(_bounds.x+i*tabWidth, _bounds.y,
			   tabWidth, tabRegionHeight);
		
		if (selected && tabRegionHeight>24)
		{
			ofSetColor(0, 0, 0);
			ofSetLineWidth(1);
			ofNoFill();
			ofRect(_bounds.x+i*tabWidth+BORDER_OFFSET, _bounds.y+BORDER_OFFSET,
				   tabWidth-BORDER_OFFSET*2, tabRegionHeight-BORDER_OFFSET*2);		
		}
		
		//draw text
		int texty = tabRegionHeight/2 + TEXT_HEIGHT/2;
		texty += _bounds.y;
		
		if (selected)
			ofSetColor(0, 0, 0);
		else
			ofSetColor(255, 255, 255);
		ofDrawBitmapString(abridgeString(screens[i]->caption,tabWidth),
						   _bounds.x+i*tabWidth+1 + textOffset,
						   texty);
		
		ofPopStyle();
	}
	
}

////////////////////////////////////////////////////////////

void scrGroupTabbed::mousePressed(float x, float y, int button)
{
	//check to see whether our mouse is
	//hitting the tab region
	//otherwise pass through to normal group
	//action
	
	if (x>_bounds.x && x<_bounds.x+_bounds.width &&
		y>_bounds.y && y<_bounds.y+tabRegionHeight)
		iSelection = (x-_bounds.x)/tabWidth;
	else
		scrGroupBase::mousePressed(x,y,button);

}

////////////////////////////////////////////////////////////

int scrGroupTabbed::findScreen(float x, float y)
{
	if (_isFullscreen)
		return iScreenMaximised;
	else if (x>_bounds.x && x<_bounds.x+_bounds.width &&
		y>_bounds.y+tabRegionHeight && y<_bounds.y+_bounds.height)
		return iSelection;
	else
		return -1;
}

void scrGroupTabbed::doResize()
{
	tabWidth = _bounds.width / screens.size();
	
    ofRectangle boundsMinusTabs = _bounds;
    
    boundsMinusTabs.y += tabRegionHeight;
    boundsMinusTabs.height -= tabRegionHeight;
    
	for (int i=0; i<screens.size(); i++)
		screens[i]->setBounds(boundsMinusTabs);
}

string scrGroupTabbed::abridgeString(string input, int width)
{
	width-=8;
	
	if (input.length()*8 < width)
		return input;
	else
		return input.substr(0,width/8-3) + "...";
}