#pragma once
//
//  scrViewport.h
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 27/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrBase.h"
#include "ofEvents.h"

class scrViewport : public scrBase {
	
public:
	scrViewport(string _caption = "");
	
    ofEvent<ofRectangle>    evtDrawInsideViewport;
    
protected:
	void			drawContent();
	
	virtual void	drawInsideViewport() { };
	
};