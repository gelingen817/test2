// imageprocessView.h : interface of the CImageprocessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEPROCESSVIEW_H__534BB161_372D_4B3F_89D7_655D637049CB__INCLUDED_)
#define AFX_IMAGEPROCESSVIEW_H__534BB161_372D_4B3F_89D7_655D637049CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"CDib.h"
#include"Morph.h"
class CImageprocessView : public CView
{
protected: // create from serialization only
	CImageprocessView();
	DECLARE_DYNCREATE(CImageprocessView)

// Attributes
public:
	CImageprocessDoc* GetDocument();
	
	CDib mybmp,newbmp;

	int showflag;

	CSize sizeDibDisplay,ImageSize;

	MorphClass morphobj;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageprocessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageprocessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageprocessView)
	afx_msg void OnOpen();
	afx_msg void OnSaveBmp();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in imageprocessView.cpp
inline CImageprocessDoc* CImageprocessView::GetDocument()
   { return (CImageprocessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROCESSVIEW_H__534BB161_372D_4B3F_89D7_655D637049CB__INCLUDED_)
