#include "discoverMessage.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>

void discoverMessage::parseMessage()
{
	if (!this->messageBuffer)
		return ;
	//this->messageBuffer = (unsigned char *)realloc(messageBuffer, sizeof(char*) * 14);
	std::memcpy(this->messageBuffer,&(this->messageType), 2);
	std::memcpy(this->messageBuffer + 2,&(this->distance), 4);
	std::memcpy(this->messageBuffer + 6,&(this->angle), 4);
	std::memcpy(this->messageBuffer + 10,&(this->speed), 4);
	//std::cout << "________________parseMessage ____________:	" << this->messageBuffer << "\n";
	//return this->messageBuffer;
	
	/*for (int i = 0;i < 14;i++) {
		std::cout << " , " << messageBuffer[i] ;

	}
	std::cout << "parseMessage:	" << this->messageBuffer << "\n";*/
}

void discoverMessage::parseBack()
{
	this->messageBuffer = (unsigned char*)malloc(14);
	std::memcpy(this->messageBuffer, &(this->messageType), 2);
	std::memcpy(this->messageBuffer + 2, &(this->distance), 4);
	std::memcpy(this->messageBuffer + 6, &(this->angle), 4);
	std::memcpy(this->messageBuffer + 10, &(this->speed), 4);
	//std::cout << "parseMessage:	" << this->messageBuffer << "\n";
}
void discoverMessage::print()
{
	std::cout << "inform about your messege:" << "\n";
	std::cout << "Type:	" << this->messageType << "\t" << "distance:	" << this->distance << "\t" << "speed:	" << this->speed << "\t" << "Type:	" << this->messageType<<"\n";
}
discoverMessage::discoverMessage(int messageId, int messageType, float distance, float angle, float speed) :baseMessage(messageId, messageType)
{
	this->distance = (distance < 500 || distance>10000) ? 0 : distance;
	this->angle = (angle < 0 || angle>360) ? 0 : angle;
	this->speed = (speed < 0 || speed>1000) ? 0 : speed;
}