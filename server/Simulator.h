#pragma once
#include "camera.h"

//#define 4 4
class Simulator
{
public:
	int size;
	Simulator();
	camera arrCamera[4];
	void start();
};