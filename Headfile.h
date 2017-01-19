
#include <iostream>
#include"BSpline.h"
#include <GLUT/GLUT.h>
#include <GLUT/glut.h>

//◊‘∂®“Â∫Ø ˝…˘√˜
GLvoid SetupLights();


//ª˘±æªÿµ˜∫Ø ˝…˘√˜
GLvoid Initialization();								//≥ı ºªØ
GLvoid OnDisplay();										//œ‘ æªÿµ˜∫Ø ˝
GLvoid OnReshape(int w, int h);							//¥∞ø⁄¥Û–°∏ƒ±‰ªÿµ˜∫Ø ˝

GLvoid ProcessNormalKeys(unsigned char key, int x, int y);			//º¸≈Ã≤Ÿ◊˜
GLvoid ProcessMousePress(int button, int state, int x, int y);		// Û±Í≤Ÿ◊˜
GLvoid ProcessMouseActiveMotion(int x, int y);						// Û±ÍÕœ∂Ø≤Ÿ◊˜
