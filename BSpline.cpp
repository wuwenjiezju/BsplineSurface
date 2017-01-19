#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include "BSpline.h"




CBSplineSurfaceView::CBSplineSurfaceView()
{
	ControlPoint[0][0]=Point3D(-3.5, -2.5, 6.0);
	ControlPoint[0][1]=Point3D(1.0, -2.5, 6.0);
	ControlPoint[0][2]=Point3D(0.0, 5.0, 6.0);
	ControlPoint[0][3]=Point3D(4.5, 1.5, 6.0);

	ControlPoint[1][0]=Point3D(-4.5, -3.5, 3.0);
	ControlPoint[1][1]=Point3D(-3.0, 2.0, 3.0);
	ControlPoint[1][2]=Point3D(0.0, 4.0, 3.0);
	ControlPoint[1][3]=Point3D(3.0, 2.0, 3.0);

	ControlPoint[2][0]=Point3D(-3.5, -3.5, 0.0);
	ControlPoint[2][1]=Point3D(-2.0, 0.0, 0.0);
	ControlPoint[2][2]=Point3D(0.0,-1.5, 0.0);
	ControlPoint[2][3]=Point3D(2.0, 0.0, 0.0);
	
	ControlPoint[3][0]=Point3D(-4.0, -4.0,-3.0);
	ControlPoint[3][1]=Point3D(-3.0, 0.0,-3.0);
	ControlPoint[3][2]=Point3D(0.0, 2.5,-3.0);
	ControlPoint[3][3]=Point3D(3.0, 0.0,-3.0);
	

	uknots=NULL;
	vknots=NULL;

	

}
CBSplineSurfaceView ::~CBSplineSurfaceView()
{
delete []uknots;
delete []vknots;
}



//����B�������ߵĶ��壬����B���������ϸ��������ֵ��PΪ���Ƶ�
//���Ƶ�P�ĸ���Ϊn+1,�������knotΪB�������߽ڵ��������ڵ������ĸ���Ϊnum

Point3D  CBSplineSurfaceView::BSpline(Point3D P[][N+1],double uknot[],double vknot[],int unum,int vnum,double u,double v)
{
	Point3D ret=Point3D(0,0,0);
	double temp1,temp2;
	for(int i=0;i<=M;i++)
	{
		temp1=Base(i,unum-M-1,uknot,unum,u);
			for(int j=0;j<=N;j++)
				{
		
				temp2=Base(j,vnum-N-1,vknot,vnum,v);
				
				ret+=P[i][j]*temp1*temp2;
			}
	}
	return ret;

}
//CP���Ƶ㣬u�ڵ�����Ϊm+p+2;v�ڵ�����Ϊn+q+2��
//�������de boor�㷨���ɵ�B���������ϵ���ɢ������pts
//�������ɢ�����Ϊ(mpoints+1)*(npoints+1)
void  CBSplineSurfaceView::solve_bspline(Point3D P[][N+1],double uknot[],double vknot[])
{

	double u,v,delt1,delt2;
	int i1,i2;
	delt1=(uknot[M+1]-uknot[p])/(double)mpoints;//��������Ϊ[u_p,u_(m+1)],���ֳ�mpoints�ȷ�
	delt2=(vknot[N+1]-vknot[q])/(double)npoints;//��������Ϊ[v_q,v_(n+1)],���ֳ�npoints�ȷ�
	u=uknot[p];
	
	
		for(i1=0;i1<=mpoints;i1++,u+=delt1)
		{
			v=vknot[q];
			for (i2=0;i2<=npoints;i2++,v+=delt2)
			{
				ptPts[i1][i2]=BSpline(P,uknot,vknot,M+p+2,N+q+2,u,v);
			}
		}

}
//k�������
double CBSplineSurfaceView::Base(int i,int k,double knot[],int num,double u)//����B����������
{
	double temp1=0,temp2=0;
	if(k==1)
	{
		
			if ((u>=knot[i])&&(u<=knot[i+1]))
				return 1; 
			else
				return 0;
		
	}
	else if(k>1)
	{
		temp1=temp2=0;
		if(knot[i+k-1]!=knot[i])
		{
			temp1=Base(i,k-1,knot,num,u);
			temp1=(u-knot[i])*temp1/(knot[i+k-1]-knot[i]);

		}
		if(knot[i+k]!=knot[i+1])
		{
			temp2=Base(i+1,k-1,knot,num,u);
			temp2=(knot[i+k]-u)*temp2/(knot[i+k]-knot[i+1]);
		}
		return temp1+temp2;

	}
	return 0;
}
void CBSplineSurfaceView::GenerateKnots(int type)
{
	int i,j,ulen=M+p+2,vlen=N+q+2;
	uknots=new double[ulen];
	vknots=new double[vlen];
	switch (type)
	{
	case 0:
	
			for(i=0;i<ulen;i++)
			uknots[i]=i;
		for(j=0;j<vlen;j++)
			vknots[j]=j;
		
		break;
	case 1:
		
			for(i=0;i<ulen;i++)
			if(i<=p)
				uknots[i]=0;
			else if(i>=M+1)
				uknots[i]=M-p+1;
			else
				uknots[i]=i-p;
		   for(j=0;j<vlen;j++)
				if(j<=q)
					vknots[j]=0;
				else if(j>=N+1)
					vknots[j]=N-q+1;
				else
					vknots[j]=j-q;
		
				break;
	}

}
