/*
 *  Histogram.cpp
 *
 *  Created by Elliot Woods on 15/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "Histogram.h"

int Histogram::_nHistograms=0;

Histogram::Histogram(string name, int nClasses)
{
	_isInitialised=false;
	_name = name;
	_colour = _colSwatch1[_nHistograms++ % 5];
	
	_selectionIClass = 0;
	_isTextureUpToDate = false;
	
	initialise(nClasses);
}

void Histogram::initialise(int nClasses)
{
	if (_isInitialised)
	{
		delete[] _count;
		delete[] _charImage;
	}

	_isInitialised=true;
	
	_nClasses = nClasses;
	_count = new int[nClasses];
	
	_charImage = new unsigned char[GUI_HISTOGRAM_TEXTURE_RESOLUTION*GUI_HISTOGRAM_TEXTURE_RESOLUTION*3];
	_texImage.allocate(GUI_HISTOGRAM_TEXTURE_RESOLUTION, GUI_HISTOGRAM_TEXTURE_RESOLUTION, GL_RGB);
	_texImage.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	
}

void Histogram::add(int iClass)
{
	if (iClass>0 && iClass<_nClasses)
	{
		_count[iClass]=_count[iClass]+1;
		
		if (_count[iClass]>_Max)
			_Max = _count[iClass];
		
		_hasData=true;
	}
	
	_isTextureUpToDate=false;
}

void Histogram::clear()
{
	_hasData=false;

	for (int iClass = 0; iClass<_nClasses; iClass++)
		_count[iClass]=0;
	
	_Max = 0;	
	_isTextureUpToDate=false;
}

int Histogram::getSelection()
{
	return _selectionIClass;
}

void Histogram::setSelection(int value)
{
    _selectionIClass = value;
    ofNotifyEvent(updateSelection, _selectionIClass, this);
}

void Histogram::update()
{
	//clear all colour values to background colour
	for (int iPixel = 0; iPixel<GUI_HISTOGRAM_TEXTURE_RESOLUTION*GUI_HISTOGRAM_TEXTURE_RESOLUTION; iPixel++)
	{
		
		_charImage[iPixel*3]	=	(_colour >> 16) & 255;
		_charImage[iPixel*3+1]	=	(_colour >> 8) & 255;
		_charImage[iPixel*3+2]	=	(_colour) & 255;
		
	}
	
	int iPixelX;
	float maxheight = log(float(_Max));
	
		
	int iClass;
	
	for (iPixelX = 0; iPixelX < GUI_HISTOGRAM_TEXTURE_RESOLUTION; iPixelX++)
	{
		iClass = iPixelX*_nClasses/GUI_HISTOGRAM_TEXTURE_RESOLUTION;

		updateBar(iPixelX, iClass, maxheight);
	}
	
	_texImage.loadData(_charImage, GUI_HISTOGRAM_TEXTURE_RESOLUTION, GUI_HISTOGRAM_TEXTURE_RESOLUTION, GL_RGB);

	_isTextureUpToDate=true;
}
		
void Histogram::updateBar(int iPixelX, int iClass, float maxheight)
{
	
	float targetHeight = log(float(_count[iClass]))/maxheight;

	float thisPixelHeight;
	int iPixel;
	
	for (int iPixelY=0; iPixelY<GUI_HISTOGRAM_TEXTURE_RESOLUTION; iPixelY++)
	{
		
		thisPixelHeight = 1-float(iPixelY)/float(GUI_HISTOGRAM_TEXTURE_RESOLUTION);
		
		if (thisPixelHeight < targetHeight)
		{
			iPixel = iPixelY * GUI_HISTOGRAM_TEXTURE_RESOLUTION + iPixelX;
			_charImage[iPixel*3]=255;
			_charImage[iPixel*3+1]=255;
			_charImage[iPixel*3+2]=255;
		}
		
	}
}

void Histogram::draw(float x, float y, float width, float height)
{
	if (!_isTextureUpToDate)
		update();
	
	if (_hasData)
	{
		//
		// TEXTURE
		//
		
		_texImage.draw(x, y, width, height);
		
		//
		// TEXT
		//
		ofPushStyle();
		ofSetColor(0);
		ofDrawBitmapString(_name, x, y+height-3);
		ofPopStyle();
		
		//
		// LINES
		//		
		//selection line
		ofPushStyle();
		ofSetColor(0, 0, 0);		
		ofSetLineWidth(2);
		int linex= x + (width*_selectionX);
		ofLine(linex, y, linex, y+height);
		
		//hover line
		ofSetLineWidth(1);
		linex = x + (width*_hoverX);
		ofLine(linex, y, linex, y+height);
		
		ofPopStyle();
		
		// END LINES
		
		
	}
	
}

void Histogram::mouseDown(float x, float y)
{
	if (x>=0 && x<=1)
	{
		_selectionX = x;
		setSelection(x*_nClasses);
	}
}

string Histogram::mouseHover(float xX, float xY)
{
	char strStatus[100];
	
	if (xX>=0 || xX<=1)
	{
		_hoverX = xX;
		int hoverIClass = _nClasses*xX;
		int hoverAmp = _count[hoverIClass];
		
		sprintf(strStatus, "selected: iClass=%d;    hover: iClass=%d, count=%d", _selectionIClass, hoverIClass, hoverAmp);
		
		return strStatus;
	} else {
		return "";
	}
}
