#pragma once
/*
 *  GUIGlobal.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 04/07/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"

class GUIGlobal
{
public:
	static void				g_userAction();
	static bool				g_updateIsUserActive();
	
	static void				g_enableUserInterface();
	static void				g_disableUserInterface();
	
	static bool				g_isUserActive;
	static bool				g_isInterfaceEnabled;
	
private:
	static float			_lastUserAction;
};