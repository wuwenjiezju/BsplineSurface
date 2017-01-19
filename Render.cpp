#include"Headfile.h"
#define  GLUT_WHEEL_UP 3           //������ֲ���  
#define  GLUT_WHEEL_DOWN 4
CBSplineSurfaceView surface;

GLfloat _mouseX = 0.0;
GLfloat _mouseY = 0.0;
bool _mouseLeftDown = false;
GLfloat _cameraDistance = -20.0;
GLfloat _cameraAngleX = 0.0;
GLfloat _cameraAngleY = 0.0;

//��������꽻��������ESC�˳����򣬹�������ʵ�ַ�����������ס������ʵ����ת����

GLvoid ProcessNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		//ESC�˳�����
	case 27:
		exit(0);
		break;
	}
}

GLvoid ProcessMousePress(int button, int state, int x, int y)
{
	_mouseX = x;
	_mouseY = y;
	if ( button == GLUT_WHEEL_UP)
	{
		_cameraDistance += 0.5;
		glutPostRedisplay();
	}
	if ( button == GLUT_WHEEL_DOWN)
	{
		_cameraDistance -= 0.5;
		glutPostRedisplay();
	}
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			_mouseLeftDown = true;
		else if (state == GLUT_UP)
			_mouseLeftDown = false;
	}
}

GLvoid ProcessMouseActiveMotion(int x, int y)
{
	if (_mouseLeftDown)
	{
		_cameraAngleY += (x - _mouseX);
		_cameraAngleX += (y - _mouseY);
		_mouseX = x;
		_mouseY = y;
	}
	glutPostRedisplay();
}



GLvoid Initialization()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GL_DEPTH_TEST);
	
	surface.GenerateKnots(1);
	
	surface.solve_bspline(surface.ControlPoint,surface.uknots,surface.vknots);
	

}

GLvoid OnReshape(int w, int h)
{
	// ��ֹ�߶�Ϊ0
	if (h == 0)	h = 1;
	float ratio = 1.0* w / h;
	// ��λ��ͶӰ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// �����ӿڴ�СΪ�������ڴ�С
	glViewport(0, 0, w, h);
	// ������ȷ��ͶӰ����
	gluPerspective(45, ratio, 1, 1000);
	//����������ģ����ͼ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
}


GLvoid OnDisplay()
{
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0, 0.0, _cameraDistance);
	glRotatef(_cameraAngleX, 1.0, 0.0, 0.0);
	glRotatef(_cameraAngleY, 0.0, 1.0, 0.0);
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	glColor3d(1.0,0.0,0.0);


	int i,j;
	for (i=0;i<mpoints+1;i++)
	{
		glBegin(GL_LINE_STRIP);	
		for (j=0;j<npoints+1;j++)
		{
			glVertex3d(surface.ptPts[i][j].x,surface.ptPts[i][j].y,surface.ptPts[i][j].z);

		}
		glEnd();
	}
	for (j=0;j<npoints+1;j++)
	{
		glBegin(GL_LINE_STRIP);	
		for (i=0;i<mpoints+1;i++)
		{
			glVertex3d(surface.ptPts[i][j].x,surface.ptPts[i][j].y,surface.ptPts[i][j].z);

		}
		glEnd();
	}

	glColor3d(0.0,1.0,0.0);
	glLineWidth(2);

	for (i=0;i<M+1;i++)
	{
		glBegin(GL_LINE_STRIP);	
		for (j=0;j<N+1;j++)
		{
			glVertex3f(surface.ControlPoint[i][j].x,surface.ControlPoint[i][j].y,surface.ControlPoint[i][j].z);

		}
		glEnd();
	}
	for (j=0;j<N+1;j++)
	{
		glBegin(GL_LINE_STRIP);	
		for (i=0;i<M+1;i++)
		{
			glVertex3f(surface.ControlPoint[i][j].x,surface.ControlPoint[i][j].y,surface.ControlPoint[i][j].z);

		}
		glEnd();
	}

	glPopMatrix();

	glutSwapBuffers();


}