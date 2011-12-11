#pragma once
/*
 *  ofxCVGUI.h
 *  Kimchi and Chips' CV GUI (aka Screens)
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */
#include "include/GUIGlobal.h"
#include "include/GUIConstants.h"
#include "include/GUIAssets.h"
#include "include/GUIDesigner.h"

#include "histograms/Histogram.h"

#include "screens/screens.h"
#include "widgets/widgets.h"

#include "ofMain.h"
#include "ofEvents.h"

class ofxCVgui : public GUIGlobal, public GUIAssets, public GUIDesigner
{
public:
    ofxCVgui();
    
	///init with a default root screen
	void					init();
	
	///init with root screen passed by user
    void                    init(scrBase& mainScreen);
	
	bool					doFullscreen();
	
	void					draw();
	void					update(ofEventArgs & args);
	void					draw(ofEventArgs & args);
	
    void                    mouseMoved(ofMouseEventArgs & args);
	void					mousePressed(ofMouseEventArgs & args);
	void					mouseReleased(ofMouseEventArgs & args);
	void					mouseDragged(ofMouseEventArgs & args);
	void					updateMouse(float x, float y);
	
    void                    keyPressed(ofKeyEventArgs & args);
    
    void                    windowResized(ofResizeEventArgs & args);
	void					showInterface(bool value) { if (value) g_enableUserInterface(); else g_disableUserInterface(); }
	void					interfaceNudge() {g_userAction(); }
    
    void                    setBounds(ofRectangle &bounds);
	
	void					setDrawOnEvent(bool b);
	void					setResizeOnEvent(bool b);
	
	void					setMainScreen(scrBase& s);
	void					setMainScreen(scrBase* s);
	
private:
	void	initBase();
	void	_draw();
	
    ofRectangle             _bounds;
    
	scrBase*				mainScreen;
	
	bool					isMaximised;
    bool                    isInitialised;
    
	float					_mousex, _mousey;
	
	bool					_drawOnEvent;
	bool					_resizeOnEvent;
};