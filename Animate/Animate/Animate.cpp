#include "Animate.h"
#include"resource.h"
#include <afxwinappex.h>
#include <afxdocksite.h>
#include <afxdockablepane.h>
#include<afxshelllistCtrl.h>
#include<afxmsg_.h>
CMyApp MyApp;
BOOL CMyApp::InitInstance()
{
	
#ifdef DEBUG
    //AfxEnableMemoryTracking(FALSE);//打开或关闭内存跟踪
#endif // DEBUG

    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
#ifdef DEBUG
    //AfxEnableMemoryTracking(FALSE);
#endif // DEBUG
    return TRUE;
}
BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BUTTON, CMainWindow::OnMybutton)
    ON_BN_CLICKED(IDC_DELETE, CMainWindow::OnDeleteColumn)
    ON_BN_CLICKED(IDC_DRAW, CMainWindow::OnDrawItem)
    ON_BN_CLICKED(IDC_bkg, CMainWindow::OnGBKbutton)
    ON_BN_CLICKED(IDC_BKGIMAGE, CMainWindow::OnGKImage)
    ON_BN_CLICKED(IDC_DelALL, CMainWindow::OnDelallItem)
    ON_BN_CLICKED(IDC_BUTTOM, CMainWindow::OnGetItemIndexRect)
    ON_BN_CLICKED(IDC_ADD, CMainWindow::OnAddItem)
    ON_BN_CLICKED(1002, CMainWindow::OnPushWIndows)
    ON_NOTIFY(NM_RCLICK, IDC_MYLISTBOX, OnNMDoubleClickList)
    ON_NOTIFY(NM_DBLCLK, IDC_MYLISTBOX, OnNMDBoubleClickList)
    ON_COMMAND(ID_SELECT_BORDER, &CMainWindow::OnToolbar)
    ON_COMMAND(ID_SELECT_INNER,&CMainWindow::OnButton2)
    ON_COMMAND(ID_BUTTON40010, &CMainWindow::OnButton40010)
    ON_COMMAND(ID_BUTTON40070, &CMainWindow::OnButton40070)
    ON_UPDATE_COMMAND_UI(ID_BUTTON40070, &CMainWindow::OnUpdateButton40070)
    ON_UPDATE_COMMAND_UI(ID_BUTTON40010, &CMainWindow::OnUpdateButton40010)
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{

    Create(NULL, _T("Animate"));

}

