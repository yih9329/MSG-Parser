#include"stdafx.h"
#include"Property.h"

Property::Property() {
	sender_add = NULL;
	sender_name = NULL;
	recv_add = NULL;
	recv_name = NULL;
	subject = NULL;
	attacted_file = NULL;
	ref_name = NULL;
	hidden_ref_name = NULL;
}

void Property::AllocMem(int type, int size) {

	if (size % 2)
		size = size / 2 + 1;
	else
		size = size / 2;

	switch (type) {
	case SEN_NAME:
		sender_name = new wchar_t[size]();
		break;

	case SEN_ADD:
		sender_add = new wchar_t[size]();
		break;

	case RECV_NAME:
		recv_name = new wchar_t[size]();
		break;

	case RECV_ADD:
		recv_add = new wchar_t[size]();
		break;

	case SUBJECT:
		subject = new wchar_t[size]();
		break;

	case ATT_FILE:
		attacted_file = new wchar_t[size]();
		break;

	case REF_NAME:
		ref_name = new wchar_t[size]();
		break;

	case HID_REF_NAME:
		hidden_ref_name = new wchar_t[size]();
		break;
	}
}

void Property::ExtractProperty(unsigned int **ssat, int min_stream_size, wchar_t **sstm_ent, int ssec_size, int dir_ent_num, wchar_t **dir_ent) {

	int sec, size, k;
	for (int i = 0; i < dir_ent_num; i++) {
		if (dir_ent[i][12] == '3' && dir_ent[i][13] == '0' && dir_ent[i][14] == '0' && dir_ent[i][15] == '3' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 받는사람 메일
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(RECV_ADD, size);

			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							recv_add[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							recv_add[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '0' && dir_ent[i][13] == 'E' && dir_ent[i][14] == '0' && dir_ent[i][15] == '4' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 받는사람 이름
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(RECV_NAME, size);
			
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							recv_name[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							recv_name[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '0' && dir_ent[i][13] == 'C' && dir_ent[i][14] == '1' && dir_ent[i][15] == 'F' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 보낸사람 메일
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(SEN_ADD, size);
			
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							sender_add[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							sender_add[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}
	
			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '0' && dir_ent[i][13] == 'C' && dir_ent[i][14] == '1' && dir_ent[i][15] == 'A' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 보낸사람 이름
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(SEN_NAME, size);
			
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							sender_name[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							sender_name[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '0' && dir_ent[i][13] == '0' && dir_ent[i][14] == '3' && dir_ent[i][15] == '7' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 메일 제목
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(SUBJECT, size);

			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							subject[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++) 
							subject[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size/2);
					}
				}
				
			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '3' && dir_ent[i][13] == '7' && dir_ent[i][14] == '0' && dir_ent[i][15] == '7' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 첨부파일명
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(ATT_FILE, size);
		
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							attacted_file[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							attacted_file[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '0' && dir_ent[i][13] == 'E' && dir_ent[i][14] == '0' && dir_ent[i][15] == '2' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 숨은참조이름
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(HID_REF_NAME, size);
		
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							hidden_ref_name[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							hidden_ref_name[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}

		else if (dir_ent[i][12] == '3' && dir_ent[i][13] == '7' && dir_ent[i][14] == '0' && dir_ent[i][15] == '7' && dir_ent[i][16] == '0' && dir_ent[i][17] == '0' && dir_ent[i][18] == '1' && dir_ent[i][19] == 'F') {
			// 참조이름
			k = 0;
			size = dir_ent[i][60] + pow(16, 4) * dir_ent[i][61];
			sec = dir_ent[i][58] + pow(16, 4) * dir_ent[i][59];
			AllocMem(REF_NAME, size);
		
			if (size < min_stream_size) {
				if (size % 2)
					size = size / 2 + 1;
				else
					size = size / 2;

				while (1) {
					if (size <= (ssec_size / 2)) {
						for (int j = 0; j < size; j++)
							ref_name[k++] = sstm_ent[sec][j];
						break;
					}

					else {
						for (int j = 0; j < (ssec_size / 2); j++)
							ref_name[k++] = sstm_ent[sec][j];
						sec = ssat[0][sec];
						size -= (ssec_size / 2);
					}
				}

			}

			else {
				puts("메일정보의 길이가 최소길이를 넘었습니다.\n");
				exit(1);
			}
		}
	}

}

void Property::MakeFile(wchar_t *dir_path, int first) {

	wchar_t* full_path = new wchar_t[wcslen(dir_path) + 1]();
	wcscpy(full_path, dir_path);
	FILE *f;
	if (first == 1) {
		f = _wfopen(wcscat(full_path, L"\\property.txt"), L"wb");
		wchar_t mark = 0xFEFF;
		fwrite(&mark, sizeof(wchar_t), 1, f);
		fwprintf(f, L"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", L"발신자", L"발신메일", L"수신자", L"수신메일", L"제목", L"첨부파일명", L"참조자", L"숨은참조자");
		fwprintf(f, L"%c%c", 0x000D, 0x000A);
	}

	else
		f = _wfopen(wcscat(full_path, L"\\property.txt"), L"ab");
	
	fwprintf(f, L"%s\t", sender_name);
	fwprintf(f, L"%s\t", sender_add);
	fwprintf(f, L"%s\t", recv_name);
	fwprintf(f, L"%s\t", recv_add);
	fwprintf(f, L"%s\t", subject);
	fwprintf(f, L"%s\t", attacted_file);
	fwprintf(f, L"%s\t", ref_name);
	fwprintf(f, L"%s\t", hidden_ref_name);
	fwprintf(f, L"%c%c", 0x000D, 0x000A);
	fclose(f);
}

Property::~Property() {
	delete[] sender_name;
	delete[] sender_add;
	delete[] recv_name;
	delete[] recv_add;
	delete[] subject;
	delete[] attacted_file;
	delete[] ref_name;
	delete[] hidden_ref_name;
}