#include "camera.h"
//#include "Simulator.h"
#include "discoverMessage.h"
#include "statusMessage.h"

#include <random>
#include <Windows.h>
#include <iostream>
statusMessage* createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}

discoverMessage* createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverMessage* dm = new discoverMessage(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	
	return dm;

}


camera::camera(char id )
{
	cameraId = id;
	index = 0;
	seconds = 10;
	isActive = true;
	arrMessage = NULL;

}

camera::camera()
{
	arrMessage = NULL;
}

void camera::generate()
{
	this->count= rand() % 5 + 1;
	while  (count > 0){
	this->arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (index + 1));
	(rand() % 2 + 1 == 1) ? arrMessage[index++] = createStatusMessage () : arrMessage[index++] = createDiscoverMessage();
	arrMessage[index - 1]->print();
	Sleep(1000);
	count--;
	}
}

camera::~camera()
{
	free(arrMessage);
}
void camera::sendToBuffer()
{
	for (int i = 0;i < index;i++) {
		/*std::cout << "before: \t";
		arrMessage[i]->print();*/
		arrMessage[i]->parseBack();
		/*arrMessage[i]->parseMessage();
		std::cout << "after: \t";
		arrMessage[i]->print();*/
		buffer.addToBuffer(arrMessage[i]->getMessageBuffer());
	}
	free(arrMessage);
	arrMessage = NULL;
	index = 0;
}

int camera::getIndex()
{
	return this->index;
}

char camera::getCameraId()
{
	return this->cameraId;
}



void camera::run()
{

	while (isActive) {
		std::cout <<"cameraId : "<<this->cameraId<<std::endl;
		generate();
		arrMessage[index - 1]->print();
		sendToBuffer();
		Sleep(1000);
	}
}

void camera::stop()
{
	this->isActive = false;
}
