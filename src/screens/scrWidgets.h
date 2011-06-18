#pragma once
/*
 *  scrWidgets.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"
#include "wdgBase.h"

#define WIDGET_PADDING 10
class scrWidgets : public scrBase
{
public:
	scrWidgets(string _caption);
	
	void				mousePressed(int x, int y, int button);
    void                mouseReleased(int x, int y, int button);
    void                mouseDragged(int x, int y, int dx, int dy, int button);
    void                mouseMoved(int x, int y);
	
	void				push(wdgBase *widget);

	void				doResize();
	
protected:
	void				drawContent();
	
	vector<wdgBase*>	_widgets;	
	int					_sumHeights;
};