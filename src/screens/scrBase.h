#pragma once
/*
 *  scrBase.h
 *  screen base class
 *	designed as part of pixel correlation project
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "GUIAssets.h"
#include "GUIGlobal.h"

#include "ofMain.h"
#include "ofEvents.h"

#include "Histogram.h"

#include "btnBase.h"

class scrBase : public GUIAssets, public GUIGlobal
{
public:
	scrBase(string _caption);
	~scrBase();
	
	void					draw(); // please override the private one below
	
	bool					isHit(float x, float y);
	
	virtual void			mousePressed(float x, float y, int button);
	virtual void			mouseMoved(float x, float y);
	virtual void			mouseReleased(float x, float y, int button) {_isMouseAttached=false; };
	virtual void			mouseDragged(float x, float y, float dx, float dy, int button);
	
	virtual void			keyPressed(int key) { };
	
	virtual bool			hitMaximise(float x, float y);
	virtual void			hitMaximise(float x, float y, bool input);
	const bool				&isFullscreen;
	
	void					setBounds(ofRectangle &bounds);
    ofRectangle				getLiveBounds(); //also considers fullscreen
	virtual void			doResize() { };
	
	void					updateInterface();
	bool					isUserActive();

	bool                    getIsMouseAttached() const {
        return _isMouseAttached;
    };
	
	///transform mouse coords from computer screen to local screen coordinates
    void					transformMouse(float mouseX, float mouseY, float &screenX, float &screenY);
	ofVec2f					normaliseMouse(float x, float y);
    
	void					setLock(ofMutex& m);
	
	ofEvent<ofRectangle>	evtDraw;
	ofEvent<ofVec2f>		evtMouseMoved;
	ofEvent<ofVec2f>		evtMousePressed;
	
	string					caption;
	bool					enabled;
	
protected:
	void					getLiveBounds(int &x, int &y, int &w, int &h); //also considers fullscreen
	virtual void			drawContent()=0;
	void					drawChrome();
	

	
	ofRectangle             _bounds;
	bool					_isFullscreen;
	
    bool                    _isMouseAttached;

	float					_lastLocalInterfaceUpdate;
	
	int						_mousex, _mousey;
	
	bool					_hasChrome;

	ofMutex*				_lock;

};


