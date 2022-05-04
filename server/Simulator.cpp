#include "Simulator.h"
#include <thread>
#include <iostream>
#include <fstream>
#include <Windows.h>




Simulator::Simulator()
{
	char id = 'a';
	for (int i = 0;i < this->size;i++) {
		arrCamera[i] = camera(id++);
		std::cout << "camera: "<< arrCamera[i].getCameraId()<<std::endl;
	}
}

void Simulator::start()
{
	std::thread cameraThreads[4];
	std::thread sendToServerThreads[4];

	for (int i = 0;i < 4;i++) {
		cameraThreads[i] = std::thread(&camera::run, &arrCamera[i]);
		sendToServerThreads[i] = std::thread(&camera::sendToServer, &arrCamera[i]);
	}
	for (int i = 0;i < 4;i++) {
		cameraThreads[i].join();
	}
	/*for (int i = 0;i < this->size;i++) {
		arrCamera[i].run();

	}
	for (int i = 0;i < this->size;i++) {
		
		buffer b = arrCamera[i].getbuffervalue();
		for (int j = 0;j <arrCamera[i].getmessageInSecond();j++) {
			std::cout << "________________\t" << b.getBuffer()[j];
		
		}
	}*/
	
	Sleep(2000);
	char* b = (char*)arrCamera[0].b.getBuffer();
	while (true) {
		for (int i = 0;i < 4;i++) {
			arrCamera[i].sendToServer();
		}
	}
}
	
