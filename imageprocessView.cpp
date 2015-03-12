// imageprocessView.cpp : implementation of the CImageprocessView class
//

#include "stdafx.h"
#include "imageprocess.h"

#include "imageprocessDoc.h"
#include "imageprocessView.h"

#include<iostream>
#include<fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView

IMPLEMENT_DYNCREATE(CImageprocessView, CView)

BEGIN_MESSAGE_MAP(CImageprocessView, CView)
	//{{AFX_MSG_MAP(CImageprocessView)
	ON_COMMAND(ID_OPEN, OnOpen)
	ON_COMMAND(ID_SAVE_BMP, OnSaveBmp)
	ON_COMMAND(Change, OnChange)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView construction/destruction

CImageprocessView::CImageprocessView()
{
	// TODO: add construction code here

}

CImageprocessView::~CImageprocessView()
{
}

BOOL CImageprocessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView drawing

void CImageprocessView::OnDraw(CDC* pDC)
{
	CImageprocessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);			
	
	mybmp.Draw(pDC,CPoint(0,0),ImageSize);

	if ( showflag ==1)
		newbmp.Draw(pDC, CPoint(ImageSize.cx+20,0), ImageSize);



}

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView printing

BOOL CImageprocessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageprocessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageprocessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView diagnostics

#ifdef _DEBUG
void CImageprocessView::AssertValid() const
{
	CView::AssertValid();
}

void CImageprocessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageprocessDoc* CImageprocessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageprocessDoc)));
	return (CImageprocessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageprocessView message handlers

void CImageprocessView::OnOpen() 
{

	CFileDialog FileDlg(TRUE, _T("*.bmp"), "",OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,"image files (*.bmp; *.jpg) |*.bmp;*.jpg|AVI files (*.avi) |*.avi|All Files (*.*)|*.*||",NULL);
	char title[]= {"Open Image"};
	FileDlg.m_ofn.lpstrTitle= title;

	CFile file ;
	if( FileDlg.DoModal() == IDOK ) 
	{
		if(!file.Open(FileDlg.GetPathName(), CFile::modeRead))
		{
			AfxMessageBox("cannot open the file");
			return;
		}
		if(!mybmp.Read(&file))
		{
			AfxMessageBox("cannot read the file");
			return;
		}
	}
		
	if (mybmp.m_lpBMIH->biCompression != BI_RGB)
	{
		AfxMessageBox("Can not read compressed file.");
		return ;
	}
	ImageSize=mybmp.GetDimensions();
}







void CImageprocessView::OnSaveBmp() 
{
	CFileDialog FileDlg(FALSE, _T("*.bmp"), "",OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,"image files (*.bmp) |*.bmp|AVI files (*.avi) |*.avi|All Files (*.*)|*.*||",NULL);
	char title[]= {"Open Image"};
	FileDlg.m_ofn.lpstrTitle= title;
	CFile file ;
	if( FileDlg.DoModal() == IDOK ) 
	{
		if(!file.Open(FileDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate | CFile::typeBinary))
		{
			AfxMessageBox("cannot open the file");
			return;
		}
		else
	      	mybmp.Write(&file);
	}

   	
}





void CImageprocessView::OnChange() 
{
    newbmp.CreateCDib(ImageSize, 24);

    CPoint a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,m1,a2,b2,c2,d2,e2,f2,g2,h2,i2,j2,k2,m2,s1,s2,t1,t2;
	
    double stepx1[20],stepy1[20],stepx2[20],stepy2[20],stepx3[20],stepy3[20];

	ImageSize = mybmp.GetDimensions();
	a1= CPoint(164,192);
	b1= CPoint(124,214);
	c1= CPoint(169,228);
	d1= CPoint(203,212);
	e1= CPoint(278,176);
	f1= CPoint(238,210);
	g1= CPoint(278,223);
	h1 =CPoint(302,195);
	i1 =CPoint(0,0);
	j1= CPoint(0,ImageSize.cy-1);
	k1= CPoint(ImageSize.cx-1,ImageSize.cy-1);
	m1= CPoint(ImageSize.cx-1,0);
	s1 =CPoint(ImageSize.cx/2,0);
	t1 =CPoint((ImageSize.cx-1)/2,ImageSize.cy-1);



	a2= CPoint(167,202);//206
	b2= CPoint(118,214);//121,214
	c2= CPoint(167,207);
	d2= CPoint(212,212);//208,212
	e2= CPoint(278,203);//278,208
	f2= CPoint(235,211);//238,211
	g2= CPoint(278,209);//278,209
	h2 =CPoint(306,203);//305,199
	i2 =CPoint(0,0);
	j2= CPoint(0,ImageSize.cy-1);
	k2= CPoint(ImageSize.cx-1,ImageSize.cy-1);
	m2= CPoint(ImageSize.cx-1,0);
	s2 =CPoint(ImageSize.cx/2,0);
	t2 =CPoint((ImageSize.cx-1)/2,ImageSize.cy-1);

	CPoint tmp1,tmp2,tmp3,tmp11,tmp22,tmp33;

	for(int k = 0; k<20;k++) //分20步进行
	{
		for( int i =1;i < 21; i++)//20个三角形
		{
		//为求解作准备
		switch(i)
		{
			case 1:	
				tmp1 = i1;
				tmp2 = a1;
				tmp3 = s1;

				tmp11 = i2;
				tmp22 = a2;
				tmp33 = s2;
				break;
			case 2:
				tmp1 = i1;
				tmp2 = b1;
				tmp3 = a1;

				tmp11 = i2;
				tmp22 = b2;
				tmp33 = a2;
				break;
			case 3:
				tmp1 = i1;
				tmp2 = b1;
				tmp3 = j1;

				tmp11 = i2;
				tmp22 = b2;
				tmp33 = j2;
				break;
			case 4:
				tmp1 = j1;
				tmp2 = b1;
				tmp3 = c1;

				tmp11 = j2;
				tmp22 = b2;
				tmp33 = c2;
				break;
			case 5:
				tmp1 = j1;
				tmp2 = c1;
				tmp3 = t1;

				tmp11 = j2;
				tmp22 = c2;
				tmp33 = t2;
				break;
			case 6:
				tmp1 = c1;
				tmp2 = d1;
				tmp3 = t1;

				tmp11 = c2;
				tmp22 = d2;
				tmp33 = t2;
				break;
			case 7:
				tmp1 = d1;
				tmp2 = f1;
				tmp3 = t1;

				tmp11 = d2;
				tmp22 = f2;
				tmp33 = t2;
				break;
			case 8:
				tmp1 = f1;
				tmp2 = g1;
				tmp3 = t1;

				tmp11 = f2;
				tmp22 = g2;
				tmp33 = t2;
				break;
			case 9:
				tmp1 = g1;
				tmp2 = t1;
				tmp3 = k1;

				tmp11 = g2;
				tmp22 = t2;
				tmp33 = k2;
				break;
			case 10:
				tmp1 = g1;
				tmp2 = h1;
				tmp3 = k1;

				tmp11 = g2;
				tmp22 = h2;
				tmp33 = k2;/////////
				break;
			case 11:
				tmp1 = m1;
				tmp2 = h1;
				tmp3 = k1;

				tmp11 = m2;
				tmp22 = h2;
				tmp33 = k2;
				break;
			case 12:
				tmp1 = e1;
				tmp2 = m1;
				tmp3 = h1;

				tmp11 = e2;
				tmp22 = m2;
				tmp33 = h2;
				break;
			case 13:
				tmp1 = s1;
				tmp2 = m1;
				tmp3 = e1;

				tmp11 = s2;
				tmp22 = m2;
				tmp33 = e2;
				break;
			case 14:
				tmp1 = s1;
				tmp2 = f1;
				tmp3 = e1;

				tmp11 = s2;
				tmp22 = f2;
				tmp33 = e2;
				break;
			case 15:
				tmp1 = s1;
				tmp2 = d1;
				tmp3 = f1;

				tmp11 = s2;
				tmp22 = d2;
				tmp33 = f2;
				break;
			case 16:
				tmp1 = a1;
				tmp2 = s1;
				tmp3 = d1;

				tmp11 = a2;
				tmp22 = s2;
				tmp33 = d2;
				break;
			case 17:
				tmp1 = a1;
				tmp2 = b1;
				tmp3 = d1;

				tmp11 = a2;
				tmp22 = b2;
				tmp33 = d2;
				break;
			case 18:
				tmp1 = b1;
				tmp2 = d1;
				tmp3 = c1;

				tmp11 = b2;
				tmp22 = d2;
				tmp33 = c2;
				break;
			case 19:
				tmp1 = e1;
				tmp2 = f1;
				tmp3 = h1;

				tmp11 = e2;
				tmp22 = f2;
				tmp33 = h2;
				break;
			case 20:
				tmp1 = f1;
				tmp2 = h1;
				tmp3 = g1;

				tmp11 = f2;
				tmp22 = h2;
				tmp33 = g2;
				break;
			default:
				break;
		}
//初始化步长
		if(k==0)
		{
			int num =20;
					
			stepx1[i-1] =(tmp11.x-tmp1.x)*1.0/num;
			stepy1[i-1] =(tmp11.y-tmp1.y)*1.0/num;

			stepx2[i-1] =(tmp22.x-tmp2.x)*1.0/num;
			stepy2[i-1] =(tmp22.y-tmp2.y)*1.0/num;

			stepx3[i-1] =(tmp33.x-tmp3.x)*1.0/num;
			stepy3[i-1] =(tmp33.y-tmp3.y)*1.0/num;	
		}
		//给步长赋值
		tmp11.x=tmp1.x+(int)(stepx1[i-1]*k+0.5);
		tmp11.y=tmp1.y+(int)(stepy1[i-1]*k+0.5);

		tmp22.x=tmp2.x+(int)(stepx2[i-1]*k+0.5);
		tmp22.y=tmp2.y+(int)(stepy2[i-1]*k+0.5);

		tmp33.x=tmp3.x+(int)(stepx3[i-1]*k+0.5);
		tmp33.y=tmp3.y+(int)(stepy3[i-1]*k+0.5);


			

		morphobj.TrianglePoint[i-1][0] = tmp1;
		morphobj.TrianglePoint[i-1][1] = tmp2 ;
		morphobj.TrianglePoint[i-1][2] = tmp3 ;
				
		//求第1-20个三角形的解
		morphobj.GetSolution(morphobj.Solution[i-1],tmp1,tmp2,tmp3,tmp11,tmp22,tmp33);
		}
//画newbmp.首先初始化
		for (int y = 0 ; y <= ImageSize.cy-1; y ++)
			for (int x = 0 ; x <= ImageSize.cx-1 ; x ++)
			{
				RGBQUAD color;

				color.rgbRed = 255;
				color.rgbGreen = 255; 
				color.rgbBlue =255;
				newbmp.WritePixel(x,y,color);
			}

		for (  y = 0 ; y < ImageSize.cy-1; y ++)
			for (int x = 0 ; x < ImageSize.cx-1 ; x ++)
			{
				CPoint thePoint(x,y);
				int x_new,y_new;
				RGBQUAD color;

				int flag=0;
				morphobj.JudgePointInTriangle(thePoint,morphobj.TrianglePoint,flag);

				flag -= 1;

				color = mybmp.GetPixel(x,y);  
						
				x_new=int(morphobj.Solution[flag][0]*thePoint.x+morphobj.Solution[flag][1]*thePoint.y+morphobj.Solution[flag][2]+0.5);
				y_new=int(morphobj.Solution[flag][3]*thePoint.x+morphobj.Solution[flag][4]*thePoint.y+morphobj.Solution[flag][5]+0.5);

				if (x_new>=0 && x_new< ImageSize.cx && y_new>=0 &&  y_new <ImageSize.cy)
				newbmp.WritePixel(x_new,y_new,color);
									
			}
//进行插值避免空白像素
        	for ( y = 1 ; y < ImageSize.cy-2; y ++)
				for (int x = 1 ; x < ImageSize.cx-2 ; x ++)
				{
					RGBQUAD color,color2;
					color = newbmp.GetPixel(x,y); 
					 
 
					if(color.rgbRed == 255 && color.rgbGreen == 255 && color.rgbBlue ==255)
					{
						int tmp1=0,tmp2=0,tmp3 = 0;int count =0;
						for(int k1=-1;k1<=1;k1++)
							for(int k2=-1;k2<=1;k2++)
						{
							color2	= newbmp.GetPixel(x+k1,y+k2);
							
							if (color2.rgbRed != 255 || color.rgbGreen != 255 || color.rgbBlue !=255)
							{
								count++;
								tmp1 += color2.rgbRed;
								tmp2 += color2.rgbGreen;
								tmp3 += color2.rgbBlue;
							}
						}
						if (count != 0)
						{
							color2.rgbRed = tmp1/count;
							color2.rgbGreen = tmp2/count;
			    			color2.rgbBlue	= tmp3/count;
						
							newbmp.WritePixel(x,y,color2);
						}
					} 

				}


        newbmp.Draw(GetDC(),CPoint(ImageSize.cx+20,0),ImageSize);
		showflag = 1;
		Invalidate();

	}

	
}




//DEL void CImageprocessView::OnTest() 
//DEL {
//DEL     newbmp.CreateCDib(ImageSize, 24);
//DEL 
//DEL 	int k=0;
//DEL 
//DEL 	CPoint a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,m1,a2,b2,c2,d2,e2,f2,g2,h2,i2,j2,k2,m2,s1,s2,t1,t2;
//DEL 	
//DEL     double stepx1[20],stepy1[20],stepx2[20],stepy2[20],stepx3[20],stepy3[20];
//DEL 
//DEL 	ImageSize = mybmp.GetDimensions();
//DEL 
//DEL 
//DEL //	a1= CPoint(164,192);
//DEL 	a1=CPoint(141,209);
//DEL 	b1= CPoint(124,214);
//DEL 	c1= CPoint(169,228);
//DEL //	d1= CPoint(203,212);
//DEL     d1= CPoint(198,212);
//DEL 	e1= CPoint(278,176);
//DEL //	f1= CPoint(238,210);
//DEL     f1= CPoint(252,206);
//DEL 	g1= CPoint(278,223);
//DEL //	h1 =CPoint(302,195);
//DEL 	h1= CPoint(303,203);
//DEL 	i1 =CPoint(0,0);
//DEL 	j1= CPoint(0,ImageSize.cy-1);
//DEL 	k1= CPoint(ImageSize.cx-1,ImageSize.cy-1);
//DEL 	m1= CPoint(ImageSize.cx-1,0);
//DEL 	s1 =CPoint(ImageSize.cx/2,0);
//DEL 	t1 =CPoint((ImageSize.cx-1)/2,ImageSize.cy-1);
//DEL 
//DEL 
//DEL 
//DEL //	a2= CPoint(167,206);
//DEL     a2= CPoint(163,210);
//DEL //	b2= CPoint(121,214);
//DEL     b2= CPoint(110,230);
//DEL 	c2= CPoint(167,207);
//DEL 	d2= CPoint(208,212);
//DEL 	e2= CPoint(278,208);
//DEL //	f2= CPoint(238,211);
//DEL     f2= CPoint(252,207);
//DEL 	g2= CPoint(278,209);
//DEL //	h2 =CPoint(305,199);
//DEL     h2 =CPoint(305,205);
//DEL 	i2 =CPoint(0,0);
//DEL 	j2= CPoint(0,ImageSize.cy-1);
//DEL 	k2= CPoint(ImageSize.cx-1,ImageSize.cy-1);
//DEL 	m2= CPoint(ImageSize.cx-1,0);
//DEL 	s2 =CPoint(ImageSize.cx/2,0);
//DEL 	t2 =CPoint((ImageSize.cx-1)/2,ImageSize.cy-1);
//DEL 
//DEL 	CPoint tmp1,tmp2,tmp3,tmp11,tmp22,tmp33;
//DEL 
//DEL 		for( int i =1;i < 21; i++)//20个三角形
//DEL 		{
//DEL 		//为求解作准备
//DEL 		switch(i)
//DEL 		{
//DEL 			case 1:	
//DEL 				tmp1 = i1;
//DEL 				tmp2 = a1;
//DEL 				tmp3 = s1;
//DEL 
//DEL 				tmp11 = i2;
//DEL 				tmp22 = a2;
//DEL 				tmp33 = s2;
//DEL 				break;
//DEL 			case 2:
//DEL 				tmp1 = i1;
//DEL 				tmp2 = b1;
//DEL 				tmp3 = a1;
//DEL 
//DEL 				tmp11 = i2;
//DEL 				tmp22 = b2;
//DEL 				tmp33 = a2;
//DEL 				break;
//DEL 			case 3:
//DEL 				tmp1 = i1;
//DEL 				tmp2 = b1;
//DEL 				tmp3 = j1;
//DEL 
//DEL 				tmp11 = i2;
//DEL 				tmp22 = b2;
//DEL 				tmp33 = j2;
//DEL 				break;
//DEL 			case 4:
//DEL 				tmp1 = j1;
//DEL 				tmp2 = b1;
//DEL 				tmp3 = c1;
//DEL 
//DEL 				tmp11 = j2;
//DEL 				tmp22 = b2;
//DEL 				tmp33 = c2;
//DEL 				break;
//DEL 			case 5:
//DEL 				tmp1 = j1;
//DEL 				tmp2 = c1;
//DEL 				tmp3 = t1;
//DEL 
//DEL 				tmp11 = j2;
//DEL 				tmp22 = c2;
//DEL 				tmp33 = t2;
//DEL 				break;
//DEL 			case 6:
//DEL 				tmp1 = c1;
//DEL 				tmp2 = d1;
//DEL 				tmp3 = t1;
//DEL 
//DEL 				tmp11 = c2;
//DEL 				tmp22 = d2;
//DEL 				tmp33 = t2;
//DEL 				break;
//DEL 			case 7:
//DEL 				tmp1 = d1;
//DEL 				tmp2 = f1;
//DEL 				tmp3 = t1;
//DEL 
//DEL 				tmp11 = d2;
//DEL 				tmp22 = f2;
//DEL 				tmp33 = t2;
//DEL 				break;
//DEL 			case 8:
//DEL 				tmp1 = f1;
//DEL 				tmp2 = g1;
//DEL 				tmp3 = t1;
//DEL 
//DEL 				tmp11 = f2;
//DEL 				tmp22 = g2;
//DEL 				tmp33 = t2;
//DEL 				break;
//DEL 			case 9:
//DEL 				tmp1 = g1;
//DEL 				tmp2 = t1;
//DEL 				tmp3 = k1;
//DEL 
//DEL 				tmp11 = g2;
//DEL 				tmp22 = t2;
//DEL 				tmp33 = k2;
//DEL 				break;
//DEL 			case 10:
//DEL 				tmp1 = g1;
//DEL 				tmp2 = h1;
//DEL 				tmp3 = k1;
//DEL 
//DEL 				tmp11 = g2;
//DEL 				tmp22 = h2;
//DEL 				tmp33 = k2;/////////
//DEL 				break;
//DEL 			case 11:
//DEL 				tmp1 = m1;
//DEL 				tmp2 = h1;
//DEL 				tmp3 = k1;
//DEL 
//DEL 				tmp11 = m2;
//DEL 				tmp22 = h2;
//DEL 				tmp33 = k2;
//DEL 				break;
//DEL 			case 12:
//DEL 				tmp1 = e1;
//DEL 				tmp2 = m1;
//DEL 				tmp3 = h1;
//DEL 
//DEL 				tmp11 = e2;
//DEL 				tmp22 = m2;
//DEL 				tmp33 = h2;
//DEL 				break;
//DEL 			case 13:
//DEL 				tmp1 = s1;
//DEL 				tmp2 = m1;
//DEL 				tmp3 = e1;
//DEL 
//DEL 				tmp11 = s2;
//DEL 				tmp22 = m2;
//DEL 				tmp33 = e2;
//DEL 				break;
//DEL 			case 14:
//DEL 				tmp1 = s1;
//DEL 				tmp2 = f1;
//DEL 				tmp3 = e1;
//DEL 
//DEL 				tmp11 = s2;
//DEL 				tmp22 = f2;
//DEL 				tmp33 = e2;
//DEL 				break;
//DEL 			case 15:
//DEL 				tmp1 = s1;
//DEL 				tmp2 = d1;
//DEL 				tmp3 = f1;
//DEL 
//DEL 				tmp11 = s2;
//DEL 				tmp22 = d2;
//DEL 				tmp33 = f2;
//DEL 				break;
//DEL 			case 16:
//DEL 				tmp1 = a1;
//DEL 				tmp2 = s1;
//DEL 				tmp3 = d1;
//DEL 
//DEL 				tmp11 = a2;
//DEL 				tmp22 = s2;
//DEL 				tmp33 = d2;
//DEL 				break;
//DEL 			case 17:
//DEL 				tmp1 = a1;
//DEL 				tmp2 = b1;
//DEL 				tmp3 = d1;
//DEL 
//DEL 				tmp11 = a2;
//DEL 				tmp22 = b2;
//DEL 				tmp33 = d2;
//DEL 				break;
//DEL 			case 18:
//DEL 				tmp1 = b1;
//DEL 				tmp2 = d1;
//DEL 				tmp3 = c1;
//DEL 
//DEL 				tmp11 = b2;
//DEL 				tmp22 = d2;
//DEL 				tmp33 = c2;
//DEL 				break;
//DEL 			case 19:
//DEL 				tmp1 = e1;
//DEL 				tmp2 = f1;
//DEL 				tmp3 = h1;
//DEL 
//DEL 				tmp11 = e2;
//DEL 				tmp22 = f2;
//DEL 				tmp33 = h2;
//DEL 				break;
//DEL 			case 20:
//DEL 				tmp1 = f1;
//DEL 				tmp2 = h1;
//DEL 				tmp3 = g1;
//DEL 
//DEL 				tmp11 = f2;
//DEL 				tmp22 = h2;
//DEL 				tmp33 = g2;
//DEL 				break;
//DEL 			default:
//DEL 				break;
//DEL 		}
//DEL 
//DEL 		if(k==0)
//DEL 		{
//DEL 			int num =20;
//DEL 					
//DEL 			stepx1[i-1] =(tmp11.x-tmp1.x)*1.0/num;
//DEL 			stepy1[i-1] =(tmp11.y-tmp1.y)*1.0/num;
//DEL 
//DEL 			stepx2[i-1] =(tmp22.x-tmp2.x)*1.0/num;
//DEL 			stepy2[i-1] =(tmp22.y-tmp2.y)*1.0/num;
//DEL 
//DEL 			stepx3[i-1] =(tmp33.x-tmp3.x)*1.0/num;
//DEL 			stepy3[i-1] =(tmp33.y-tmp3.y)*1.0/num;	
//DEL 		}
//DEL 
//DEL 		tmp11.x=tmp1.x+(int)(stepx1[i-1]*k+0.5);
//DEL 		tmp11.y=tmp1.y+(int)(stepy1[i-1]*k+0.5);
//DEL 
//DEL 		tmp22.x=tmp2.x+(int)(stepx2[i-1]*k+0.5);
//DEL 		tmp22.y=tmp2.y+(int)(stepy2[i-1]*k+0.5);
//DEL 
//DEL 		tmp33.x=tmp3.x+(int)(stepx3[i-1]*k+0.5);
//DEL 		tmp33.y=tmp3.y+(int)(stepy3[i-1]*k+0.5);
//DEL 
//DEL 
//DEL 			
//DEL 
//DEL 		morphobj.TrianglePoint[i-1][0] = tmp1;
//DEL 		morphobj.TrianglePoint[i-1][1] = tmp2 ;
//DEL 		morphobj.TrianglePoint[i-1][2] = tmp3 ;
//DEL 				
//DEL //求第1-20个三角形的解
//DEL 		morphobj.GetSolution(morphobj.Solution[i-1],tmp1,tmp2,tmp3,tmp11,tmp22,tmp33);
//DEL 		}
//DEL //画newbmp
//DEL 		for (int y = 0 ; y <= ImageSize.cy-1; y ++)
//DEL 			for (int x = 0 ; x <= ImageSize.cx-1 ; x ++)
//DEL 			{
//DEL 				RGBQUAD color;
//DEL 
//DEL 				color.rgbRed = 255;
//DEL 				color.rgbGreen = 255; 
//DEL 				color.rgbBlue =255;
//DEL 				newbmp.WritePixel(x,y,color);
//DEL 			}
//DEL //进行插值
//DEL 		for (  y = 0 ; y < ImageSize.cy-1; y ++)
//DEL 			for (int x = 0 ; x < ImageSize.cx-1 ; x ++)
//DEL 			{
//DEL 				CPoint thePoint(x,y);
//DEL 				int x_new,y_new;
//DEL 				RGBQUAD color;
//DEL 
//DEL 				int flag=0;
//DEL 				morphobj.JudgePointInTriangle(thePoint,morphobj.TrianglePoint,flag);
//DEL 
//DEL 				flag -= 1;
//DEL 
//DEL 				color = mybmp.GetPixel(x,y);  
//DEL 						
//DEL 				x_new=int(morphobj.Solution[flag][0]*thePoint.x+morphobj.Solution[flag][1]*thePoint.y+morphobj.Solution[flag][2]+0.5);
//DEL 				y_new=int(morphobj.Solution[flag][3]*thePoint.x+morphobj.Solution[flag][4]*thePoint.y+morphobj.Solution[flag][5]+0.5);
//DEL 
//DEL 				if (x_new>=0 && x_new< ImageSize.cx && y_new>=0 &&  y_new <ImageSize.cy)
//DEL 				newbmp.WritePixel(x_new,y_new,color);
//DEL 									
//DEL 			}
//DEL 
//DEL //        newbmp.Draw(GetDC(),CPoint(ImageSize.cx+20,0),ImageSize);
//DEL //		showflag = 1;
//DEL 		Invalidate(TRUE);
//DEL 
//DEL 	
//DEL }
