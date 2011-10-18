/*
 *  scrWidgets.cpp
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrWidgets.h"

#define FOREACH_WIDGET for (int iWidget=0; iWidget<_widgets.size(); iWidget++)

scrWidgets::scrWidgets(string _caption)
: scrBase(_caption) {
	_sumHeights=0;
}

void scrWidgets::mousePressed(float x, float y, int button) {
	int currentx, currenty, currentw, currenth;
	getLiveBounds(currentx, currenty, currentw, currenth);
	
	if (y<0 || _widgets.size()==0)
		return;
	
	int yOffset=y-_widgets[0]->y;
	
	FOREACH_WIDGET
	{
		if  (yOffset <= _widgets[iWidget]->height) {
			if (_widgets[iWidget]->enabled)
				_widgets[iWidget]->mousePressed(x,y,button);
			break;
		}
		
		yOffset -= _widgets[iWidget]->height + WIDGET_PADDING;
	}
    
    scrBase::mousePressed(x,y,button);
}

void scrWidgets::mouseReleased(float x, float y, int button) {
	FOREACH_WIDGET
    {
        if (_widgets[iWidget]->getIsMouseAttached()) {
			_widgets[iWidget]->mouseReleased(x,y,button);
			break;
		}
    }
    
    scrBase::mouseReleased(x,y,button);
	
}

void scrWidgets::mouseDragged(float x, float y, float dx, float dy, int button) {
	FOREACH_WIDGET
    {
        if (_widgets[iWidget]->getIsMouseAttached()) {
			_widgets[iWidget]->mouseDragged(x,y,dx,dy,button);
			break;
		}
    }
	
}

void scrWidgets::mouseMoved(float x, float y) {
	FOREACH_WIDGET
        _widgets[iWidget]->mouseMoved(x,y);
	
}

void scrWidgets::keyPressed(int key) {
	FOREACH_WIDGET
		_widgets[iWidget]->keyPressed(key);
}

void scrWidgets::push(wdgBase *widget) {
	int x, y, w, h;
	getLiveBounds(x, y, w, h);
	
	widget->setBounds(x+WIDGET_PADDING, y+_sumHeights,
					  w - 2*WIDGET_PADDING);
	
	_widgets.push_back(widget);
	
	_sumHeights += widget->height + WIDGET_PADDING;
}

void scrWidgets::push(wdgBase &w) {
	this->push(&w);
}

void scrWidgets::doResize() {
	int x, y, w, h;
	getLiveBounds(x, y, w, h);
	
	_sumHeights = WIDGET_PADDING;
	
	FOREACH_WIDGET {
		_widgets[iWidget]->setBounds(x+WIDGET_PADDING, y+_sumHeights+WIDGET_PADDING,
									 w - 2*WIDGET_PADDING);
		_sumHeights += _widgets[iWidget]->height + WIDGET_PADDING;
	}
}

void scrWidgets::drawContent() {
	FOREACH_WIDGET
		_widgets[iWidget]->draw();
}