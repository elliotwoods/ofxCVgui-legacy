#pragma once
/*
 *  ofxCVGUI.h
 *  Kimchi and Chips' CV GUI (aka Screens)
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

#include "scrHistograms.h"
#include "scrWidgets.h"
#include "scrFileSelect.h"
#include "scrPointCloud.h"
#include "scrVbo.h" //might remove this.
#include "scrDraw3D.h"
#include "scrDraw2D.h"
#include "scrViewport.h"

#include "scrGroupGrid.h"
#include "scrGroupTabbed.h"

#include "wdgSlider.h"
#include "wdgCounter.h"
#include "wdgButton.h"
#include "wdgXYZ.h"
#include "wdgColour.h"
#include "wdgHistogram.h"
#include "wdgFPS.h"
#include "wdgTransform.h"

#include "ofMain.h"
#include "ofEvents.h"

class ofxCVgui : public GUIGlobal, public GUIAssets
{
public:
    ofxCVgui();
    
    void                    init(scrBase& mainScreen);
	
	bool					doFullscreen();
	
	void					draw();
	void					update(ofEventArgs & args);
	void					draw(ofEventArgs & args);
	
    void                    mouseMoved(ofMouseEventArgs & args);
	void					mousePressed(ofMouseEventArgs & args);
	void					mouseReleased(ofMouseEventArgs & args);
	void					mouseDragged(ofMouseEventArgs & args);
	void					updateMouse(int x, int y);
	
    void                    keyPressed(ofKeyEventArgs & args);
    
    void                    windowResized(ofResizeEventArgs & args);
	void					showInterface(bool value) { if (value) g_enableUserInterface(); else g_disableUserInterface(); }
	void					interfaceNudge() {g_userAction(); }
    
    void                    setBounds(ofRectangle &bounds);
	
	void					setDrawOnEvent(bool b);
	void					setResizeOnEvent(bool b);
	
	void					setMainScreen(scrBase& s);

	
private:
	void					_draw();
    ofRectangle             _bounds;
    
	scrBase*				mainScreen;
	
	bool					isMaximised;
    bool                    isInitialised;
    
	int						_mousex, _mousey;
	
	bool					_drawOnEvent;
	bool					_resizeOnEvent;
};