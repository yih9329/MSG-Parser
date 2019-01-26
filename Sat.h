#pragma once
#include<iostream>
using namespace std;

class Sat {
private:
	unsigned char **sat;
	int dir_sec_len, sstm_sec_len;

public:
	Sat(int sat_secnum, int sec_size);
	void ReadSAT(FILE *f, int sat_stsecid, int sat_secnum, int sec_size);
	int* ListDirSectors(int Dir_stsec, int sat_secnum, int sec_size);
	int* LIstShortStreamSectors(int sstm_stsec, int sat_secnum, int sec_size);
	int GetDirSecLen();
	int GetShortStreamSecLen();
	~Sat();
};

