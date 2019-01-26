#pragma once
#include"stdafx.h"

class CFileAccsView : public CWnd
{
protected: // create from serialization only
	//CFileAccsView();
	DECLARE_DYNCREATE(CFileAccsView)

	// Attributes
public:

	
	// 클래스에서 사용할 변수를 잡고
	char m_dirName[MAX_PATH];         // 선택된 디렉토릴 저장   예:test
	char m_dirFolderPath[MAX_PATH]; // 선택된 디렉토리의 path명 까지 포함한 디렉토리  예: C:\tmp\test


	char m_filename[MAX_PATH];        // 파일명을 저장 한다.

	char m_filenamePath[MAX_PATH];  // Path까지를 포함한 파일명을 저장 한다



	char *m_MultFileList[100];  // 파일 리스트를 저장할 포인터 공간
	int  m_fCount;                    // 파일명의 갯수



	char m_buff[1024];  // 임시버퍼

	TCHAR* OnGetFDir();

};

