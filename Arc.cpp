#include "Arc.h"

int Arc::rad = 20;
float Arc::angle = TWO_PI / 4;
float Arc::rotVel = TWO_PI / 360;
int Arc::thickness = 20;

Arc::Arc(){
	rot = 0;
	pos.set(0);
	color = 0xffffff;
	path.setStrokeHexColor(color);
}

void Arc::update(){
	rot += rotVel;
	if (rot > TWO_PI) {
		rot = 0;
	}
}

void Arc::move(ofVec3f newPos){
	pos = newPos;
}

void Arc::draw(){
	float rotDeg = (rot / TWO_PI) * 360;
	float angleDeg = (angle / TWO_PI) * 360;
	path.clear();
	path.moveTo(pos.x, pos.y);
	path.arc(pos.x, pos.y, rad, rad, rotDeg + angleDeg, rotDeg);

	path.draw();
}