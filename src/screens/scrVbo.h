#pragma once
//
//  scrVbo.h
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 25/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "ofMain.h"

#include "scrBase.h"

class scrVbo : public scrBase {
	
public:
	scrVbo(vector<ofVec3f> &xyz, vector<ofColor> &color, string caption);
	scrVbo(vector<ofVec3f> &xyz, string caption);	
	~scrVbo() { };
	
	void			update();
	
	void			setDynamicPositions(bool b);
	void			setDynamicColors(bool b);
	
	float			pointSize;
	
	ofEasyCam		&getCamera() { return camera; }
protected:
	virtual void	drawContent();
	unsigned int	getNPoints();
	
	ofEasyCam		camera;
	
    vector<ofVec3f>	*_xyz;
	vector<ofColor>	*_color;
	
	
	ofVbo			_vbo;
	
	bool			dynamicPositions;
	bool			dynamicColors;
	
};