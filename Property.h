#pragma once
#include<iostream>
enum {SEN_NAME, SEN_ADD, RECV_NAME, RECV_ADD, SUBJECT, ATT_FILE, REF_NAME, HID_REF_NAME};

class Property {
private:
	wchar_t *sender_name, *sender_add, *recv_name, *recv_add, *subject, *attacted_file, *ref_name, *hidden_ref_name; 

public:
	Property();
	void AllocMem(int type, int size);
	void ExtractProperty(unsigned int **ssat, int min_stream_size, wchar_t **sstm_ent, int ssec_size, int dir_ent_num, wchar_t **dir_ent);
	void MakeFile(wchar_t *path, int first);
	~Property();
};