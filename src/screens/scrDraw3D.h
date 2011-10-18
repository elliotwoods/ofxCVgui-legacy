//
//  scrDraw3D.h
//  PosRotSca-test
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "ofMain.h"

#include "scrBase.h"

class scrDraw3D : public scrBase {
	
public:
	scrDraw3D(string caption, ofNode& node);
	
	void			keyPressed(ofKeyEventArgs & args);
	ofNode&			getNodeReference();
	
	float			pointSize;
	ofEvent<ofNode>	evtDraw3D; ///< differs from standard event, in that it is triggered after the transforms have been applied
	
	
protected:
	virtual void	drawContent();
	
	
	ofEasyCam		camera;
	ofNode&			_node;
};