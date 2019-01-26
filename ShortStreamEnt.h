#pragma once
#include<iostream>

class ShortStreamEnt {
private:
	wchar_t **sstm_ent;

public:
	ShortStreamEnt(int sstm_sec_len, int ssec_size, int sec_size);
	void ReadShortStream(FILE *f, int *sstm_sec, int sstm_sec_len, int ssec_size, int sec_size);
	wchar_t** GetShortStreamEnt();
	~ShortStreamEnt();

};
