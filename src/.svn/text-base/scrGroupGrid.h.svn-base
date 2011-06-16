/*
 *  scrGroupGrid.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 29/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupBase.h"

class scrGroupGrid : public scrGroupBase
{
public:
	scrGroupGrid(string caption="");
	void		drawContent();
	
	int			findScreen(int x, int y);
	
	void		setGridWidth(int gridWidth);
	void		setGridHeight(int gridHeight);
	
protected:
	void		doResize();
	int			_gridWidth, _gridHeight;
    int         constraint; // 0=square, 1=width, 2=height
};
