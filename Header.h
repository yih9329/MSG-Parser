#pragma once
#include<iostream>

class Header {
private:
	unsigned char header[512];
	int sec_size, ssec_size;

public:
	Header(FILE *f);
	void SetSecSize();
	void SetShortSecSize();
	int getSecSize();
	int getShortSecSize();
	int getSatSecNum();
	int getDirStartSecID();
	int getMinStreamSize();
	int getShortSatSecID();
	int getShortSatSecNum();
	int getSatSecID();
	~Header();
};