/*
 *  scrBaseMarkers.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 20/03/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"

class scrBaseMarkers
{
public:
	scrBaseMarkers();
	void					setMarkers(std::vector<ofPoint> *x);
	void					clearMarkers();
	
protected:
	void					drawMarkers(float x, float y, float width, float height);
	
	bool					_showMarkers;
	bool					_hasMarkers;
	
	std::vector<ofPoint>	*_markers;
	int						_nMarkers;
};
