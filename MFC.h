#pragma once
#include"stdafx.h"

class CFileAccsView : public CWnd
{
protected: // create from serialization only
	//CFileAccsView();
	DECLARE_DYNCREATE(CFileAccsView)

	// Attributes
public:

	
	// Ŭ�������� ����� ������ ���
	char m_dirName[MAX_PATH];         // ���õ� ���丱 ����   ��:test
	char m_dirFolderPath[MAX_PATH]; // ���õ� ���丮�� path�� ���� ������ ���丮  ��: C:\tmp\test


	char m_filename[MAX_PATH];        // ���ϸ��� ���� �Ѵ�.

	char m_filenamePath[MAX_PATH];  // Path������ ������ ���ϸ��� ���� �Ѵ�



	char *m_MultFileList[100];  // ���� ����Ʈ�� ������ ������ ����
	int  m_fCount;                    // ���ϸ��� ����



	char m_buff[1024];  // �ӽù���

	TCHAR* OnGetFDir();

};

