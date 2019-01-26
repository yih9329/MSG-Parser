#include"stdafx.h"
#include"Sat.h"

Sat::Sat(int sat_secnum, int sec_size) : dir_sec_len(0), sstm_sec_len(0) {
	sat = new unsigned char*[sat_secnum];
	for (int i = 0; i < sat_secnum; i++)
		sat[i] = new unsigned char[sec_size]();
}

void Sat::ReadSAT(FILE *f, int sat_stsecid, int sat_secnum, int sec_size) {
	if (sat_secnum == 1) {
		fseek(f, 0, SEEK_SET);
		fseek(f, sec_size * (sat_stsecid + 1), SEEK_CUR);
		fread(sat[0], sec_size, 1, f);
	}

	else {
		cout << "SAT 테이블이 하나 이상입니다." << endl;
		exit(1);
	}
}

int* Sat::ListDirSectors(int Dir_stsec, int sat_secnum, int sec_size) {

	int s = Dir_stsec * 4, tmp, i = 0;
	int *dir_sec = new int[sec_size * sat_secnum]();

	dir_sec[i++] = Dir_stsec;

	if (sat_secnum == 1) {
		while (1) {

			if (sat[0][s] == 0xFE && sat[0][s + 1] == 0xFF && sat[0][s + 2] == 0xFF && sat[0][s + 3] == 0xFF) {
				dir_sec_len = i;
				return dir_sec;
			}

			else {
				tmp = sat[0][s] + pow(16, 2) * sat[0][s + 1] + pow(16, 4) * sat[0][s + 2] + pow(16, 6) * sat[0][s + 3];
				dir_sec[i++] = tmp;
				s = tmp * 4;
			}
		}
	}

	else {
		cout << "DirEnt Error!" << endl;
		exit(1);
	}
}

int* Sat::LIstShortStreamSectors(int sstm_stsec, int sat_secnum, int sec_size) {

	int s = sstm_stsec * 4, tmp, i = 0;
	int *sstm_sec = new int[sec_size * sat_secnum]();

	sstm_sec[i++] = sstm_stsec;

	if (sat_secnum == 1) {
		while (1) {

			if (sat[0][s] == 0xFE && sat[0][s + 1] == 0xFF && sat[0][s + 2] == 0xFF && sat[0][s + 3] == 0xFF) {
				sstm_sec_len = i;
				return sstm_sec;
			}

			else {
				tmp = sat[0][s] + pow(16, 2) * sat[0][s + 1] + pow(16, 4) * sat[0][s + 2] + pow(16, 6) * sat[0][s + 3];
				sstm_sec[i++] = tmp;
				s = tmp * 4;
			}
		}
	}

	else {
		cout << "ShortStreamSector Error!" << endl;
		exit(1);
	}
}

int Sat::GetDirSecLen() {
	return dir_sec_len;
}

int Sat::GetShortStreamSecLen() {
	return sstm_sec_len;
}

Sat::~Sat() {
	delete[] sat[0];
	delete[] sat;
}