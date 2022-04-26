#include "buffer.h"
#include <Windows.h>


buffer::buffer()
{
	bufferS = nullptr;
}
void buffer::addToBuffer(unsigned char* message)
{
	bufferS = (unsigned char**)realloc(bufferS, sizeof(unsigned char*) * (index + 1));
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