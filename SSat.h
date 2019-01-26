#pragma once
#include<iostream>
using namespace std;

class SSat {
private:
	unsigned int **ssat;

public:
	SSat(int ssat_secnum, int sec_size);
	void ReadSSAT(FILE *f, int ssat_stsecid, int ssat_secnum, int sec_size);
	unsigned int** GetSSat();
	~SSat();
};