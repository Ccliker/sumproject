#include "camera.h"
//#include "Simulator.h"
#include "discoverMessage.h"
#include "statusMessage.h"
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
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
	isActive = true;
	arrMessage = NULL;
	ip = (char*)"127.0.0.1";
}
camera::camera()
{
	arrMessage = nullptr;
	ip = (char*)"127.0.0.1";
}
void camera::generate()
{
	this->arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (this->index + 1));
	(rand() % 2 + 1 == 1) ? arrMessage[this->index++] = createStatusMessage () : arrMessage[index++] = createDiscoverMessage();
	arrMessage[this->index - 1]->print();
	Sleep(1000);
}
camera::~camera()
{
	free(arrMessage);
}
void camera::sendToBuffer()
{
	for (int i = 0;i < this->index;i++) {
		arrMessage[i]->parseBack();
		b.addToBuffer(arrMessage[i]->getMessageBuffer());
	}
	free(arrMessage);
	arrMessage = NULL;
	this->index = 0;
}
int camera::getIndex()
{
	return this->index;
}
void camera::sendToServer()
{
	Sleep(3000);
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}
	string getInput;
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr(this->ip);
	addr.sin_port = htons(3300);
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;

		for (int i = 0;i < 5;i++) {
			getInput = (char*)b.getBuffer()[i];
			send(connection, getInput.c_str(), getInput.length(), 0);
		}
		exit(0);
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
}
char camera::getCameraId()
{
	return this->cameraId;
}
buffer camera::getbuffervalue()
{
	return b;
}
int camera::getmessageInSecond()
{
	return this->messageInSecond;
}
void camera::run()
{
	std::cout <<"cameraId : "<<this->cameraId<<std::endl;
	while (isActive) {
		for (int i = 0;i < this->messageInSecond;i++) {
			this->generate();
		}
		sendToBuffer();
		Sleep(1000);
	}
}
void camera::stop()
{
	this->isActive = false;
}
