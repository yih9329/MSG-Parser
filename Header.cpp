#include"stdafx.h"
#include"Header.h"

Header::Header(FILE *f) {
	fread(header, 512, 1, f);
	SetSecSize();
	SetShortSecSize();
}

void Header::SetSecSize() {											// ���� ũ�� ����
	int a = header[30];
	int b = 256 * header[31];
	sec_size = pow(2, a + b);
}

void Header::SetShortSecSize() {
	int a = header[32];
	int b = 256 * header[33];
	ssec_size = pow(2, a + b);
}

int Header::getSecSize() {
	return sec_size;
}

int Header::getShortSecSize() {
	return ssec_size;
}

int Header::getSatSecNum() {										// SAT ���̺�� ���Ǵ� ������ ��
	return header[44] + pow(16, 2) * header[45] + pow(16, 4) * header[46] + pow(16, 6) * header[47];
}

int Header::getDirStartSecID() {									// Directory ���� ���� ���͹�ȣ
	return header[48] + pow(16, 2) * header[49] + pow(16, 4) * header[50] + pow(16, 6) * header[51];
}

int Header::getMinStreamSize() {
	return header[56] + pow(16, 2) * header[57] + pow(16, 4) * header[58] + pow(16, 6) * header[59];
}

int Header::getShortSatSecID() {									// SSAT ���̺� ���� ���͹�ȣ
	return header[60] + pow(16, 2) * header[61] + pow(16, 4) * header[62] + pow(16, 6) * header[63];
}

int Header::getShortSatSecNum() {									// SSAT ���̺�� ���Ǵ� ������ ��
	return header[64] + pow(16, 2) * header[65] + pow(16, 4) * header[66] + pow(16, 6) * header[67];
}

int Header::getSatSecID() {											// SSAT ���̺� ���� ���͹�ȣ

	int j = 0;

	while (1) {

		for (int i = 0; i < 4; i++) {
			if (header[76 + j + i] == 0xFF && header[77 + j + i] == 0xFF && header[78 + j + i] == 0xFF && header[79 + j + i] == 0xFF)
				continue;
			else
				return header[76 + j + i] + pow(16, 2) * header[77 + j + i] + pow(16, 4) * header[78 + j + i] + pow(16, 6) * header[79 + j + i];
		}

		j += 4;
	}

}

Header::~Header() {
	delete[] header;
}

