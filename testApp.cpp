#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofBackground(0, 0, 0);

	int width = ofGetWidth();
	int height = ofGetHeight();
	int arcRad = Arc::rad;
	int arcDiam = 2 * (arcRad - Arc::overlap);

	int xArcs = floor(width / arcDiam);
	int yArcs = floor(height / arcDiam);
	numArcs = xArcs * yArcs;

	arcList.assign(numArcs, Arc());

	int posInLine;
	ofVec3f arcPos;

	int xProx;
	int yProx;

	for (int i = 0; i < numArcs; ++i) {
		arcPos.x = (i % xArcs) * arcDiam + (arcRad * (i % 2));
		arcPos.y = floor(i / xArcs) * arcDiam + (arcRad * (i % 2));

		xProx = abs(arcPos.x - (width / 2));
		yProx = abs(arcPos.y - (height / 2));

		arcList[i].rot = (xProx + yProx) * (PI * 1 / 9);

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
	ofClear(0, 0, 0);
	ofSetHexColor(Arc::color);
	ofSetPolyMode(OF_POLY_WINDING_ODD);

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