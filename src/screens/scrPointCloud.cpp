/*
 *  scrPointCloud.cpp
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 04/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrPointCloud.h"

scrPointCloud::scrPointCloud(string caption) :
scrBase(caption),
_isSet(false)
{
	_nPoints = 0;
	pointSize = 2;
	glGenBuffersARB(1, &vbo[0]);
	glGenBuffersARB(1, &vbo[1]);
//	ofAddListener(ofEvents.keyPressed, this, &scrPointCloud::keyPressed);

	camera.setPosition(0,0,1);
	useLocal = false;
}

scrPointCloud::~scrPointCloud()
{
//	ofRemoveListener(ofEvents.keyPressed, this, &scrPointCloud::keyPressed);
}

void scrPointCloud::drawContent()
{
    if (!_isSet)
        return;

	begin();
    drawPoints();
	end();
}

void scrPointCloud::begin() {
	camera.begin(getLiveBounds());
	ofPushMatrix();
	ofRotate(180,0,1,0);
	
}

void scrPointCloud::end() {
	ofPopMatrix();
	camera.end();

	ofRectangle bounds = getLiveBounds();
	ofDrawBitmapString(ofToString(_nPoints), bounds.x + 10, bounds.y + 30);
}

void scrPointCloud::drawPoints()
{
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo[0]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, _nPoints * 3 * sizeof(float), _positions, GL_STATIC_DRAW_ARB);
	glVertexPointer(3, GL_FLOAT, 0, 0);
    
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo[1]);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, _nPoints * 3 * sizeof(float), _colours, GL_STATIC_DRAW_ARB);
	glColorPointer(3, GL_FLOAT, 0, 0);
	
	glDrawArrays(GL_POINTS, 0, _nPoints);
	
	glDisableClientState(GL_VERTEX_ARRAY); 
	glDisableClientState(GL_COLOR_ARRAY);
	
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
}

void scrPointCloud::clear()
{
    _isSet = false;
}

void scrPointCloud::setWith(float *positions, float *colours, int nPoints)
{
	_positions = positions;
	_colours = colours;
	_nPoints = nPoints;
    
    _isSet = true;
}

void scrPointCloud::setWith(double *positions, int nPoints) {
	if (useLocal)
	{
		delete[] localPositions;
	}
	if (nPoints > 0)
	{
		localPositions = new float[nPoints*3];
		useLocal = true;
	}

	for (int i=0; i<nPoints; i++)
	{
		for (int j=0; j<3; j++)
			localPositions[i*3+j] = positions[i*3+j];
	}

	
	setWith(localPositions, localPositions, nPoints);

}

void scrPointCloud::keyPressed(int key)
{
	cout << "" << key << endl;
}