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
	scrGroup(string caption = "");
	
	int					findScreen(int x, int y);
	
	void				mousePressed(int x, int y, int button);
	void				mouseMoved(int x, int y);
	void				mouseReleased(int x, int y, int button);
    void                mouseDragged(int x, int y, int dx, int dy, int button);
	
	bool				hitMaximise(int x, int y);
	
	int					gridWidth;
	
	vector<scrBase*>	screens;
	
	
private:
	void				drawContent();

	void				doResize();
	
	int					gridHeight;
	int					iScreenMaximised;

};