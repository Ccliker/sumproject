#pragma once
class buffer
{
private:
	unsigned char** bufferS;
	int index;
public:
	buffer();
	void addToBuffer(unsigned char *);
	unsigned char** getBuffer();
	void cleanBuffer();
	int getIndex();
	//~buffer();
};

