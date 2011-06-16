/*
 *  scrGroupBase.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 27/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupBase.h"

#define FOREACH_SCREEN for (int iScreen=0; iScreen<screens.size(); iScreen++)

//////////////////////////////////////////////////////

scrGroupBase::scrGroupBase(string caption) :
scrBase(cursor_none, true, caption)
{
	iScreenMaximised = -1;
	_hasInterface = false;
}

//////////////////////////////////////////////////////

void scrGroupBase::push(scrBase *addScreen)
{
	screens.push_back(addScreen);
}

//////////////////////////////////////////////////////

void scrGroupBase::mouseMoved(int x, int y)
{
	int iScreen = findScreen(x,y);
	
	if (iScreen==-1)
		return;

	screens[iScreen]->mouseMoved(x,y);
}

void scrGroupBase::mouseDown(int x, int y)
{
	int iScreen = findScreen(x,y);
	
	if (iScreen==-1)
		return;
	
	screens[iScreen]->mouseDown(x,y);	
	
	scrBase::mouseDown(x, y);
}

void scrGroupBase::mouseReleased(int x, int y)
{
	FOREACH_SCREEN
		if (screens[iScreen]->hasCursorAttached)
			screens[iScreen]->mouseReleased(x,y);	
	
	scrBase::mouseReleased(x, y);
}

void scrGroupBase::mouseDragged(int x, int y, int dx, int dy, int button)
{
	FOREACH_SCREEN
		if (button==0)
		{
			if (screens[iScreen]->hasCursorAttached)
				screens[iScreen]->mouseDragged(x,y,dx,dy,0);
		} else
			screens[iScreen]->mouseDragged(x,y,dx,dy,1);
}

//////////////////////////////////////////////////////

bool scrGroupBase::hitMaximise(int x, int y)
{
	//this function:
	//will maximise / unmaximise one of its children if anything is hit
	//returns whether one of it's members is maximised

	if (_isFullscreen)
	{
		//one of the children are already maximised
		//should be iScreenMaximised

		screens[iScreenMaximised]->hitMaximise(x, y, false);
		iScreenMaximised=-1;
		_isFullscreen=false;
		return false;
	} else {
		//no children are maximised

		//find screen to maximise
		int iScreen = findScreen(x, y);

		//if we cant find a screen, let's leave it
		if (iScreen==-1)
			return false;

		screens[iScreen]->hitMaximise(x, y, true);
		iScreenMaximised=iScreen;
		_isFullscreen=true;
		return true;
	}
}

void scrGroupBase::hitMaximise(int x, int y, bool isMaximised)
{
	if (_isFullscreen==isMaximised)
	{
		ofLog(OF_LOG_WARNING, "scrGroupBase: already in that maximised state which is " + string(_isFullscreen ? "true" : "false"));
		return;
	} else {
		hitMaximise(x,y);
	}
}