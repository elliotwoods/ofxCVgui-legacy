/*
 *  wdgSlider.h
 *  ofxCVgui
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgBase.h"
#include <math.h>

class wdgSlider : public wdgBase
{
public:
	wdgSlider(string caption,
			  float &myValue,
			  float min, float max,
			  float stepSize=1,
			  string units="");

	wdgSlider(string caption,
			  ofVec2f &myValue,
			  float min, float max,
			  float stepSize=1,
			  string units="");
	
	wdgSlider(string caption,
			  ofVec3f &myValue,
			  float min, float max,
			  float stepSize=1,
			  string units="");
	
	void		draw();
	void		mousePressed(float x, float y, int button);
	void		mouseDragged(float x, float y, float dx, float dy, int button);
	void		mouseMoved(float x, float y);
	
protected:
    void        mouseDown(float x, float y);
	
	
	float		*_value;
	int const	_nValues;
	
	float		_min, _max;
	float		_stepSize;
	
	string		_units;
	
	int			_iSelected;

	//vc++ doesn't have this(?!!)..
	int			round(float x) { return floor(x+0.5); }
};
