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
	~camera();
	baseMessage ** arrMessage;
	buffer buffer;
	int getIndex();
	bool isActive;
	void generate();
	void sendToBuffer();
	void run();
	void stop();

};

