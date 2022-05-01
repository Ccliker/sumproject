#pragma once
#include "baseMessage.h"
#include "buffer.h"
class camera
{
private:
	char cameraId;
	int index;
	int seconds;
	int count;

public:
	camera();
	camera(char id);
	//~camera();
	baseMessage ** arrMessage;
	buffer buffer;
	int getIndex();
	char getCameraId();
	bool isActive;
	void generate();
	void sendToBuffer();
	void sendToServer();
	void run();
	void stop();

};

