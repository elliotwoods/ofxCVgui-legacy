//
//  scrVbo.cpp
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 25/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrVbo.h"

scrVbo::scrVbo(string caption, vector<ofVec3f> &xyz, vector<ofColor> &color) : 
_xyz(xyz),
_color(color),
dynamicPositions(true),
dynamicColors(true),
scrBase(caption)
{
	
}

void scrVbo::setDynamicPositions(const bool b)
{
	const unsigned int nPoints = getNPoints();
	
	if (b == dynamicPositions)
		return;
	
	if (b)
		_vbo.setVertexData(&_xyz[0], nPoints, GL_DYNAMIC_DRAW);
	else
		_vbo.setVertexData(&_xyz[0], nPoints, GL_STATIC_DRAW);
	
	dynamicPositions = b;
}

void scrVbo::setDynamicColors(const bool b)
{
	const unsigned int nPoints = getNPoints();
	
	if (b == dynamicColors)
		return;
	
	if (b)
		_vbo.setColorData(&_color[0], nPoints, GL_DYNAMIC_DRAW);
	else
		_vbo.setColorData(&_color[0], nPoints, GL_STATIC_DRAW);
	
	
	dynamicColors = b;
}

void scrVbo::updateStatic()
{
	const unsigned int nPoints = getNPoints();
	
	if (!dynamicPositions)
		_vbo.setVertexData(&_xyz[0], nPoints, GL_STATIC_DRAW);
	
	if (!dynamicColors)
		_vbo.setColorData(&_color[0], nPoints, GL_STATIC_DRAW);
	
}

void scrVbo::drawContent()
{
	const unsigned int nPoints = getNPoints();
	
	if (dynamicPositions)
		
	camera.begin(getLiveBounds());
	
	_vbo.draw(GL_POINTS, 0, nPoints);
	
	camera.end();
}

unsigned int scrVbo::getNPoints()
{
	const unsigned int nPoints = _xyz.size();
	
	if (nPoints != _color.size())
	{
		ofLogWarning() << "scrVbo::updateStatic : size mismatch between position and color vectors. We may as well exit now to avoid bad access errors.";
		
		std::exit(1);
	}
	
	return nPoints;
}