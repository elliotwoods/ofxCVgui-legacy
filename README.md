#ofxCvGUI
*OpenFrameworks extension designed for CV tasks*

Copyright Kimchi and Chips 2011 http://www.kimchiandchips.com

MIT License

##Overview
Yet another GUI library. This time it's specfically designed for CV tasks.

Commonly GUI's in openFrameworks are things that you put on top of your main display. In ofxCVGUI, there is no 'main display', i.e. it's not designed on the paradigm of a 'runtime' and 'tweak time' which many other GUI's are focused on.

Currently ofxCvGUI is also being designed in mind to cooperate with ofxCv.

Also ofxCvGUI works in a little more OO way than other GUI's (which are generally procedurally defined). This has the dis-advantage that you sometimes have to write more code to define your GUI.

##To Do

* Easier to setup:
	* requires main screen to attach on init
	* complains if assets aren't available (do we need assets? can we replace all with ofDrawBitmapString?)
* Remove old histogram concept (replace with new one).
