#pragma once
#include "baseMessage.h"
#include "buffer.h"
class camera
{
private:
	char cameraId;
	int index;
	int count;
	
public:
	int messageInSecond;
	int port;
	const char* ip;
	camera();
	camera(char id);
	~camera();
	baseMessage ** arrMessage;
	buffer b;
	int getIndex();
	int getmessageInSecond();
	buffer getbuffervalue();
	char getCameraId();
	bool isActive;
	void generate();
	void sendToBuffer();
	void sendToServer();
	void run();
	void stop();

};

