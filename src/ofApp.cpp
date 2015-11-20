#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  osc.setup(9999);

  movieSrc = "movies/test.mp4";
  bgSrc = "images/passiveBg.png";
  passiveBackground.load(bgSrc);
  bgRect = ofRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight()/5);
  bgRect.y = ofGetWindowHeight()-bgRect.height;
  player.loadMovie(movieSrc);
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
  }else{
    passiveBackground.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
  }
}

void ofApp::setText(string toSet){
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
