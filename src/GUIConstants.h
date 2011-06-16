#pragma once
/*
 *  GUIConstants.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 04/07/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#define GUI_INTERFACE_DISPLAY_TIME 2

#define GUI_FONT_SIZE 10

enum enumGUIButtonState { button_wait, button_over, button_down };
enum enumGUIButtonType {button_bang, button_toggle};

enum enumShowCursor { cursor_none, cursor_x, cursor_y, cursor_xy };

#define GUI_INTERFACE_BUTTON_SIZE 16
#define GUI_INTERFACE_BORDER_LINE_WIDTH 2

#define GUI_HISTOGRAM_TEXTURE_RESOLUTION 512