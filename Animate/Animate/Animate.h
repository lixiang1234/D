#pragma once
#include<afxwin.h>
#include<afxcmn.h>
#include<afxcview.h>
#include<afxext.h>
#include<afxshellmanager.h>
#include<afxshelllistCtrl.h>
#include<afxDockablePane.h>
#include "afxdialogex.h"
#include<afxribbonbar.h>
#include<afxext.h>
class CObjectToolBar : public CMFCToolBar
{
public:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
	
	
};
class CObjectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CObjectDlg)

public:
	CObjectDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CObjectDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
class CMyDockablePane :public CDockablePane
{
public:
	CMyDockablePane(void);
	~CMyDockablePane(void);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void AdjustLayout();
	afx_msg void OnDestroy();
	// 定义三个控件
	CEdit m_edit;
	CStatic m_static;
	CObjectDlg m_objectDlg;
	CObjectToolBar m_wndToolBar;//工具条对象
};

class CMyListCtrl :public CListCtrl
{
public:
	CMyListCtrl();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	~CMyListCtrl();
	
};
class CMyListBox :public CListBox
{		
public:
	CMyListBox();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	~CMyListBox();
	
};
class CMyBar :public CStatusBar {
	
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	
};
class CMyComboBox :public CComboBox
{
	DECLARE_DYNAMIC(CMyComboBox)
public:
	CMyComboBox();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	 void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	CImageList* GetImageList() const;
	void* GetItemDataPtr(int nIndex) const;
	int AddString(LPCTSTR lpszString, int nImageIndex);
	void SetImageList(CImageList* pImageList);
	//int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
public:
	CImageList* m_pImageList;
	CSize      m_imageSize;
	unsigned int  m_nEditHeight;
	int m_iIsDropList;
	struct CBDataXI
	{
		// 图像序号,如果为-1,则表示无图像
		int iImageIndex;
		
		// 关联数据的指针
		LPVOID pData;
		
		CBDataXI()
		{
			iImageIndex = -1;
			pData = NULL;
		}
	};

};
class MyCListBox :public CListBox
{
public:
	MyCListBox();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

};

class CMyApp :public CWinApp {
public :
	BOOL  m_bHiColorIcons;
public:
	virtual BOOL InitInstance();
	
};

class CMainWindow :public CFrameWnd
{
public:
	CMainWindow();
protected:
	//CListCtrl mylist;
	CMyListCtrl mylist;
	CButton mybuttom, Delbuttom, DrawItemButton, bkgroundButtom, BKGImageButtom,
		DelAllItemsButtom, ItemIndexRectButtom, AddItemBuytton,PUSHWINDOWS;
	CProgressCtrl progress;
	CImageList imagelist,imagelist2;
	CMyBar CStatusBar;
	CMyListBox list;
	CSpinButtonCtrl CsplitButton;
	CSplitButton sbutton;
	CMyComboBox combobox;
	MyCListBox m_listBox;
	CMenu m_Menu,FileMenu;
	CMyDockablePane Pane;
	CToolBar m_ToolBar;
	CMFCShellListCtrl ShellListCtrl;
	CObjectToolBar CMyTOOL;
	CTreeCtrl m_TreeCrtl;
	CToolBarCtrl M_TOOLBarCtrl;
	CBitmap m_bmpToolBar;
	int nCOUNT, nCurrPos;
	CDialogBar dialogBar;
	CMFCRibbonBar m_RibbonBar;
	CReBar rebar;
	BOOL state,state2;
protected:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCrestestruct);
	afx_msg void OnMybutton();
	afx_msg void OnDeleteColumn();
	afx_msg void OnDrawItem();
	afx_msg void OnGBKbutton();
	afx_msg void OnGKImage();
	afx_msg void OnDelallItem();
	afx_msg void OnGetItemIndexRect();
	afx_msg void OnNMDoubleClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDBoubleClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAddItem();
	afx_msg void OnPushWIndows();
	afx_msg void OnButton40010();
	afx_msg void OnToolbar();
	afx_msg void OnButton2();
	void GetColumnOrderArray();
	void GetEditControl();
	void GetFirstSelectedItemPosition();
	void DrawItem(CDC* pdc);
	void InsertItem();
	void MapIndexToID();
	void Arrange();
	void GetItemData();
	void GetInsertMark();
	UINT ThreadFunc(LPVOID Pparam);
	//virtual BOOL OnInitApp();
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);	
public:
	afx_msg void OnButton40070();
	afx_msg void OnUpdateButton40070(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButton40010(CCmdUI* pCmdUI);
};
