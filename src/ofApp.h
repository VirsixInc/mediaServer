#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxTextSuite.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    void setText(string toSet);

    ofxOscReceiver osc;

    ofVideoPlayer player;
    string movieSrc, textBgSrc, bgSrc;

    string currText;

    ofRectangle bgRect;
    ofImage textBackground, passiveBackground;

    ofxTextBlock txtBox;


};
