/*
 *  scrFileSelect.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 04/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrWidgets.h"
#include "wdgButton.h"

class scrFileSelect : public scrWidgets, public ofDirectory
{
public:
	scrFileSelect(string caption, string path, string extension);
	
	void				drawContent();
	
	void				refresh();
	void				selectAll();
	void				selectNone();	
    
    string              getSelectedPath();

	vector<char>		selected;
	const int			&nFiles;
	
protected:		
	string				_path;
	int					_nFiles;
	
	wdgButton			*bangSelectAll, *bangSelectNone, *bangRefresh;
};