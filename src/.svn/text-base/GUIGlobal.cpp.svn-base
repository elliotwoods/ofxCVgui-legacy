/*
 *  GUIGlobal.cpp
 *  pixel correlation
 *
 *  Created by Elliot Woods on 04/07/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "GUIGlobal.h"
#include "GUIConstants.h"

bool GUIGlobal::g_isInterfaceEnabled = true;
bool GUIGlobal::g_isUserActive = true;

float GUIGlobal::_lastUserAction = ofGetElapsedTimef();


void GUIGlobal::g_userAction()
{
	_lastUserAction = ofGetElapsedTimef();
}

bool GUIGlobal::g_updateIsUserActive()
{
	g_isUserActive = (_lastUserAction + GUI_INTERFACE_DISPLAY_TIME) > ofGetElapsedTimef();
	return g_isUserActive;
}

void GUIGlobal::g_enableUserInterface()
{
	if (!g_isInterfaceEnabled)
		ofShowCursor();
	g_isInterfaceEnabled=true;
}

void GUIGlobal::g_disableUserInterface()
{
	if (g_isInterfaceEnabled)
		ofHideCursor();
	g_isInterfaceEnabled=false;
}