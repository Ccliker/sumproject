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
	bufferS = (unsigned char**)realloc(bufferS, sizeof(unsigned char*) * (index + 1));
	std :: cout << "index: " << this->index;
	bufferS[index++] = message;
}

unsigned char** buffer::getBuffer()
{
	return bufferS;
}

void buffer::cleanBuffer()
{
	bufferS = nullptr;
}
buffer::~buffer()
{
	free(bufferS);
}