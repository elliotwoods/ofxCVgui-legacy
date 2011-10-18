#pragma once
/*
 *  scrHistograms.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"

#include "Histogram.h"

class scrHistograms : public scrBase
{
public:
	scrHistograms(string caption);
	
	void						drawContent();
	void						drawHistogram();
	
	void						addHistogram(Histogram &histogram);
	
	virtual void				mousePressed(float x, float y, int button);
private:
	std::vector<Histogram*>	_vecHistograms;
};