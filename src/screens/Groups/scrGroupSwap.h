/*
 *  scrGroupSwap.h
 *  MapTools Structured Light
 *
 *  Created by Elliot Woods on 29/10/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrGroupBase.h"

class scrGroupSwap : public scrGroupBase
{
public:
	scrGroupSwap(string caption) : scrGroupBase(caption)
    { iSelection = 0; };
	int			iSelection;
};
