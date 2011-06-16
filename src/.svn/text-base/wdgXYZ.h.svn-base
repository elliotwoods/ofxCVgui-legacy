//
//  wdgXYZ.h
//  PC Encode
//
//  Created by Elliot Woods on 06/05/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "wdgBase.h"
#include <math.h>

class wdgXYZ : public wdgBase
{
public:
	wdgXYZ(string caption,
			  float *myValuesXYZ,
			  float min, float max,
			  float stepSize,
			  string units="",
			  bool readOnly=false);
    
	void		draw();
	void		mouseDown(int x, int y);
	
	bool		isValueNew();
	
protected:
	float		*_value;
	bool		_hasNewValue;
	
	bool		_readOnly;
	
	float		_min, _max;
	float		_stepSize;
	
	string		_units;
    
	//stupid vc++ doesn't have this..phhff
	int			round(float x) { return floor(x+0.5); }
};
