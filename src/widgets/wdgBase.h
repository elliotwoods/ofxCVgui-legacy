#pragma once
/*
 *  wdgBase.h
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"

class wdgBase
{
public:
	wdgBase(string _caption);

	virtual void	draw() = 0;
	
	virtual void	mousePressed(float x, float y, int button) ;
    virtual void	mouseDragged(float x, float y, float dx, float dy, int button) { };
    virtual void	mouseReleased(float x, float y, int button);
    virtual void	mouseMoved(float x, float y) { };
	virtual void	keyPressed(int key) { };
    
	bool			isHit(float x, float y);
    bool            getIsMouseAttached();
	
	void			setBounds(float x, float y, int width);
	void			setHeight(int newHeight);
	
	bool			isValueNew();
	
	const int		&height;
	const int		&y;
	string			caption;
	bool			enabled;
	
protected:
	int				_x, _y;
	int				_width, _height;
    
    bool            _isMouseAttached;
	
	bool			_hasNewValue;
};
