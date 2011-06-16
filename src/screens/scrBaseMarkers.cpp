/*
 *  scrBaseMarkers.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 20/03/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBaseMarkers.h"

scrBaseMarkers::scrBaseMarkers()
{
	_hasMarkers=false;
}

void scrBaseMarkers::setMarkers(std::vector<ofPoint> *x)
{
	_markers=x;
	_nMarkers=x->size();
	_hasMarkers=true;
}

void scrBaseMarkers::clearMarkers()
{
	_hasMarkers=false;
}

void scrBaseMarkers::drawMarkers(float x, float y, float width, float height)
{
	float xMarker, yMarker;
	
	if (_hasMarkers)
	{
		ofPushStyle();
		ofNoFill();
		ofSetColor(0,0,255);
		
		glBegin(GL_POINTS);
		for (int iMarker=0; iMarker < _nMarkers; iMarker++)
		{
			xMarker = (*_markers)[iMarker].x * width + x;
			yMarker = (*_markers)[iMarker].y * height + y;
			
			glVertex2f(xMarker, yMarker);
		}
		glEnd();
		
		ofPopStyle();
	}
}