void CMainWindow::OnPaint()
{
    CPaintDC dc(this); 
    
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpCrestestruct)
{
    if (CFrameWnd::OnCreate(lpCrestestruct) == -1)
        return -1;
    m_Menu.CreateMenu();
    FileMenu.CreatePopupMenu();
    FileMenu.AppendMenu(MF_STRING, ID_APP_EXIT, _T("E&xit"));
    FileMenu.AppendMenu(MF_STRING, ID_APP_ABOUT,_T("About"));
    m_Menu.AppendMenu(MF_POPUP, (UINT_PTR)FileMenu.m_hMenu, _T("&File"));
    SetMenu(&m_Menu);
    mylist.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, CRect(40, 40, 800, 400), this, IDC_MYLISTBOX);
    mybuttom.Create(_T("TEST1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 400, 100, 430), this, IDC_BUTTON);
    Delbuttom.Create(_T("删除所有项"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 500, 100, 530), this, IDC_DELETE);
    DrawItemButton.Create(_T("TEST2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 600, 100, 630), this, IDC_DRAW);
    bkgroundButtom.Create(_T("设置背景"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 400, 200, 440), this, IDC_bkg);
    BKGImageButtom.Create(_T("设置背景2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 500, 200, 540), this, IDC_BKGIMAGE);
    DelAllItemsButtom.Create(_T("删除所有索引"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 600, 200, 640), this, IDC_DelALL);
    ItemIndexRectButtom.Create(_T("TEST3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(200, 400, 300, 440), this, IDC_BUTTOM);
    progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, CRect(200, 500, 800, 544), this, IDC_Progress);
    imagelist.Create(32, 32, ILC_COLOR24 | ILC_MASK, 1, 1);
    CStatusBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM, AFX_IDW_STATUS_BAR);
    list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | WS_VSCROLL | LBS_SORT | LBS_MULTIPLESEL, CRect(200, 550, 300, 700), this, IDC_ListBOX);
    AddItemBuytton.Create(_T("添加所有索引"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(300, 550, 400, 600), this, IDC_ADD);
    CsplitButton.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | UDS_HORZ | UDS_SETBUDDYINT, CRect(400, 550, 500, 600), this, 1000);
    sbutton.Create(_T("拆分"), WS_CHILD | WS_VISIBLE | WS_BORDER | BS_SPLITBUTTON | BS_DEFSPLITBUTTON, CRect(400, 600, 500, 700), this, 2000);
    combobox.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL|WS_VSCROLL| CBS_SORT  | CBS_DROPDOWNLIST  |CBS_AUTOHSCROLL| CBS_OWNERDRAWVARIABLE, CRect(300, 400, 450, 1040), this, IDC_COMBOX);
    m_listBox.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL| LBS_OWNERDRAWVARIABLE, CRect(500, 400, 550, 500), this, IDC_ListBox);
    PUSHWINDOWS.Create(_T("WINDOWS"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(600, 400, 750, 500),this,1002);
    if (!m_ToolBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_TOP,IDC_TOOLBAR1)||!m_ToolBar.LoadToolBar(IDR_TOOLBAR2))
    {
        TRACE0("创建失败");
        //return FALSE;
        
   }
    m_ToolBar.LoadToolBar(IDR_TOOLBAR2);
    m_ToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_ToolBar);
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
    CString strObjectView("面向对象");
    if (!Pane.Create(strObjectView, this, CRect(800, 0, 1400, 400), TRUE, 1001, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI, AFX_CBRS_REGULAR_TABS, AFX_CBRS_CLOSE))
    {
        TRACE0("未能创建“面向对象”窗口\n");
        return FALSE; // 未能创建
    }
    m_TreeCrtl.Create(WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES | TVS_DISABLEDRAGDROP | TVS_NOTOOLTIPS | TVS_EDITLABELS, 
        CRect(800, 400, 1300, 600), this, ID_MYTREE);
    if (CMyTOOL.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDC_TOOLBAR1))
    {
        CMyTOOL.SetPaneStyle(CMyTOOL.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_ANY));
        CMyTOOL.LoadToolBar(IDR_TOOLBAR2);
        CSize   sizeToolBar = CMyTOOL.CalcFixedLayout(FALSE, TRUE);
        CMyTOOL.SetWindowPos(NULL, 20, 20, sizeToolBar.cx, sizeToolBar.cy, SWP_NOACTIVATE | SWP_NOZORDER);

    }
    M_TOOLBarCtrl.Create(WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER| TBSTYLE_WRAPABLE| CCS_ADJUSTABLE| TBSTYLE_TOOLTIPS,CRect(30,30,100,30),this,1003);
    const int iButtonNum = 2;
    CBitmap bm;
    UINT Resource[2] = { IDB_BITMAP1,IDB_BITMAP2 };          //位图ID数组
    int i;
    imagelist2.Create(32, 32, ILC_COLOR24 | ILC_MASK, 0, 0);
    M_TOOLBarCtrl.SetBitmapSize(CSize(32, 32));

    for (i = 0; i < 2; i++)
    {
        bm.LoadBitmap(Resource[i]);
        imagelist2.Add(&bm, (CBitmap*)NULL);
        bm.Detach();
    }

    M_TOOLBarCtrl.SetImageList(&imagelist2);
    TBBUTTON pRTF_Button[2];
    UINT buttonID[] = { ID_SELECT_BORDER,ID_SELECT_INNER };
    CString str;
    for (long Index = 0; Index < iButtonNum; Index++)
    {
        pRTF_Button[Index].iBitmap = Index;
        pRTF_Button[Index].idCommand = buttonID[Index];
        pRTF_Button[Index].fsStyle = TBSTYLE_CHECKGROUP;
        pRTF_Button[Index].fsState = TBSTATE_ENABLED;
        pRTF_Button[Index].dwData = 0;
        pRTF_Button[Index].iString = M_TOOLBarCtrl.AddStrings(str);
    }

    CSize size(32, 32);
    M_TOOLBarCtrl.SetButtonSize(size);
    M_TOOLBarCtrl.AddButtons(iButtonNum, pRTF_Button);
    //delete[] pRTF_Button;

    M_TOOLBarCtrl.SetBitmapSize(size);
    M_TOOLBarCtrl.ModifyStyle(0, TBSTYLE_FLAT);
    m_bmpToolBar.LoadBitmap(IDB_BITMAP2);		//这种方式对24位位图有效
    M_TOOLBarCtrl.AddBitmap(iButtonNum, &m_bmpToolBar);
    UpdateData(FALSE);
    //if (!m_RibbonBar.Create(this, WS_CHILD | CBRS_TOP))
       // TRACE0("RibbonBar Creation failed!!!");
    //EnableDocking(CBRS_ALIGN_ANY);
   // dialogBar.Create(this, IDD_DIALOG1, CBRS_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY, IDD_DIALOGBAR);
    if (!rebar.Create(this))
        TRACE0("rebar Creation failed!!!");
    rebar.AddBar(&m_ToolBar);
    rebar.RedrawWindow();
    REBARBANDINFO info;
    info.cbSize = sizeof(info);
    info.fMask = RBBIM_BACKGROUND;
    m_ToolBar.ModifyStyle(0, TBSTYLE_TRANSPARENT);//设置工具栏背景色透明
    //info.hbmBack = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TOOLBACK));//加载位图
    rebar.GetReBarCtrl().SetBandInfo(0, &info);
    return TRUE;
}
void CMainWindow::OnMybutton()
{
    mylist.InsertColumn(0, _T("Player Name"), LVCFMT_LEFT);
    LVCOLUMN col;
    col.mask = LVCF_FMT | LVCF_TEXT;
    col.pszText = (LPWSTR)_T("Jersey Number");
    col.fmt = LVCFMT_LEFT;
    mylist.InsertColumn(1, &col);
    // Set reasonable widths for our columns
    mylist.SetColumnWidth(0, LVSCW_AUTOSIZE_USEHEADER);
    mylist.SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);    
    GetEditControl();
    GetFirstSelectedItemPosition();
    

    //MessageBox(_T("HELLO"), _T("OK"), MB_OK);
}

