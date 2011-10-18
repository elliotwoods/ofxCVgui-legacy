#pragma once
/*
 *  wdgButton.h
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 03/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgBase.h"
#include "ofEvents.h"

#define BANG_FRAMES 2

class wdgButton : public wdgBase
{
public:	
	//toggle constructor
	wdgButton(string caption,
			  bool &myValue,
			  int inHeight = 30);
	
	//bang constructor
	wdgButton(string caption,
			  int inHeight = 30);
	
	void		draw();
	void		mousePressed(float x, float y, int button);
	void		keyPressed(int key);
	
	void		setHotKey(const char c);
	bool		getBang();
    void        setBang();
	
protected:
	bool		_isBang;
	bool		*_valueToggle;
	bool		_valueBang;
	
	int			_wasBang;
	bool		_hasDrawn;	//this is so we draw the mousedown state
							//before the result of the bang
	
	int			_hotkey; //stored as int to stop 'overflow in implicit const constant conversion'
	
};
