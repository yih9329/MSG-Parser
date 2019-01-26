#include"stdafx.h"
#include"MFC.h"

IMPLEMENT_DYNCREATE(CFileAccsView, CWnd);

TCHAR* CFileAccsView::OnGetFDir()
{
	BROWSEINFO   bi;
	ITEMIDLIST *pidlBrowse;
	TCHAR path[1000];

	bi.hwndOwner = this->GetSafeHwnd();
	bi.pidlRoot = NULL;

	memset(&bi, 0, sizeof(bi));
	bi.pszDisplayName = path;
	bi.lpszTitle = _T("폴더를 선택하세요.");
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	pidlBrowse = ::SHBrowseForFolder(&bi);

	if (pidlBrowse != NULL) {
		SHGetPathFromIDList(pidlBrowse, path);
	}
	return path;

}
