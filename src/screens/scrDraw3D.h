//
//  scrDraw3D.h
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "ofMain.h"

#include "scrBase.h"
#include "ofxGrabCam.h"

class scrDraw3D : public scrBase {
	
public:
	scrDraw3D(string caption, ofNode& node);
	
	void			keyPressed(ofKeyEventArgs & args);
	ofNode&			getNodeReference();
	
	void			enableGrid(float size = 10.0f);
	
	float			pointSize;
	ofEvent<ofNode>	evtDraw3D; ///< differs from standard event, in that it is triggered after the transforms have been applied
	
	
protected:
	virtual void	drawContent();
	
	float			gridSize;
	ofxGrabCam		camera;
	ofNode&			_node;
};