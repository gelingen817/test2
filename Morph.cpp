#include "stdafx.h"
#include "Morph.h"
#include "math.h"

void MorphClass::GetSolution(double theSolution[6],CPoint fpoint1,CPoint fpoint2,CPoint fpoint3,
							                       CPoint fpoint11,CPoint fpoint22,CPoint fpoint33)
{

			int index=0;
			double* pArray;double**pPointArray;
			pArray=new double[36];
			pPointArray=new double*[6];
			for(int f=0;f<6;++f)
			{
				
				pPointArray[f]=&pArray[index];
				index=index+6;
			}
			double *b=new double[6];
			pPointArray[0][0]=fpoint1.x;
			pPointArray[0][1]=fpoint1.y;
			pPointArray[0][2]=1;
			pPointArray[0][3]=0;
			pPointArray[0][4]=0;
			pPointArray[0][5]=0;

			pPointArray[1][0]=0;
			pPointArray[1][1]=0;
			pPointArray[1][2]=0;
			pPointArray[1][3]=fpoint1.x;
			pPointArray[1][4]=fpoint1.y;
			pPointArray[1][5]=1;

			pPointArray[2][0]=fpoint2.x;
			pPointArray[2][1]=fpoint2.y;
			pPointArray[2][2]=1;
			pPointArray[2][3]=0;
			pPointArray[2][4]=0;
			pPointArray[2][5]=0;

			pPointArray[3][0]=0;
			pPointArray[3][1]=0;
			pPointArray[3][2]=0;
			pPointArray[3][3]=fpoint2.x;
			pPointArray[3][4]=fpoint2.y;
			pPointArray[3][5]=1;

			pPointArray[4][0]=fpoint3.x;
			pPointArray[4][1]=fpoint3.y;
			pPointArray[4][2]=1;
			pPointArray[4][3]=0;
			pPointArray[4][4]=0;
			pPointArray[4][5]=0;

			pPointArray[5][0]=0;
			pPointArray[5][1]=0;
			pPointArray[5][2]=0;
			pPointArray[5][3]=fpoint3.x;
			pPointArray[5][4]=fpoint3.y;
			pPointArray[5][5]=1;

				
			b[0]=fpoint11.x;
			b[1]=fpoint11.y;
			b[2]=fpoint22.x;
			b[3]=fpoint22.y;
			b[4]=fpoint33.x;
			b[5]=fpoint33.y;

			int d=0;double temp,temp1;
			for(int k=0;k<6-1;++k)
			{
			    d=0;
				double temp2=fabs(pPointArray[k][k]);
				for(int h=k+1;h<6;++h)
					if(fabs(pPointArray[h][k])>temp2)
					{
						temp2=fabs(pPointArray[h][k]);
						d=h;
					}
				if(d)
				{
					temp1=b[k];
					b[k]=b[d];
					b[d]=temp1;
					for(int h1=k;h1<6;++h1)
					{
						temp=pPointArray[k][h1];
						pPointArray[k][h1]=pPointArray[d][h1];
						pPointArray[d][h1]=temp;
					}
				}
				for(int i=k+1;i<6;++i)
				{
					double l=-pPointArray[i][k]/pPointArray[k][k];
					for(int j=k+1;j<6;++j)
						pPointArray[i][j]=pPointArray[i][j]+l*pPointArray[k][j];
					b[i]=b[i]+l*b[k];
				}
			}
			for(int k1=6-1;k1>=0;--k1)
				{
					double s=0;
					for(int j=k1+1;j<6;++j)
						s+=pPointArray[k1][j]*theSolution[j];
					theSolution[k1]=(b[k1]-s)/pPointArray[k1][k1];
				}


}

double  MorphClass::area(CPoint p1,CPoint p2,CPoint p3)
{ 

	return fabs((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
}

void MorphClass::inside(CPoint p,CPoint Tri[3],int &flag)
{
	//面积方法
	if (fabs(area(Tri[0],Tri[1],Tri[2])-	 
			 area(p,Tri[1],Tri[2])- 
			 area(p,Tri[0],Tri[2])-
			 area(p,Tri[0],Tri[1]))<1.0e-6) 
		flag = 1;
	else
		flag = 0;

	//向量方法
/*	CPoint p0,p1,p2;
	p0.x=Tri[0].x - p.x; p0.y=Tri[0].y - p.y;
	p1.x=Tri[1].x - p.x; p1.y=Tri[1].y - p.y;
	p2.x=Tri[2].x - p.x; p2.y=Tri[2].y - p.y;

	//只需依次计算MA x MB,MB x MC,MC x MA,如果此3结果都是同号（或都正，或都负）
	double MAB = 0,MBC=0,MCA=0;
	MAB = p0.x * p1.y - p0.y*p1.x;
	MBC = p1.x * p2.y - p1.y*p2.x;
	MCA = p2.x * p0.y - p2.y*p0.x;
	if(( MAB > 0 && MBC > 0 && MCA > 0) || (MAB < 0 && MBC < 0 && MCA < 0))
		flag = 1;
	else 
		flag = 0;*/
	
}

void MorphClass::JudgePointInTriangle(CPoint thePoint,CPoint TrianglePoint[20][3],int &flag)
{
	for (int i = 0; i < 20; i++)
	{
		inside(thePoint,TrianglePoint[i],flag);
		if (flag ==1)
		{
			flag = i+1;
			return;
		}

	}

}
