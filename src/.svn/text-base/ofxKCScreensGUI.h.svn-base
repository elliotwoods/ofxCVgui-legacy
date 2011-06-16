#pragma once
/*
 *  ofxKCScreensGUI.h
 *  Kimchi and Chips' Screens GUI
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */
//#include "PCconstants.h"
//#include "PCAssets.h"
#include "GUIGlobal.h"
#include "GUIConstants.h"
#include "GUIAssets.h"

#include "Histogram.h"

#include "scrTexture.h"
#include "scrHistograms.h"
#include "scrWidgets.h"
#include "scrFileSelect.h"
#include "scrPointCloud.h"

#include "scrGroupGrid.h"
#include "scrGroupTabbed.h"

#include "wdgSlider.h"
#include "wdgCounter.h"
#include "wdgButton.h"
#include "wdgXYZ.h"

#include "ofMain.h"


class ofxKCScreensGUI : public GUIGlobal, public GUIAssets
{
public:
							ofxKCScreensGUI(float x, float y, float width, float height);
	
	scrBase*				mainScreen;
	
	bool					doFullscreen();
	
	void					update();
	void					draw();
	
	void					mouseMoved(int x, int y);
	void					mouseDown(int x, int y);
	void					mouseReleased(int x, int y);
	void					mouseDragged(int x, int y, int button);
	void					updateMouse(int x, int y);
	
	void					showInterface(bool value) { if (value) g_enableUserInterface(); else g_disableUserInterface(); }
	void					interfaceNudge() {g_userAction(); }

	void					resize(int x, int y);
	
private:
	float					_x, _y, _width, _height;
	bool					isMaximised;
	int						_mousex, _mousey;
};