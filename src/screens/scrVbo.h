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
	scrVbo(string caption, vector<ofVec3f> &xyz, vector<ofColor> &color);
	~scrVbo();
	
	void			setDynamicPositions(bool b);
	void			setDynamicColors(bool b);
	void			updateStatic();
	
	int				pointSize;
	
protected:
	virtual void	drawContent();
	unsigned int	getNPoints();
	
	ofEasyCam		camera;
	
    vector<ofVec3f> const	&_xyz;
	vector<ofColor> const	&_color;
	
	
	ofVbo			_vbo;
	
	bool			dynamicPositions;
	bool			dynamicColors;
	
};