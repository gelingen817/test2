#include "Afxwin.h"

class MorphClass
{
	
public:
	double Solution[20][6];  //20个三角形每个三角形对应参数求解时 有6个参数

	CPoint TrianglePoint[20][3];  //20个三角形每个3个顶点

	int flag;  //当前点在哪个三角形内，若在2号的内部，flag=2 

public:
	void GetSolution(double theSolution[6],CPoint fpoint1,CPoint fpoint2,CPoint fpoint3,
							                       CPoint fpoint11,CPoint fpoint22,CPoint fpoint33);
	void JudgePointInTriangle(CPoint thePoint,CPoint TrianglePoint[20][3],int &flag);
	void inside(CPoint p,CPoint Tri[3],int &flag);
	double area(CPoint p1,CPoint p2,CPoint p3);
};