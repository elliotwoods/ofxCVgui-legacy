/*
 *  GUIAssets.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 04/07/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "GUIAssets.h"

ofImage *GUIAssets::_assetButtonSwitch = new ofImage();
ofImage *GUIAssets::_assetButtonSwitch_over = new ofImage();
//ofTrueTypeFont *GUIAssets::_typer = new ofTrueTypeFont();


int GUIAssets::_colSwatch1[5] = { 0xF0044F, 0x08E39F, 0x0904FA, 0xE8FA65, 0xE8FA65};

void GUIAssets::assetLoad()
{	
	_assetButtonSwitch->loadImage("assets/button-switch.png");
	_assetButtonSwitch_over->loadImage("assets/button-switch_over.png");
	
//	_typer->loadFont("assets/Lucida Console.ttf", GUI_FONT_SIZE);
}

void GUIAssets::assetUnload()
{
//	delete _typer;
}