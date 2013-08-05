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
	ofVec3f center(width / 2, height / 2, 0);

	rotIncrement = PI * 1 / 1;

	ofVec3f arcPos;
	double dist;

	for (int i = 0; i < numArcs; ++i) {
		arcPos.x = (i % xArcs) * arcDiam + (arcRad * ((int) floor(i / xArcs) % 2));
		arcPos.y = floor(i / xArcs) * arcDiam + arcRad;

		dist = sqrt(pow(arcPos.x - center.x, 2) + pow(arcPos.y - center.y, 2));

		arcList[i].rot = dist * rotIncrement;

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
	if (y > 0) {
		float newRotIncrement = PI * 1 / ceil(y / 10);
		if (newRotIncrement != rotIncrement) {
			rotIncrement = newRotIncrement;
			float arcX;
			float arcY;
			double dist;
			ofVec3f center(ofGetWidth() / 2, ofGetHeight() / 2, 0);
			for (int i = 0; i < numArcs; ++i) {
				arcX = arcList[i].pos.x - center.x;
				arcY = arcList[i].pos.y - center.y;
				dist = sqrt( pow(arcX, 2) + pow(arcY, 2) );
				arcList[i].rot = dist * rotIncrement;
			}
		}
	}
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