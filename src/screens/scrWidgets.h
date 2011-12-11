#pragma once
/*
 *  scrWidgets.h
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"
#include "widgets/wdgBase.h"

#define WIDGET_PADDING 10
class scrWidgets : public scrBase
{
public:
	scrWidgets(string _caption = "Controls");
	
	void				mousePressed(float x, float y, int button);
    void                mouseReleased(float x, float y, int button);
    void                mouseDragged(float x, float y, float dx, float dy, int button);
    void                mouseMoved(float x, float y);
	void				keyPressed(int key);
	
	void				push(wdgBase *widget);
	void				push(wdgBase &widget);

	void				doResize();
	
protected:
	void				drawContent();
	
	vector<wdgBase*>	_widgets;	
	int					_sumHeights;
};