void CMainWindow::OnDeleteColumn()
{
    int nCount = mylist.GetHeaderCtrl()->GetItemCount();
    for (int i = 0; i < nCount; i++) {
        mylist.DeleteColumn(i);
    }
}

void CMainWindow::OnDrawItem()
{
    CDC* dc = new CDC;
    DrawItem(dc);
}

void CMainWindow::OnGBKbutton()
{
    COLORREF crBkColor = ::GetSysColor(COLOR_3DFACE);
    mylist.SetBkColor(crBkColor);
    //CWinThread* pThread = AfxBeginThread(ThreadFunc, NULL);
    
}

void CMainWindow::OnGKImage()
{
    LVBKIMAGE bki;
    if (mylist.GetBkImage(&bki) && (bki.ulFlags == LVBKIF_SOURCE_NONE))
    {
        HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, _T("bitmap1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE| LR_DEFAULTSIZE | LR_CREATEDIBSECTION);
        mylist.SetBkImage(hBitmap, TRUE);
    }
    InsertItem();
    MapIndexToID();
    Arrange();
    GetItemData();
    mylist.SetFocus();
    CEdit* pmyEdit = mylist.EditLabel(1);
    LVCOLUMN col;
    col.mask = LVCF_WIDTH;
    // Double the column width of the first column.
    if (mylist.GetColumn(0, &col))
    {
        col.cx *= 2;
        mylist.SetColumn(0, &col);
    }
    int nWidth = mylist.GetColumnWidth(1);
   mylist.SetColumnWidth(1, 20 + nWidth);
   //mylist.CancelEditLabel();
   //POINT point;
   //CImageList* pImageList = mylist.CreateDragImage(1, &point);
   //delete pImageList;
   GetInsertMark();
   BOOL b=mylist.SetCallbackMask(LVIS_SELECTED | LVIS_FOCUSED);
   ASSERT(mylist.GetCallbackMask() ==(LVIS_SELECTED | LVIS_FOCUSED));
   GetColumnOrderArray();
   static UINT indicators[] =	//添加状态栏：消息、标志,时间
   {
       IDS_STRING_MESSAGE,
       IDS_STRING_VERSION,
       IDS_STRING_TIME
   };
   CStatusBar.SetIndicators(indicators,3);
   CStatusBar.SetPaneInfo(0, IDS_STRING_MESSAGE, SBPS_STRETCH, 0);
   //窗格突出显示，第二栏长度为320单位，显示IDS_STRING_VERSION字符串  
   CStatusBar.SetPaneInfo(1, IDS_STRING_VERSION, SBPS_POPOUT, 320);
   CStatusBar.SetPaneInfo(2, IDS_STRING_TIME, SBPS_POPOUT, 120); //第三栏长度120单位
   RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, IDS_STRING_TIME);//指定状态栏在显示窗口位置
   SetTimer(2, 1000, NULL);       //一个1秒触发一次的定时器
   HCURSOR hCursor =AfxGetApp()->LoadCursorW(IDC_CURSOR1);
   mylist.SetHotCursor(hCursor);
   ASSERT(mylist.GetHotCursor() == hCursor);
   
}

void CMainWindow::OnDelallItem()
{
    mylist.DeleteAllItems();
    ASSERT(mylist.GetItemCount() == 0);
    nCOUNT = list.GetCount();
    for (int i = 0; i < nCOUNT; i++)
    {
        list.DeleteString(i);
    }
}

void CMainWindow::OnGetItemIndexRect()
{
    LVITEMINDEX lvItemIndex;
    lvItemIndex.iGroup = 1;
    lvItemIndex.iItem = 1;
    CRect rect;
    rect.left = 10;
    rect.top = 10;
    rect.right = 10;
    rect.bottom = 20;
    BOOL bRet = mylist.GetItemIndexRect(&lvItemIndex, 0, LVIR_BOUNDS, &rect);

    // Draw a red rectangle around the item.
    mylist.GetDC()->Draw3dRect(&rect, RGB(255, 0, 0), RGB(255, 0, 0));
    
}

void CMainWindow::OnNMDoubleClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    CString Temp;
    if (pNMListView->iItem != -1)
    {

    }
    if ((pNMListView->uOldState & LVIS_FOCUSED) == LVIS_FOCUSED && (pNMListView->uNewState & LVIS_FOCUSED) == 0) {
        MessageBox(_T("OK"));
    }
    else if ((pNMListView->uOldState & LVIS_FOCUSED) == 0 && (pNMListView->uNewState & LVIS_FOCUSED) == LVIS_FOCUSED) {
        MessageBox(_T("OK1"));
    }
    if ((pNMListView->uOldState & LVIS_SELECTED) == LVIS_SELECTED && (pNMListView->uNewState & LVIS_SELECTED) == 0)
    {
        MessageBox(_T("OK2"));
    }
    else if ((pNMListView->uOldState & LVIS_SELECTED) == 0 && (pNMListView->uNewState & LVIS_SELECTED) == LVIS_SELECTED)
    {
        MessageBox(_T("OK3"));
    }
    *pResult = 0;
}

