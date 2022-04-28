#include "Simulator.h"
#include <thread>
#include <iostream>
#include <fstream>
#include <Windows.h>
Simulator::Simulator()
{
	char id = 'a';
	for (int i = 0;i < 4;i++) {
		arrCamera[i] = camera(id++);
		//std::cout << "camera: "<< arrCamera[i].getCameraId()<<std::endl;
	}

}

void Simulator::start()
{
	std::thread cameraThreads[4];
	for (int i = 0;i < 4;i++) {
		cameraThreads[i] = std::thread(&camera::run, &arrCamera[i]);
	}
	for (int i = 0;i < 4;i++) {
		cameraThreads[i].join();
	}
	Sleep(3000);
	for (int i = 0;i < 4;i++) {
		std::cout << " " << arrCamera[i].getIndex() << std::endl;
		for (int j = 0;j < arrCamera[i].getIndex();j++) {
			std::cout << "arrcamera[i]: " << arrCamera[i].arrMessage[j] << std::endl;
			
		}
	}
}