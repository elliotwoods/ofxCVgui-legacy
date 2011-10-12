#ofxCvGUI
*OpenFrameworks extension designed for CV tasks*

Copyright Kimchi and Chips 2011 http://www.kimchiandchips.com

MIT License

##Overview
Yet another GUI library. This time it's specfically designed for CV tasks.

Commonly GUI's in openFrameworks are things that you put on top of your main display. In ofxCVGUI, there is no 'main display', i.e. it's not designed on the paradigm of a 'runtime' and 'tweak time' which many other GUI's are focused on.

Currently ofxCvGUI is also being designed in mind to cooperate with ofxCv.

##To Do

* Easier to setup, because currently:
	* requires main screen to attach on init
	* complains if assets aren't available
	* move setLock from scrDraw3d to base
* Remove old histogram concept (replace with new one).
