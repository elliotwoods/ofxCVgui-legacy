#pragma once
/*
 *  scrGroupBase.h
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 27/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"

class scrGroupBase : public scrBase
{
public:
	scrGroupBase(string caption = "");
	
	void				push(scrBase *addScreen);
	void				push(scrBase &addScreen);
	
	virtual int			findScreen(float x, float y) { return -1; };
	
	void				mouseMoved(float x, float y);
	virtual void		mousePressed(float x, float y, int button);
	void				mouseReleased(float x, float y, int button);
	void				mouseDragged(float x, float y, float dx, float dy, int button);
	void				keyPressed(int key);
	
	bool				hitMaximise(float x, float y);
	void				hitMaximise(float x, float y, bool isMaximised);
	vector<scrBase*>	screens;
	
	scrBase&			operator[](const int i);
	
protected:
	virtual void		drawContent() = 0;

	void				doResize() = 0;
	
	int					iScreenMaximised;
};