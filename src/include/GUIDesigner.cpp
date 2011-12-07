//
//  GUIDesigner.cpp
//  ofxCVgui
//
//  Created by Elliot Woods on 06/12/2011.
//  Copyright (c) 2011 Kimchi and Chips. All rights reserved.
//

#include "GUIDesigner.h"

//------------------
GUIDesigner::GUIDesigner() {
	root = 0;
}

//------------------
void GUIDesigner::push(string caption, ofBaseDraws& asset) {
	if (!checkRoot())
		return;
	
	push(new scrDraw2D(caption, asset));
}

//------------------
void GUIDesigner::setRootGroup(scrGroupBase *root) {
	this->root = root;
}

//------------------
bool GUIDesigner::checkRoot() const {
	if (root==0) {
		ofLogError() << "Cannot use GUIDesigner, no default root group is set";
		return false;
	}
	return true;
}

//------------------
void GUIDesigner::push(scrBase* screen) {
	screens.insert(pair<string, scrBase*>(screen->caption, screen));
	root->push(screen);
}
