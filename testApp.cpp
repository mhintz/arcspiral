#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofBackground(0, 0, 0);

	int width = ofGetWidth();
	int height = ofGetHeight();
	int arcRad = Arc::rad;
	int arcDiam = 2 * arcRad;

	numArcs = floor((width / arcDiam * height / arcDiam));

	arcList.assign(numArcs, Arc());

	int posInLine;
	ofVec3f arcPos;
	arcPos.set(0);

	for (int i = 0; i < numArcs; ++i) {
		posInLine = i * arcDiam;
		arcPos.x = (posInLine % width) + arcRad;
		arcPos.y = ceil(posInLine / width) * arcDiam + arcRad;
		if (arcPos.y == 0) ofLog(OF_LOG_NOTICE, ofToString((int) arcPos.y));
		arcList[i].move(arcPos);
	}

}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < numArcs; ++i) {
		arcList[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < numArcs; ++i) {
		arcList[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}