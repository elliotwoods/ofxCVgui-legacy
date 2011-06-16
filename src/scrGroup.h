/*
 *  scrGroup.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 27/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"

class scrGroup : public scrBase
{
public:
	scrGroup();
	
	int					findScreen(int x, int y);
	
	void				mouseMoved(int x, int y);
	void				mouseDown(int x, int y);
	void				mouseReleased(int x, int y);
	
	bool				hitMaximise(int x, int y);
	
	int					gridWidth;
	
	vector<scrBase*>	screens;
	
	
private:
	void				drawContent();

	void				doResize();
	
	int					gridHeight;
	int					iScreenMaximised;

};