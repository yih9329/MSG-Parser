#include"stdafx.h"
#include"ShortStreamEnt.h"

ShortStreamEnt::ShortStreamEnt(int sstm_sec_len, int ssec_size, int sec_size) {
	sstm_ent = new wchar_t*[sstm_sec_len * (sec_size / ssec_size)];
	for (int i = 0; i < sstm_sec_len * (sec_size / ssec_size); i++)
		sstm_ent[i] = new wchar_t[ssec_size/2]();
}

void ShortStreamEnt::ReadShortStream(FILE *f, int *sstm_sec, int sstm_sec_len, int ssec_size, int sec_size) {
	for (int i = 0; i < sstm_sec_len; i++) {
		fseek(f, 0, SEEK_SET);
		fseek(f, sec_size*(sstm_sec[i] + 1), SEEK_CUR);
		for (int j = 0; j < (sec_size / ssec_size); j++) {
			fread(sstm_ent[i * (sec_size / ssec_size) + j], ssec_size, 1, f);
		}
	}
}

wchar_t** ShortStreamEnt::GetShortStreamEnt() {
	return sstm_ent;
}


ShortStreamEnt::~ShortStreamEnt() {
	for (int i = 0; i < wcslen(*sstm_ent); i++)
		delete[] sstm_ent[i];
	delete[] sstm_ent;
}