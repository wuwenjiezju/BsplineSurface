#include "Headfile.h"


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("sancibiyangtiao");

	Initialization();
	
	
	//���õ�ǰ���ڹ����ʽ
	glutSetCursor(GLUT_CURSOR_DESTROY);


	glutDisplayFunc(OnDisplay);
	
	glutKeyboardFunc(ProcessNormalKeys);	//ע����̲���

	glutMouseFunc(ProcessMousePress);		//ע����갴��
	
	glutMotionFunc(ProcessMouseActiveMotion);	//ע������϶�
	
	glutReshapeFunc(OnReshape);					//�ظ�����
	
	glutMainLoop();
	return 0;
}
