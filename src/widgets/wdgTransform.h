//
//  wdgTransform.h
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 26/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "wdgBase.h"

class wdgTransform : public wdgBase
{
	public:
	wdgTransform(ofMatrix4x4 &matrix, ofCamera &camera, string caption = "Transform");
	
	void		draw();
	void		mousePressed(float x, float y, int button);
	void		mouseDragged(float x, float y, float dx, float dy, int button);    
	
	ofMatrix4x4	&_matrix;
};