//
//  scrVbo.cpp
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 25/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrVbo.h"

scrVbo::scrVbo(vector<ofVec3f> &xyz, vector<ofColor> &color, string caption) : 
_xyz(&xyz),
_color(&color),
dynamicPositions(true),
dynamicColors(true),
scrBase(caption),
pointSize(1)
{
	camera.setDistance(20);
	
	unsigned int nPoints = getNPoints();
	
	if (nPoints==0)
		return;
	
	_vbo.setVertexData(&_xyz->at(0), nPoints, GL_DYNAMIC_DRAW);
	_vbo.setColorData(&_color->at(0), nPoints, GL_STATIC_DRAW);
}

scrVbo::scrVbo(vector<ofVec3f> &xyz, string caption) : 
_xyz(&xyz),
_color(0),
dynamicPositions(true),
dynamicColors(false),
scrBase(caption),
pointSize(1)
{
	camera.setDistance(20);
	
	unsigned int nPoints = getNPoints();
	
	_color = new vector<ofColor>(nPoints);
	
	for (int i=0; i<nPoints; i++)
		(*_color)[i] = ofColor(255,255,255);
	
	if (nPoints==0)
		return;
	
	_vbo.setVertexData(&_xyz->at(0), nPoints, GL_DYNAMIC_DRAW);
	_vbo.setColorData(&_color->at(0), nPoints, GL_STATIC_DRAW);
}

void scrVbo::setDynamicPositions(const bool b)
{
	const unsigned int nPoints = getNPoints();
	
	if (b == dynamicPositions)
		return;
		
	dynamicPositions = b;
}

void scrVbo::setDynamicColors(const bool b)
{
	if (_color == 0)
	{
		ofLogError() << "scrVbo::setDynamicColors : no colors assigned for this Vbo";
		return;
	}
	
	const unsigned int nPoints = getNPoints();
	
	if (b == dynamicColors)
		return;	
	
	dynamicColors = b;
}

void scrVbo::update()
{
	const unsigned int nPoints = getNPoints();
	
	if (nPoints==0)
		return;
	
	/*
	 if (dynamicPositions)
	 _vbo.setVertexData(&_xyz->at(0), nPoints, GL_DYNAMIC_DRAW);
	 else
	 _vbo.setVertexData(&_xyz->at(0), nPoints, GL_STATIC_DRAW);
	 
	 
	 if (_color != 0)
	 if (dynamicColors)
	 _vbo.setColorData(&_color->at(0), nPoints, GL_DYNAMIC_DRAW);
	 else
	 _vbo.setColorData(&_color->at(0), nPoints, GL_STATIC_DRAW);
	 */
	
	_vbo.setVertexData(&_xyz->at(0), nPoints, GL_DYNAMIC_DRAW);
	_vbo.setColorData(&_color->at(0), nPoints, GL_STATIC_DRAW);	
}

void scrVbo::drawContent()
{
	const unsigned int nPoints = getNPoints();
	
	if (nPoints==0)
		return;
	
	camera.begin(getLiveBounds());
	
	glPointSize(pointSize);
	_vbo.draw(GL_POINTS, 0, nPoints);
	
	ofDrawAxis(10);
	
	camera.end();
}

unsigned int scrVbo::getNPoints()
{
	const unsigned int nPoints = _xyz->size();
	
	if (_color != 0)
		if (nPoints != _color->size())
		{
			ofLogWarning() << "scrVbo::updateStatic : size mismatch between position and color vectors. We may as well exit now to avoid bad access errors.";
			
			std::exit(1);
		}
	
	return nPoints;
}