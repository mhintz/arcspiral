#pragma once

#include <cmath>
#include "ofMain.h"

class Arc{
	public:
		static int rad;
		static int overlap;
		static float angle;
		static float rotVel;
		static int thickness;
		static float color;
		static int subdivisions;

		double rot;
		ofVec3f pos;
		float increment;

		ofPolyline shape;

		Arc();

		void update();
		void move(ofVec3f newPos);
		void draw();
};