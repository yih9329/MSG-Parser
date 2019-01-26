#include"stdafx.h"
#include"MFC.h"
#include"Header.h"
#include"Sat.h"
#include"SSat.h"
#include"DirEnt.h"
#include"ShortStreamEnt.h"
#include"Property.h"
#include<cmath>
#include<cstringt.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpCmdLine, int nCmdShow) {
	FILE *ogf;
	TCHAR* cur_Path;
	CFileAccsView FDig;
	cur_Path = FDig.OnGetFDir();			// 폴더선택
	CString dir_path = (LPCTSTR)cur_Path;
	CString full_path = dir_path + _T("\\*.msg");
	CFileFind finder;

	bool bWorking = finder.FindFile(full_path);
	int sec_size, ssec_size, sat_stsecid, sat_secnum, ssat_stsecid, ssat_secnum, first = 0;
	int *dir_sec, *sstm_sec;

	while (bWorking) {
		CString filePath;
		bWorking = finder.FindNextFileW();
		filePath = finder.GetFilePath();
		
		ogf = _wfopen((wchar_t*)(LPCTSTR)(filePath), L"rb");
		if (ogf == NULL) {
			cout << "error!" << endl;
			exit(1);
		}			

		Header *header = new Header(ogf);				// 헤더 읽기
		sec_size = header->getSecSize();
		ssec_size = header->getShortSecSize();

		sat_stsecid = header->getSatSecID();
		sat_secnum = header->getSatSecNum();
		Sat *sat = new Sat(sat_secnum, sec_size);
		sat->ReadSAT(ogf, sat_stsecid, sat_secnum, sec_size);			// SAT 테이블 읽기

		ssat_stsecid = header->getShortSatSecID();
		ssat_secnum = header->getShortSatSecNum();
		SSat *ssat = new SSat(ssat_secnum, sec_size);
		ssat->ReadSSAT(ogf, ssat_stsecid, ssat_secnum, sec_size);			// SSAT 테이블 읽기

		dir_sec = sat->ListDirSectors(header->getDirStartSecID(), sat_secnum, sec_size);			// Directory 섹터번호 리스트 가져오기
		DirEnt *dir_ent = new DirEnt(sat->GetDirSecLen());
		dir_ent->ReadDir(ogf, dir_sec, sat->GetDirSecLen(), sec_size);		// Directory Entry 읽기

		sstm_sec = sat->LIstShortStreamSectors(dir_ent->GetShortStreamFirstSec(), sat_secnum, sec_size);		// Short Stream 섹터번호 리스트 가져오기
		ShortStreamEnt *sstm_ent = new ShortStreamEnt(sat->GetShortStreamSecLen(), ssec_size, sec_size);
		sstm_ent->ReadShortStream(ogf, sstm_sec, sat->GetShortStreamSecLen(), ssec_size, sec_size);				// Short Stream Entry 읽기

		Property *propty = new Property();
		propty->ExtractProperty(ssat->GetSSat(), header->getMinStreamSize(), sstm_ent->GetShortStreamEnt(), ssec_size, dir_ent->GetDirEntNum(), dir_ent->GetDirEnt());		//메일정보 추출
		propty->MakeFile((wchar_t*)(LPCTSTR)dir_path, ++first);							// 메일정보 파일생성	

		fclose(ogf);
	}
}
