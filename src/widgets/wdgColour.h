//
//  wdgColour.h
//  similarColours
//
//  Created by Elliot Woods on 16/06/2011.
//  Copyright 2011 Kimchi and Chips. All rights reserved.
//

#include "wdgBase.h"

class wdgColour : public wdgBase
{
    public:
    
    //toggle constructor
	wdgColour(string caption,
			  ofColor &colour);
	
	
	void		draw();
    
    protected:
    
    ofColor     &_colour;
};
