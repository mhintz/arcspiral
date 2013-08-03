#include "Arc.h"

int Arc::rad = 20;
int Arc::overlap = 6;

float Arc::angle = TWO_PI / 2;
float Arc::rotVel = TWO_PI / 180;

int Arc::thickness = 10;

float Arc::color = 0xffffff;
int Arc::subdivisions = 40;

Arc::Arc(){
	rot = 0;
	pos.set(0);
	increment = angle / subdivisions;
}

void Arc::update(){
	rot += rotVel;
	rot = fmod(rot, TWO_PI);
}

void Arc::move(ofVec3f newPos){
	pos = newPos;
}

void Arc::draw(){
	shape.clear();
	float rotationExtent;
	for (int i = 0; i < subdivisions; ++i) {
		rotationExtent = rot + (increment * i);
		shape.addVertex(pos.x + (cos(rotationExtent) * rad), pos.y + (sin(rotationExtent) * rad));
	}
	shape.draw();
}