void CMainWindow::OnNMDBoubleClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
}

void CMainWindow::OnAddItem()
{
    imagelist.Create(32, 32, ILC_COLOR32 | ILC_MASK, 2, 1);
    imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
    imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));

    combobox.SetImageList(&imagelist);
    combobox.AddString(L"123", 0);
    combobox.AddString(L"456", 1);
    combobox.SetCurSel(1);
    m_listBox.AddString(_T("one"));
    CString str1, str2;
    int n;
    for (int i = 0; i < combobox.GetCount(); i++)
    {
        n = combobox.GetLBTextLen(i);
        combobox.GetLBText(i, str1.GetBuffer(n));
        str1.ReleaseBuffer();

        str2.Format(_T("item %d: %s\r\n"), i, str1.GetBuffer(0));
        AFXDUMP(str2);
    }
    DRAWITEMSTRUCT lpDrawItemStruct;
    lpDrawItemStruct.CtlType = ODT_COMBOBOX;
    lpDrawItemStruct.CtlID = IDC_COMBOX;
    //lpDrawItemStruct.hDC = (HDC)GetDC();
    lpDrawItemStruct.hwndItem = CWnd::GetSafeHwnd();
    lpDrawItemStruct.itemAction = (ODA_DRAWENTIRE | ODA_FOCUS | ODA_SELECT);
    lpDrawItemStruct.itemState = (ODS_CHECKED | ODS_COMBOBOXEDIT | ODS_DEFAULT | ODS_DISABLED | ODS_FOCUS | ODS_GRAYED | ODS_HOTLIGHT | ODS_INACTIVE | ODS_NOACCEL | ODS_NOFOCUSRECT | ODS_SELECTED);
    //lpDrawItemStruct.itemID = 0;
    //lpDrawItemStruct.itemData = LB_SETITEMDATA;
    combobox.AddString(_T("李想"),0);
    list.AddString(_T("123"));
    list.AddString(_T("456"));
    //TCHAR lpszWinPath[MAX_PATH], lpszOldPath[MAX_PATH];
    //VERIFY(0 < ::GetWindowsDirectory(lpszWinPath, MAX_PATH));

    // Make the windows directory the current directory.
    //::GetCurrentDirectory(MAX_PATH, lpszOldPath);
    //::SetCurrentDirectory(lpszWinPath);

    //combobox.ResetContent();
    //combobox.Dir(DDL_READWRITE | DDL_DIRECTORY, _T("*.*"));

    // Reset the current directory to its previous path.
    //::SetCurrentDirectory(lpszOldPath);
    
}
void CMainWindow::OnPushWIndows()
{
    TVINSERTSTRUCT tvInsert;
    tvInsert.hParent = NULL;
    tvInsert.hInsertAfter = NULL;
    tvInsert.item.mask = TVIF_TEXT;
    tvInsert.item.pszText = (LPWSTR)("United States");
    m_TreeCrtl.InsertItem(&tvInsert);
    HTREEITEM hCountry = m_TreeCrtl.InsertItem(&tvInsert);
    HTREEITEM hPA = m_TreeCrtl.InsertItem(TVIF_TEXT,_T("Pennsylvania"), 0, 0, 0, 0, 0, hCountry, NULL);
    m_TreeCrtl.InsertItem(_T("Pittsburgh"), hPA, TVI_SORT);
    m_TreeCrtl.InsertItem(_T("Harrisburg"), hPA, TVI_SORT);
    m_TreeCrtl.InsertItem(_T("Altoona"), hPA, TVI_SORT);
    HTREEITEM hWA = m_TreeCrtl.InsertItem(TVIF_TEXT, _T("one"), 0, 0, 0, 0, 0, hCountry, NULL);
    m_TreeCrtl.InsertItem(_T("Seattle"), hWA, TVI_SORT);
    m_TreeCrtl.InsertItem(_T("Kalaloch"), hWA, TVI_SORT);
    m_TreeCrtl.InsertItem(_T("Yakima"), hWA, TVI_SORT);
   int b= m_ToolBar.GetToolBarCtrl().EnableButton(IDR_TOOLBAR2, FALSE);
   int i= M_TOOLBarCtrl.EnableButton(ID_BUTTON40010, FALSE);
   UINT u=m_ToolBar.GetItemID(0);
}
void CMainWindow::GetColumnOrderArray()
{
    CHeaderCtrl* pHeaderCtrl = mylist.GetHeaderCtrl();

    if (pHeaderCtrl != NULL)
    {
        int  nColumnCount = pHeaderCtrl->GetItemCount();
        LPINT pnOrder = (LPINT)malloc(nColumnCount * sizeof(int));
        ASSERT(pnOrder != NULL);
        mylist.GetColumnOrderArray(pnOrder, nColumnCount);

        int i, j, nTemp;
        for (i = 0, j = nColumnCount - 1; i < j; i++, j--)
        {
            nTemp = pnOrder[i];
            pnOrder[i] = pnOrder[j];
            pnOrder[j] = nTemp;
        }

        mylist.SetColumnOrderArray(nColumnCount, pnOrder);
        free(pnOrder);
    }
}

