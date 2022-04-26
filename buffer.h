#pragma once
class buffer
{
private:
	unsigned char** bufferS;
	int index = 0;
public:
	buffer();
	void addToBuffer(unsigned char *);
	unsigned char** getBuffer();
	void cleanBuffer();
	~buffer();
};

