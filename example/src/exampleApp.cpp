#include "exampleApp.h"

//--------------------------------------------------------------
void exampleApp::setup(){
	ofSetWindowTitle("exampleApp");
	ofBackground(0,0,0);
	ofSetFrameRate(60);

	ofSetLogLevel(OF_LOG_NOTICE);
	//load the css file
	css.load("sample.css");

	//get a css block
	css.get("rect1");
}

//--------------------------------------------------------------
void exampleApp::update(){
}

//--------------------------------------------------------------
void exampleApp::draw(){
	ofxCssBlock block = css.get("rect1");
	ofSetColor(block.backgroundColor);
}

//--------------------------------------------------------------
void exampleApp::keyPressed(int key){

}

//--------------------------------------------------------------
void exampleApp::keyReleased(int key){

}

//--------------------------------------------------------------
void exampleApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void exampleApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void exampleApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void exampleApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void exampleApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void exampleApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void exampleApp::dragEvent(ofDragInfo dragInfo){ 

}
