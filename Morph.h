#include "Afxwin.h"

class MorphClass
{
	
public:
	double Solution[20][6];  //20��������ÿ�������ζ�Ӧ�������ʱ ��6������

	CPoint TrianglePoint[20][3];  //20��������ÿ��3������

	int flag;  //��ǰ�����ĸ��������ڣ�����2�ŵ��ڲ���flag=2 

public:
	void GetSolution(double theSolution[6],CPoint fpoint1,CPoint fpoint2,CPoint fpoint3,
							                       CPoint fpoint11,CPoint fpoint22,CPoint fpoint33);
	void JudgePointInTriangle(CPoint thePoint,CPoint TrianglePoint[20][3],int &flag);
	void inside(CPoint p,CPoint Tri[3],int &flag);
	double area(CPoint p1,CPoint p2,CPoint p3);
};