#include "Headfile.h"


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("sancibiyangtiao");

	Initialization();
	
	
	//设置当前窗口光标样式
	glutSetCursor(GLUT_CURSOR_DESTROY);


	glutDisplayFunc(OnDisplay);
	
	glutKeyboardFunc(ProcessNormalKeys);	//注册键盘操作

	glutMouseFunc(ProcessMousePress);		//注册鼠标按键
	
	glutMotionFunc(ProcessMouseActiveMotion);	//注册鼠标拖动
	
	glutReshapeFunc(OnReshape);					//重复绘制
	
	glutMainLoop();
	return 0;
}
