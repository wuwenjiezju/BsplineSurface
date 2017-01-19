
const int M=3;//˫����bspline����
const int N=3;
const int p=3;
const int q=3;
const int mpoints=40;
const int npoints=40;//��(mpoints+1)*(npoints+1)�������ƽ�����


class Point3D//��ά�ռ��Point3D��
{
public:
	double x,y,z;
	Point3D(){x=0;y=0;z=0;};
	Point3D(double _x,double _y,double _z){x=_x;y=_y;z=_z;};
	Point3D(double s){x=s;y=s;z=s;};
	//�����Ĳ���
	Point3D operator =(Point3D p1){x=p1.x;y=p1.y;z=p1.z;return (*this);};
	Point3D operator +=(Point3D p1){x+=p1.x;y+=p1.y;z+=p1.z;return(*this);};
	Point3D operator -=(Point3D p1){x-=p1.x;y-=p1.y;z-=p1.z;return(*this);};
	Point3D operator *=(double s){x*=s;y*=s;z*=s;return(*this);};
	Point3D operator /=(double s){x/=s;y/=s;z/=s;return(*this);};
	Point3D operator +(Point3D p1){Point3D t;t.x=x+p1.x;t.y=y+p1.y;t.z=z+p1.z;return(t);};
	Point3D operator -(Point3D p1){Point3D t;t.x=x-p1.x;t.y=y-p1.y;t.z=z-p1.z;return(t);};
	Point3D operator *(double s){Point3D t;t.x=x*s;t.y=y*s;t.z=z*s;return(t);};
	Point3D operator /(double s){Point3D t;t.x=x/s;t.y=y/s;t.z=z/s;return(t);};
	friend Point3D operator *(double s,Point3D p1){Point3D t;t.x=p1.x*s;t.y=p1.y*s;t.z=p1.z*s;return(t);};
};

class CBSplineSurfaceView 
{
	public:
	 CBSplineSurfaceView();


     Point3D ControlPoint[M+1][N+1];//����ǵ����Ϣ����
	 double *uknots;
	 double *vknots;
	 Point3D ptPts[mpoints+1][npoints+1];

	 void solve_bspline(Point3D P[][N+1],double uknot[],double vknot[]);//����B���������ϵĸ�������p(u,v)
	

	 Point3D BSpline(Point3D P[][N+1],double uknot[],double vknot[],int unum,int vnum,double u,double v);//����ֱ�ӻ�ͼ��
	 double Base(int i,int k,double knot[],int num,double u);//����B����������
	 void  GenerateKnots(int type);


	 virtual ~CBSplineSurfaceView();
};
