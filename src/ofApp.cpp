#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  osc.setup(9999);

  movieSrc = "movies/test.mp4";
  textBgSrc = "images/textBg.png";
  bgSrc = "images/passiveBg.png";
  textBackground.load(textBgSrc);
  passiveBackground.load(bgSrc);
  bgRect = ofRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight()/5);
  bgRect.y = ofGetWindowHeight()-bgRect.height;
  player.loadMovie(movieSrc);

  currText = "TESTIJN  NDFNKLDSN SNKLFNDSNG";

  txtBox.init("monospace", 80);

  txtBox.setText("HERE");
}

//--------------------------------------------------------------
void ofApp::update(){
  while(osc.hasWaitingMessages()){
    ofxOscMessage m;
    osc.getNextMessage(m);
    string address = m.getAddress();
    if(address == "/playMovie"){
      player.play();
    }else if(address == "/stopMovie"){
      player.stop();
    }else if(address == "/setText"){
      string txtToSet = m.getArgAsString(0);
      setText(txtToSet);
    }
  }
  if(player.isPlaying()){
    player.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  if(player.isPlaying()){
    player.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    textBackground.draw(bgRect.x,bgRect.y,bgRect.width,bgRect.height);
    txtBox.draw(bgRect.x, bgRect.y);
  }else{
    passiveBackground.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
  }
}

void ofApp::setText(string toSet){
  currText = toSet;
  txtBox.setText(currText);
  //txtBox.wrapTextArea(ofGetWindowWidth(),ofGetWindowHeight());//bgRect.width, bgRect.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
