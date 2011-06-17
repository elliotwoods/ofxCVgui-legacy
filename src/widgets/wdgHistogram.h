//
//  wdgHistogram.h
//  similarColours
//
//  Created by Elliot Woods on 16/06/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "wdgBase.h"

template<typename ChannelType>
class wdgHistogram : public wdgBase
{
    public:
        wdgHistogram(string caption, ChannelType binCount);
        ~wdgHistogram();
    
        void    update();
        void    draw();
    
        void    initialise();
        void    uninitialise();
    
        void    mousePressed(int x, int y, int button);
        void    mouseDragged(int x, int y, int button);
    
        void    clear();
        void    push(const ChannelType &channel);
    
        ChannelType getSelection() const { return *_selection; };
        void setSelection(ChannelType &channel);
        
        
    protected:
        bool    initialised;
        ChannelType     _binCount;
    
        ofImage image; //rotated 90 degrees
    
        ChannelType *_bins;
        ChannelType *_selection;
    
        ChannelType _localSelection;
    
    private:
        ofMatrix4x4 matSwapXY;
    
};
