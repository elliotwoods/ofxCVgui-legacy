#pragma once
//
//  scrDrawEvent.h
//  calibrate-cam,proj,depth
//
//  Created by Elliot Woods on 27/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "scrBase.h"
#include "ofEvents.h"

class scrDrawEvent : public scrBase {
	
public:
	scrDrawEvent(string _caption = "");
	
    ofEvent<ofRectangle>    evtDraw;
    
protected:
	void			drawContent();
	
};