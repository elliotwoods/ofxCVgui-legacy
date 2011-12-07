//
//  GUIDesigner.h
//  ofxCVgui
//
//  Created by Elliot Woods on 06/12/2011.
//  Copyright (c) 2011 Kimchi and Chips. All rights reserved.
//

#include "ofMain.h"
#include "screens.h"

class GUIDesigner {
public:	
	GUIDesigner();
	void push(string caption, ofBaseDraws& asset);
	
protected:
	void setRootGroup(scrGroupBase* root);

private:
	bool checkRoot() const;
	void push(scrBase* screen);
	
	scrGroupBase* root;
	map<string, scrBase*> screens;
};