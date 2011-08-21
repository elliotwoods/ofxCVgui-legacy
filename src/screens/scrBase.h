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
	
	bool					isHit(int x, int y);
	
	virtual void			mousePressed(int x, int y, int button);
	virtual void			mouseMoved(int x, int y);
	virtual void			mouseReleased(int x, int y, int button) {_isCursorAttached=false; };
	virtual void			mouseDragged(int x, int y, int dx, int dy, int button);
	
	virtual bool			hitMaximise(int x, int y);
	virtual void			hitMaximise(int x, int y, bool input);
	const bool				&isFullscreen;
	
	void					setBounds(ofRectangle &bounds);
	virtual void			doResize() { };
	
	void					getStatus(string &strStatus) { };
	
	void					moveCursor(float x, float y);
	
	void					updateInterface();
	bool					isUserActive();
    
    bool                    getIsCursorAttached() const {
        return _isCursorAttached;
    };

    bool					transformMouse(float mouseX, float mouseY, float &screenX, float &screenY);
    
	ofEvent<ofPoint>		evtCursorMove;
	ofEvent<ofPoint>		evtCursorPressed;
	
	string					caption;
	
protected:
	void					getLiveBounds(int &x, int &y, int &w, int &h); //also considers fullscreen
    ofRectangle				getLiveBounds(); //also considers fullscreen
	virtual void			drawContent()=0;
	void					drawChrome();
	

	
	ofRectangle             _bounds;
	bool					_isFullscreen;
	
	ofPoint					_ptCursorPosition;
    bool                    _isCursorAttached;
	
	string					_strStatus;

	std::vector<btnBase*>	_vecInterfaceButtons;
	//btnBase				*_btnMaximise;
	
	float					_lastLocalInterfaceUpdate;
	
	int						_mousex, _mousey;
	
	bool					_hasChrome;
    

};


