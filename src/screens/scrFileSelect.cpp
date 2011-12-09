/*
 *  scrFileSelect.cpp
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 04/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrFileSelect.h"

scrFileSelect::scrFileSelect(string caption, string path, string extension) :
scrWidgets(caption),
nFiles(_nFiles)
{
	_path = path;
	allowExt(extension);
	
	////////////////////////////
	// CONTROLS
	////////////////////////////
    //
	bangSelectAll = new wdgButton("Select all");
	bangSelectNone = new wdgButton("Select none");
	bangRefresh = new wdgButton("Refresh");
	
	push(bangSelectAll);
	push(bangSelectNone);
	push(bangRefresh);
    //
	////////////////////////////
	
	refresh();
	
}

void scrFileSelect::drawContent()
{
	scrWidgets::drawContent();
	
	if (bangSelectAll->getBang())
		selectAll();
	
	if (bangSelectNone->getBang())
		selectNone();
	
	if (bangRefresh->getBang())
		refresh();
}

void scrFileSelect::refresh()
{
	string path = ofToDataPath(_path, true);
	_nFiles = listDir(path);
	
	for (int i=3; i<_widgets.size(); i++)
		delete _widgets[i];
	
	while (_widgets.size()>3)
		_widgets.pop_back();
	
	doResize();
	
	selected.resize(_nFiles);

	for (int i=0; i<_nFiles; i++)
	{
		selected[i]=false;
		push(new wdgButton(getName(i),
						   *(bool*)&selected[i],
							15));
	}
	
	doResize();
	
}

void scrFileSelect::selectAll()
{
	for (int i=0; i<_nFiles; i++)
		selected[i]=true;
}

void scrFileSelect::selectNone()
{
	for (int i=0; i<_nFiles; i++)
		selected[i]=false;
}

string scrFileSelect::getSelectedPath()
{
    string name = "";
    
    for (int i=0; i<_nFiles; i++)
    {
        if (selected[i])
        {
            name = getPath(i);
            break;
        }
    }
    
    return name;
}