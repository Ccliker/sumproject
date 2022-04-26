#include "Simulator.h"
#include <thread>
#include <iostream>
Simulator::Simulator()
{
	char id = 'a';
	std::cout << "gg\n";
	for (int i = 0;i < 4;i++) {
		std::cout << "simulator\n";
		arrCamera[i] = camera(id++);
	}
}

void Simulator::start()
{
	
	std::thread cameraThreads[4];
	for (int i = 0;i < 4;i++) {
		cameraThreads[i] = std::thread(&camera::run, arrCamera[i]);
	}
	std::cout << "start\n";
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < arrCamera[i].getIndex();j++) {
			arrCamera[i].arrMessage[j]->parseMessage();
		}		
	}
}
