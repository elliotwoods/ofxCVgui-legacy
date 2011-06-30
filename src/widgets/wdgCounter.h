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
			  unsigned int const &myValue,
			  unsigned int myMax=0);
	
	void		draw();
	void		setMax(unsigned int const myMax);
	
protected:
	unsigned int	const	&_value;
	unsigned int			_max;	
};