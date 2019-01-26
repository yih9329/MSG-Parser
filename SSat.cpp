#include"stdafx.h"
#include"SSat.h"

SSat::SSat(int ssat_secnum, int sec_size) {
	ssat = new unsigned int*[ssat_secnum];
	for (int i = 0; i < ssat_secnum; i++)
		ssat[i] = new unsigned int[sec_size/sizeof(int)];
}

void SSat::ReadSSAT(FILE *f, int ssat_stsecid, int ssat_secnum, int sec_size) {
	if (ssat_secnum == 1) {
		fseek(f, 0, SEEK_SET);
		fseek(f, sec_size*(ssat_stsecid + 1), SEEK_CUR);
		fread(ssat[0], sec_size, 1, f);
	}

	else {
		cout << "SSAT 테이블이 하나 이상입니다." << endl;
		exit(1);
	}
}

unsigned int** SSat::GetSSat() {
	return ssat;
}

SSat::~SSat() {
	delete[] ssat[0];
	delete[] ssat;
}