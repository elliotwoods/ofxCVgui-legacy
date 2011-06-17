#pragma once
/*
 *  scrGroupBase.h
 *  PC Encode
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
	
	virtual int			findScreen(int x, int y) { return -1; };
	
	void				mouseMoved(int x, int y);
	virtual void		mousePressed(int x, int y, int button);
	void				mouseReleased(int x, int y, int button);
	void				mouseDragged(int x, int y, int dx, int dy, int button);
	
	bool				hitMaximise(int x, int y);
	void				hitMaximise(int x, int y, bool isMaximised);
	vector<scrBase*>	screens;
	
	
protected:
	virtual void		drawContent() = 0;

	void				doResize() = 0;
	
	int					iScreenMaximised;
};