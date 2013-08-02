#pragma once

#include <cmath>
#include "ofMain.h"

class Arc{
	public:
		static int rad;
		static float angle;
		static int thickness;
		static float rotVel;

		float rot;
		ofVec3f pos;
		float color;

		ofPath path;

		Arc();

		void update();
		void move(ofVec3f newPos);
		void draw();
};