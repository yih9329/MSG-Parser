#include"stdafx.h"
#include"DirEnt.h"

DirEnt::DirEnt(int dir_sec_len) {
	dir_ent_num = dir_sec_len * 4;
	dir_ent = new wchar_t*[dir_ent_num]();
	for (int i = 0; i < dir_ent_num; i++)
		dir_ent[i] = new wchar_t[DIR_ENT_SIZE/2]();
}

void DirEnt::ReadDir(FILE *f, int *dir_sec, int dir_sec_len, int sec_size) {

	for (int i = 0; i < dir_sec_len; i++) {
		fseek(f, 0, SEEK_SET);
		fseek(f, sec_size*(dir_sec[i] + 1), SEEK_CUR);
		fread(dir_ent[i * 4], DIR_ENT_SIZE, 1, f);
		fread(dir_ent[i * 4 + 1], DIR_ENT_SIZE, 1, f);
		fread(dir_ent[i * 4 + 2], DIR_ENT_SIZE, 1, f);
		fread(dir_ent[i * 4 + 3], DIR_ENT_SIZE, 1, f);
	}

	SetShortStreamFirstSec();
}

wchar_t** DirEnt::GetDirEnt() {
	return dir_ent;
}

void DirEnt::SetShortStreamFirstSec() {										//  Short stream이 저장된 첫번째 섹터의 위치를 가져옴.
	sstm_stsec = dir_ent[0][58] + pow(16, 4) * dir_ent[0][59];
}

int DirEnt::GetShortStreamFirstSec() {
	return sstm_stsec;
}

int DirEnt::GetDirEntNum() {
	return dir_ent_num;
}

DirEnt::~DirEnt() {
	for (int i = 0; i < dir_ent_num; i++)
		delete[] dir_ent[i];
	delete[] dir_ent;
}