/*
 *  scrHistograms.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrHistograms.h"

scrHistograms::scrHistograms(enumShowCursor showCursor, bool hasCursorEvents, string _caption)
: scrBase(showCursor, hasCursorEvents, _caption)
{
}

void scrHistograms::drawContent()
{
	int x, y, w, h;
	getLiveBounds(x, y, w, h);
	
	int nHistograms = _vecHistograms.size();
	if (nHistograms>0)
	{
		int histogramHeight = h/nHistograms;
		
		for (int iHistogram = 0; iHistogram < nHistograms; iHistogram++)
		{
			_vecHistograms.at(iHistogram)->draw(x, y + (histogramHeight*iHistogram), w, histogramHeight);
		}
	}
	
}

void scrHistograms::addHistogram(Histogram &histogram)
{
	_vecHistograms.push_back(&histogram);
}

void scrHistograms::mouseDown(int x, int y)
{
	scrBase::mouseDown(x, y);
	
	float xX, xY;
	transformMouse(x, y, xX, xY);
	
	int nHistograms = _vecHistograms.size();

	if (nHistograms>0)
	{
		int iHistogram = xY * float(nHistograms);
        
		xY = xY*float(nHistograms);
		xY -= floor(xY);
		
		_vecHistograms.at(iHistogram)->mouseDown(xX,xY);
		
	}
}