/*
 *  scrGroupGrid.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 29/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupGrid.h"

scrGroupGrid::scrGroupGrid(string caption) :
scrGroupBase(caption)
{
	_gridWidth = 0;
    _gridHeight = 1;
    
    constraint = 0;
}
//////////////////////////////////////////////////////

void scrGroupGrid::drawContent()
{
	if (!_isFullscreen)
		for (int i=0; i<screens.size(); i++)
			screens[i]->draw();
	else
		screens[iScreenMaximised]->draw();
}

//////////////////////////////////////////////////////

int scrGroupGrid::findScreen(int x, int y)
{
	if (screens.size()==0)
		return -1;
	
	int iScreen; // return value
	
	int w = _width / _gridWidth;
	int h = _height / _gridHeight;
	
	
	if (_isFullscreen)
		iScreen=iScreenMaximised;
	
	else
	{
		int iScreenX, iScreenY;
		
		iScreenX = (x - _x) / w;
		iScreenY = (y - _y) / h;
		
		iScreen = iScreenY * _gridWidth + iScreenX;
	}
	
	if (iScreen<0 || iScreen>screens.size()-1)
		iScreen=-1;
	
	return iScreen;
	
}

void scrGroupGrid::setGridWidth(int gridWidth)
{
	_gridWidth = gridWidth;
    constraint = 1;
    
	doResize();
}

void scrGroupGrid::setGridHeight(int gridHeight)
{
	_gridHeight = gridHeight;
    constraint = 2;
    
	doResize();
}

void scrGroupGrid::doResize()
{
    int nScreens = screens.size();
    
    if (nScreens==0)
		return;
	
    
    switch (constraint) {
            
        case 0: // SQUARE
            
            _gridWidth = ceil(sqrt( float(nScreens) ));
            _gridHeight = ceil(float(nScreens) / float(_gridWidth));
            
            break;
            
        case 1: // WIDTH
            
            _gridHeight = ceil(float(nScreens) / float(_gridWidth));
            
            break;
            
        case 2: // HEIGHT
            
            _gridWidth = ceil(float(nScreens) / float(_gridHeight));
            
            break;

    }
	
	//code for arranging grid
	int ix, iy;
	float x, y, w, h;
	
	w = _width / _gridWidth;
	h = _height / _gridHeight;
	
	for (int i=0; i<nScreens; i++)
	{
		ix = i % _gridWidth;
		iy = i / _gridWidth;
		
		x = _x + ix * w;
		y = _y + iy * h;
		
		screens[i]->setBounds(x, y, w, h);
	}
}
