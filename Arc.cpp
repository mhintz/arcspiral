#include "Arc.h"

int Arc::rad = 20;
float Arc::angle = TWO_PI / 4;
float Arc::rotVel = TWO_PI / 360;
int Arc::thickness = 10;

Arc::Arc(){
	rot = 0;
	pos.set(0);
	color = 0xffffff;
	path.setStrokeHexColor(color);
	path.setFillHexColor(color);
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
	path.curveTo(pos.x + (cos(rot) * rad), pos.y + (sin(rot) * rad));
	path.curveTo(pos.x + (cos(rot + (angle / 2)) * rad), pos.y + (sin(rot + (angle / 2)) * rad));
	path.curveTo(pos.x + (cos(rot + angle) * rad), pos.y + (sin(rot + angle) * rad));
	path.draw();
}