void CMainWindow::GetEditControl()
{
    
    LPCTSTR lpszmyString = _T("custom label!");
    mylist.SetFocus();
    mylist.EnsureVisible(0, FALSE);
    mylist.EditLabel(0);
    // If possible, replace the text in the label edit control.
    CEdit* pEdit = mylist.GetEditControl();

    if (pEdit != NULL)
    {
        pEdit->SetWindowText(lpszmyString);
    }
}

void CMainWindow::GetFirstSelectedItemPosition()
{
    POSITION pos = mylist.GetFirstSelectedItemPosition();
    if (pos == NULL)
    {
        TRACE(_T("No items were selected!\n"));
    }
    else
    {
        while (pos)
        {
            int nItem = mylist.GetNextSelectedItem(pos);
            TRACE(_T("Item %d was selected!\n"), nItem);
            // you could do your own processing on nItem here
        }
    }
}
void CMainWindow::DrawItem(CDC* pdc)
{
    DRAWITEMSTRUCT lpDrawItemStruct;
    lpDrawItemStruct.CtlType = ODT_LISTVIEW;
    lpDrawItemStruct.CtlID = IDC_MYLISTBOX;
    lpDrawItemStruct.hDC = (HDC)GetDC();
    lpDrawItemStruct.hwndItem = CWnd::GetSafeHwnd();
    lpDrawItemStruct.itemAction = (ODA_DRAWENTIRE | ODA_FOCUS | ODA_SELECT);
    lpDrawItemStruct.itemState = (ODS_CHECKED | ODS_COMBOBOXEDIT | ODS_DEFAULT | ODS_DISABLED | ODS_FOCUS | ODS_GRAYED | ODS_HOTLIGHT | ODS_INACTIVE | ODS_NOACCEL | ODS_NOFOCUSRECT | ODS_SELECTED);
    lpDrawItemStruct.itemID = 0;
    lpDrawItemStruct.itemData = LB_SETITEMDATA;
    RECT rect;
    rect.left = 10;
    rect.right = 800;
    rect.top = 10;
    rect.bottom = 400;
    lpDrawItemStruct.rcItem = rect;
    mylist.ModifyStyle(0, LVS_OWNERDRAWFIXED, 0);
    mylist.DrawItem(&lpDrawItemStruct);
}

void CMainWindow::InsertItem()
{
    CString strText;
    int nColumnCount = mylist.GetHeaderCtrl()->GetItemCount();
    imagelist.SetBkColor(RGB(255, 255, 255));
    imagelist.Add(AfxGetApp()->LoadIconW(IDI_ICON1));
    mylist.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES);
    mylist.SetImageList(&imagelist, LVSIL_SMALL);
    mylist.SetItem(0, 1, LVIF_TEXT | LVIF_IMAGE, _T("123"), 0, 0, 0, 0);
    // Insert 10 items in the list view control.
    for (int i = 0; i < 10; i++)
    {
        strText.Format(TEXT("item %d"), i);

        // Insert the item, select every other item.
        mylist.InsertItem(LVIF_TEXT | LVIF_STATE, i, strText,(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);

        // Initialize the text of the subitems.
        for (int j = 1; j < nColumnCount; j++)
        {
            strText.Format(TEXT("sub-item %d %d"), i, j);
            mylist.SetItemText(i, j, strText);
            progress.SetPos(i);
            progress.SetRange(0, 100);
            nCurrPos = progress.GetPos();
            progress.SetStep(i*10);
            progress.StepIt();
        }
    }
}

void CMainWindow::MapIndexToID()
{
    int iCount = mylist.GetItemCount();
    UINT nId = 0;
    UINT nIndex = 0;
    for (int iIndexOriginal = 0; iIndexOriginal < iCount; iIndexOriginal++)
    {
        // Map index to ID.
        nId = mylist.MapIndexToID((UINT)iIndexOriginal);

        // Map ID to index.
        nIndex = mylist.MapIDToIndex(nId);

        if (nIndex != (UINT)(iIndexOriginal))
        {
            CString str;
            str.Format(_T("Mapped index (%d) is not equal to original index (%d)"),
                nIndex, (UINT)(iIndexOriginal));
            AfxMessageBox(str);
            return;
        }
    }
    AfxMessageBox(_T("The mapped indexes and original indexes are equal."),
        MB_ICONINFORMATION);
}

void CMainWindow::Arrange()
{
    mylist.Arrange(LVA_ALIGNLEFT);
}

void CMainWindow::GetItemData()
{
    for (int i = 0; i < mylist.GetItemCount(); i++)
    {
        if (mylist.GetItemData(i) == 0)
        {
            mylist.SetItemData(i, (DWORD)-1);
        }
    }
}

void CMainWindow::GetInsertMark()
{
    LVINSERTMARK lvi = { 0 };
    lvi.cbSize= sizeof(LVINSERTMARK);
    lvi.dwFlags = LVIM_AFTER;
    lvi.iItem = 1;
    BOOL b = mylist.GetInsertMark(&lvi);
    
}

UINT CMainWindow::ThreadFunc(LPVOID Pparam)
{
    return 0;
}

CMyListCtrl::CMyListCtrl()
{
}

void CMyListCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    int nItem = lpDrawItemStruct->itemID;   //菜单项的菜单项标识符或列表框或组合框中项的索引
    if (nItem == -1)                        //索引等于-1 返回
        return;
    CRect rcCol = lpDrawItemStruct->rcItem; //矩形区域
    CString sText;
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);//加载HDC设备上下文
    int nOldDCMode = pDC->SaveDC();                     //保存DC
    LVITEM item;                //指定或接收列表视图项的属性
    item.iItem = nItem;         //此结构所引用的项的从零开始的索引
    item.iSubItem = 0;          //此结构引用的子项的从 1 开始的索引;如果此结构引用项而不是子项，则为零
    item.mask = LVIF_IMAGE | LVIF_STATE;    //指定此结构的哪些成员包含要设置的数据或正在请求哪些成员的标志集
    item.stateMask = 0XFFFF;    //指定将检索或修改 状态 成员的哪些位的值
    GetItem(&item);             //检索列表视图项的部分属性或全部属性
    BOOL bSelected = item.state & LVIS_SELECTED;//指示项的状态、状态图像和覆盖图像
    COLORREF color = ::GetSysColor(COLOR_WINDOW); //获取系统颜色
    if (bSelected)
    {
        pDC->SetBkColor(::GetSysColor(COLOR_HIGHLIGHT)); //设置背景色
        pDC->SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT)); //设置字体颜色
        color = ::GetSysColor(COLOR_HIGHLIGHT);         //获取系统色
    }

    else
    {
        pDC->SetBkColor(color);   //设置背景色
        pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));//设置字体颜色为系统色
    }
    LV_COLUMN lvc;              //包含有关在报告视图列
    lvc.mask = LVCF_FMT | LVCF_WIDTH;
    rcCol.right = rcCol.left;           //矩形区域右边=左边
    for (int nCol = 0; GetColumn(nCol, &lvc); nCol++)
    {
      rcCol.left = rcCol.right;     //矩形左边=右边
        rcCol.right = rcCol.left + GetColumnWidth(nCol);//右边=左边+列宽
        HPEN hOldPen = (HPEN)::SelectObject(lpDrawItemStruct->hDC, ::CreatePen(PS_SOLID, 1, RGB(0xc0, 0xc0, 0xc0)));//在DC里面选择PEN铅笔
        HBRUSH hOldBrush = (HBRUSH)::SelectObject(lpDrawItemStruct->hDC, ::CreateSolidBrush(color));//DC里面指定指定纯色的逻辑画笔
        ::Rectangle(lpDrawItemStruct->hDC, rcCol.left - 1, rcCol.top - 1, rcCol.right, rcCol.bottom);//函数绘制一个矩形。 矩形使用当前笔轮廓，并使用当前画笔填充
        ::DeleteObject(SelectObject(lpDrawItemStruct->hDC, hOldBrush));//删除逻辑画笔
        ::DeleteObject(SelectObject(lpDrawItemStruct->hDC, hOldPen));   //删除PEN画笔
        //sText = MakeShortString(pDC, GetItemText(nItem, nCol), rcCol.Width());
        pDC->DrawText(sText, -1, CRect::CRect(rcCol.left + 3, rcCol.top, rcCol.right, rcCol.bottom - 2), DT_LEFT);//绘制文本

    }
    pDC->RestoreDC(nOldDCMode);
}

CMyListCtrl::~CMyListCtrl()
{
}

void CMyBar::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    int nItem = lpDrawItemStruct->itemID;   //菜单项的菜单项标识符或列表框或组合框中项的索引
    if (nItem == -1)                        //索引等于-1 返回
        return;
    CRect rcCol = lpDrawItemStruct->rcItem; //矩形区域
    CString sText;
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);//加载HDC设备上下文
    int nOldDCMode = pDC->SaveDC();                     //保存DC
    lpDrawItemStruct->CtlType == ODT_STATIC;
}

CMyListBox::CMyListBox()
{
}

void CMyListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
}

CMyListBox::~CMyListBox()
{
}


void CMainWindow::DoDataExchange(CDataExchange* pDX)
{
    // TODO: 在此添加专用代码和/或调用基类
    CFrameWnd::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBOX, combobox);
    
}

IMPLEMENT_DYNAMIC(CMyComboBox, CComboBox)
CMyComboBox::CMyComboBox()
{
    m_pImageList = NULL;
    m_imageSize.cx = 0;
    m_imageSize.cy = 0;
    m_nEditHeight = 0;
    m_iIsDropList = -1;

}

void CMyComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    if (lpDrawItemStruct->itemID == -1)
    {
        return;
    }

    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    pDC->SetBkMode(TRANSPARENT);
    RECT& rcItem = lpDrawItemStruct->rcItem;

    CString cstrItemText;
    CComboBox::GetLBText(lpDrawItemStruct->itemID, cstrItemText);

    CBDataXI* pData = (CBDataXI*)CComboBox::GetItemDataPtr(lpDrawItemStruct->itemID);
    if (NULL == pData)
    {
        return;
    }

    // 是否处于选中状态
    BOOL bIsSelected = (lpDrawItemStruct->itemAction | ODA_SELECT)
        && (lpDrawItemStruct->itemState & ODS_SELECTED);

    // 是否处于焦点状态
    BOOL bIsFocused = (lpDrawItemStruct->itemAction | ODA_FOCUS)
        && (lpDrawItemStruct->itemState & ODS_FOCUS);

    // 绘制背景
    if (bIsSelected)
    {
        COLORREF oldColor = pDC->GetBkColor();
        pDC->FillSolidRect(&rcItem, ::GetSysColor(COLOR_HIGHLIGHT));
        pDC->SetBkColor(oldColor);
    }
    else
    {
        pDC->FillSolidRect(&rcItem, pDC->GetBkColor());
    }

    // 绘制ICON
    CRect rcIcon(rcItem.left, rcItem.top, rcItem.left, rcItem.top);
    if (m_pImageList)
    {
        HICON hIcon = m_pImageList->ExtractIcon(pData->iImageIndex);
        if (hIcon)
        {
            rcIcon.right = rcItem.left + m_imageSize.cx + 2 * CBXI_CX_BORDER;
            rcIcon.bottom = rcItem.top + m_imageSize.cy + 2 * CBXI_CY_BORDER;

            CPoint pos(rcIcon.left + CBXI_CX_BORDER, rcIcon.top + CBXI_CY_BORDER);
            pDC->DrawState(pos, m_imageSize, hIcon, DSS_NORMAL, (CBrush*)NULL);
            ::DestroyIcon(hIcon);
        }
    }

    // 绘制Text
    if (bIsSelected)
    {
        pDC->SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));
    }
    else
    {
        pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
    }
    CRect rcText(rcItem);
    rcText.left = rcIcon.right;
    rcText.top = rcIcon.top;
    pDC->DrawText(cstrItemText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_WORDBREAK);

	
}

void CMyComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
    CDC* pDC = GetDC();
    LPCTSTR lpszText = (LPCTSTR)lpMeasureItemStruct->itemData;
    CSize szText = pDC->GetTextExtent(lpszText);
    ReleaseDC(pDC);

    lpMeasureItemStruct->itemHeight =
        szText.cy > m_imageSize.cy + 2 * CBXI_CY_BORDER ? szText.cy : m_imageSize.cy + 2 * CBXI_CY_BORDER;

    // 检测是否是DropList
    if (-1 == m_iIsDropList)
    {
        DWORD dwStyle = GetStyle();
        if (DWORD(CBS_DROPDOWNLIST & dwStyle) == (DWORD)CBS_DROPDOWNLIST)
        {
            m_iIsDropList = 1;
        }
        else
        {
            m_iIsDropList = 0;
        }
    }

    // 设置EditCtrl的高度
    if (m_iIsDropList == 1 && lpMeasureItemStruct->itemHeight > m_nEditHeight)
    {
        m_nEditHeight = lpMeasureItemStruct->itemHeight;
        SetItemHeight(-1, m_nEditHeight);
    }

}

CImageList* CMyComboBox::GetImageList() const
{
    return m_pImageList;
}

void* CMyComboBox::GetItemDataPtr(int nIndex) const
{
    CBDataXI* pCBData = (CBDataXI*)CComboBox::GetItemDataPtr(nIndex);
    if (pCBData == (CBDataXI*)CB_ERR || pCBData == NULL)
    {
        return (void*)CB_ERR;
    }

    return pCBData->pData;

}
int CMyComboBox::AddString(LPCTSTR lpszString, int nImageIndex)
{
    int nIndex = CComboBox::AddString(lpszString);
    if (nIndex != CB_ERR && nIndex != CB_ERRSPACE)
    {
        CBDataXI* pData = new CBDataXI();
        pData->iImageIndex = nImageIndex;
        pData->pData = NULL;
        CComboBox::SetItemData(nIndex, (DWORD_PTR)pData);
    }

    return nIndex;
}
void CMyComboBox::SetImageList(CImageList* pImageList)
{
    m_pImageList = pImageList;
    if (m_pImageList)
    {
        int cx;
        int cy;
        ImageList_GetIconSize(*m_pImageList, &cx, &cy);
        m_imageSize.cx = cx;
        m_imageSize.cy = cy;
    }
    else
    {
        m_imageSize.cx = 0;
        m_imageSize.cy = 0;
    }
    Invalidate();
}
MyCListBox::MyCListBox()
{
}
void MyCListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);
    LPCTSTR lpszText = (LPCTSTR)lpDrawItemStruct->itemData;
    ASSERT(lpszText != NULL);
    CDC dc;

    dc.Attach(lpDrawItemStruct->hDC);

    // Save these value to restore them when done drawing.
    COLORREF crOldTextColor = dc.GetTextColor();
    COLORREF crOldBkColor = dc.GetBkColor();

    // If this item is selected, set the background color 
    // and the text color to appropriate values. Also, erase
    // rect by filling it with the background color.
    if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&
        (lpDrawItemStruct->itemState & ODS_SELECTED))
    {
        dc.SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));
        dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT));
        dc.FillSolidRect(&lpDrawItemStruct->rcItem,
            ::GetSysColor(COLOR_HIGHLIGHT));
    }
    else
    {
        dc.FillSolidRect(&lpDrawItemStruct->rcItem, crOldBkColor);
    }

    // If this item has the focus, draw a red frame around the
    // item's rect.
    if ((lpDrawItemStruct->itemAction | ODA_FOCUS) &&
        (lpDrawItemStruct->itemState & ODS_FOCUS))
    {
        CBrush br(RGB(255, 0, 0));
        dc.FrameRect(&lpDrawItemStruct->rcItem, &br);
    }

    // Draw the text.
    dc.DrawText(lpszText, (int)_tcslen(lpszText), &lpDrawItemStruct->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

    // Reset the background color and the text color back to their
    // original values.
    dc.SetTextColor(crOldTextColor);
    dc.SetBkColor(crOldBkColor);

    dc.Detach();

}
CMyDockablePane::CMyDockablePane(void)
{
}

