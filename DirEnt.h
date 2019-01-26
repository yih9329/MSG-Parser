#pragma once
#include<iostream>
#include<cstring>
#define DIR_ENT_SIZE 128
using namespace std;

class DirEnt {
private:
	wchar_t **dir_ent;
	int sstm_stsec, dir_ent_num;

public:
	DirEnt(int dir_sec_len);
	void ReadDir(FILE *f, int *dir_sec, int dir_sec_len, int sec_size);
	wchar_t** GetDirEnt();
	void SetShortStreamFirstSec();
	int GetShortStreamFirstSec();
	int GetDirEntNum();
	~DirEnt();
};