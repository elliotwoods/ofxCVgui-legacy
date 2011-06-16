/*
 *  wdgCounter.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 03/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgBase.h"

#define COUNTER_RADIUS 3
class wdgCounter : public wdgBase
{
public:
	wdgCounter(string caption,
			  int &myValue,
			  int myMax=-1);
	
	void		draw();
	void		setMax(int myMax);
	
protected:
	int			&_value;
	int			_max;	
};