/*
 *  wdgSlider.h
 *  MapTools Structured Light
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
			  string units="",
			  bool readOnly=false);

	wdgSlider(string caption,
			  ofVec2f &myValue,
			  float min, float max,
			  float stepSize=1,
			  string units="",
			  bool readOnly=false);
	
	wdgSlider(string caption,
			  ofVec3f &myValue,
			  float min, float max,
			  float stepSize=1,
			  string units="",
			  bool readOnly=false);
	
	void		draw();
	void		mousePressed(int x, int y, int button);
	void		mouseDragged(int x, int y, int dx, int dy, int button);    
	
	bool		isValueNew();
	
protected:
    void        mouseDown(int x, int y);
	
	
	float		*_value;
	int const	_nValues;
	bool		_hasNewValue;
	
	bool		_readOnly;
	
	float		_min, _max;
	float		_stepSize;
	
	string		_units;
	
	int			_iSelected;

	//vc++ doesn't have this(?!!)..phhff
	int			round(float x) { return floor(x+0.5); }
};
