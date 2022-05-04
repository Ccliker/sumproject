#include "buffer.h"
#include <Windows.h>
#include <iostream>
buffer::buffer()
{
	bufferS = nullptr;
	index = 0;
}
void buffer::addToBuffer(unsigned char* message)
{
	/*if (!bufferS) {
		bufferS = (unsigned char**)malloc(sizeof(unsigned char*) * (index + 1));
	}*/
	bufferS = (unsigned char**)realloc(bufferS, sizeof(unsigned char*) * (index + 1));
	
	bufferS[index++] = message;
	std::cout << "  index: " << this->index << "  bufferS: " << bufferS[index - 1] << std::endl;
}
unsigned char** buffer::getBuffer()
{
	return this->bufferS;
}
void buffer::cleanBuffer()
{
	bufferS = nullptr;
}
buffer::~buffer()
{
	//free(this->bufferS);
}