CMyDockablePane::~CMyDockablePane(void)
{
}
BEGIN_MESSAGE_MAP(CMyDockablePane, CDockablePane)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()
int CMyDockablePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDockablePane::OnCreate(lpCreateStruct) == -1)
        return -1;
    CRect rectDummy;
    rectDummy.SetRectEmpty();

    // 创建组合:
    const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_BORDER | CBS_SORT | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, ID_START);
    m_wndToolBar.LoadToolBar(101, 0, 0, TRUE /* 已锁定*/);
    m_wndToolBar.CleanUpLockedImages();
    m_wndToolBar.LoadBitmap(MyApp.m_bHiColorIcons ? ID_START : ID_START, 0, 0, TRUE /* 锁定*/);

    m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
    m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));
    m_wndToolBar.SetOwner(this);

    // 所有命令将通过此控件路由，而不是通过主框架路由:
    m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

    // 动态创建控件  控件尺寸为0
    if (!m_edit.Create(dwViewStyle, rectDummy, this, 1))
    {
        TRACE0("未能创建CEdit控件 \n");
        return -1;      // 未能创建
    }

    // 动态创建控件
    if (!m_static.Create(NULL, dwViewStyle, rectDummy, this, 6))
    {
        TRACE0("未能创建CStatic控件\n");
        return -1; // 未能创建
    }

    // 创建对话框窗口:
    if (!m_objectDlg.Create(IDD_DIALOG1, this))    // 创建非摸对话框
    {
        TRACE0("未能创建对话框窗口\n");
        return -1;      // 未能创建
    }
    m_objectDlg.ShowWindow(SW_SHOW);				// 显示对话框
    AdjustLayout();

    return 0;
}

void CMyDockablePane::OnSize(UINT nType, int cx, int cy)
{
    CDockablePane::OnSize(nType, cx, cy);
    AdjustLayout();
}

void CMyDockablePane::AdjustLayout()
{
    if (GetSafeHwnd() == NULL || (AfxGetMainWnd() != NULL && AfxGetMainWnd()->IsIconic()))   // IsIconic()作用是判断窗口是否处于最小化状态（点击了最小化按钮之后）。
    {
        return;
    }
    CRect rectClient;
    GetClientRect(rectClient);    // 获得客户窗口尺寸矩形

    int height = rectClient.Height() / 3;
    //控件在窗口中所占空间大小   动态调整控件的位置及尺寸
    m_edit.SetWindowPos(this, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height() / 3, SWP_NOACTIVATE | SWP_NOZORDER);
    m_static.SetWindowPos(this, rectClient.left, rectClient.top + height, rectClient.Width(), rectClient.Height() / 3, SWP_NOACTIVATE | SWP_NOZORDER);
    m_objectDlg.SetWindowPos(this, rectClient.left, rectClient.top + height * 2, rectClient.Width(), rectClient.Height() / 3, SWP_NOACTIVATE | SWP_NOZORDER);
    int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;
    m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);

    //控件在窗口中所占空间大小
    m_objectDlg.SetWindowPos(this, rectClient.left, rectClient.top + cyTlb, rectClient.Width(), rectClient.Height() - cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);


}

void CMyDockablePane::OnDestroy()
{   CDockablePane::OnDestroy();
    m_objectDlg.DestroyWindow();    
}
IMPLEMENT_DYNAMIC(CObjectDlg, CDialogEx)

CObjectDlg::CObjectDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG1, pParent)
{

}

CObjectDlg::~CObjectDlg()
{
}

void CObjectDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CObjectDlg, CDialogEx)
END_MESSAGE_MAP()

void CMainWindow::OnToolbar()
{
    MessageBox(L"TEO");
}

void CMainWindow::OnButton2()
{
    M_TOOLBarCtrl.EnableButton(ID_SELECT_BORDER, FALSE);
    MessageBox(L"Three");
}

void CMainWindow::OnButton40010()
{   
    state = FALSE;
    bool b=m_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON40070, state);
    //MessageBox(L"Three123");
    // TODO: 在此添加命令处理程序代码
   MessageBox(L"40010");
}

void CMainWindow::OnButton40070()
{
    // TODO: 在此添加命令处理程序代码
     state2 = FALSE;
    m_ToolBar.GetToolBarCtrl().EnableButton(ID_BUTTON40010, state2);
    
    MessageBox(L"40070");
}


void CMainWindow::OnUpdateButton40070(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(!state);
    
    // TODO: 在此添加命令更新用户界面处理程序代码
}


void CMainWindow::OnUpdateButton40010(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(!state2);
    // TODO: 在此添加命令更新用户界面处理程序代码
}
