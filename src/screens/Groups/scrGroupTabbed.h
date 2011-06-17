/*
 *  scrGroupTabbed.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 31/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupSwap.h"

#define TEXT_HEIGHT 12
#define BORDER_OFFSET 2
class scrGroupTabbed : public scrGroupSwap
{
public:
	scrGroupTabbed(string caption, int _tabRegionHeight=16);
	void		drawContent();
	
	void		mousePressed(int x, int y, int button);
	
	int			findScreen(int x, int y);
	
protected:
	int			tabRegionHeight;
	int			tabWidth;
	void		doResize();

	string		abridgeString(string input, int width);
};
