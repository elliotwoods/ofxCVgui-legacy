#pragma once
/*
 *  GUIAssets.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 04/07/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"
#include "GUIConstants.h"

class GUIAssets
{
public:
	static void				assetLoad();
	static void				assetUnload();
	
protected:
	
	static ofImage			*_assetButtonSwitch;
	static ofImage			*_assetButtonSwitch_over;
	
	static int				_colSwatch1[5];	
	
//	static ofTrueTypeFont	*_typer;
};