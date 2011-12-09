#pragma once
/*
 *  Histogram.h
 *
 *  Created by Elliot Woods on 15/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"
#include "GUIAssets.h"

class Histogram : public GUIAssets
{
	public:
		Histogram();
		Histogram(string name, int nClasses);
		void				initialise(int nClasses);
		void				add(int iClass);
		void				clear();
		int					getSelection();
        void                setSelection(int value);

		void				update();
		void				draw(float x, float y, float width, float height);

		void				mouseDown(float x, float y);
		string				mouseHover(float xX, float xY);
		ofEvent<int>		updateSelection;

	protected:

		void				updateBar(int iPixelX, int iClass, float maxheight);

		static int			_nHistograms;

		ofTexture			_texImage;
		unsigned char*		_charImage;
		bool				_isTextureUpToDate;

		int					_colour;
		int *				_count;
		int					_nClasses;
		int					_Max;
		bool				_isInitialised;
		bool				_hasData;

		float				_selectionX;
		int					_selectionIClass;

		float				_hoverX;

		string				_name;
};
