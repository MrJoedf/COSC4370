/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

//run script: ./script.sh

//10 teapots in a circle. 360 degrees in circle, 10 teapots = 36 degrees per teapot
//Approach this like points in a circle
//Place teapots for each point


//Reference: https://community.khronos.org/t/rotating-objects-in-a-double-orbit/70704/2
void problem1() {
  //360 degrees with i+=36 for the 36 degrees for teapot
  for (int i = 0; i < 360; i+=36) {
    
    //push the matrix so that the arrangement is saved and ordered, instead of all over the place
      glPushMatrix();  
  		glRotatef(i, 0, 0, 1); //using z produces the image somehow

    //x is used here to give space between teapots, so it won't be a blob
  		glTranslatef (1, 0, 0); 

    //place the teapot
  		glutSolidTeapot(0.2); 
  	  glPopMatrix();
	}
    
}

void problem2() {
  //IDEA: Create the rising steps then fill in the space beneath
  
  //first cube position
  glTranslatef(-1.4, -0.2, 0); 

  //create the initial incline of the cubes
  for(int i=0; i<15; i++){
    glutSolidCube(0.2);
    

    //fill in the steps row by row
    glPushMatrix();
    for(int j=i; j<15; j++){
      glTranslatef(0.2f, 0, 0);
      glutSolidCube(0.2);
    }
    glPopMatrix();
    
    glTranslatef(0.2f, 0.025f+(i/240.0f), 0);
  }
    //glPopMatrix();
}

void problem3() {
    // TODO: Your code here!

  //Start with top teapot and work downwards
  glTranslatef(0, 1.5f, 0);
  glutSolidTeapot(0.2);
  
//create right side diagonal teapots
  for(int i=0; i<5; i++){
    glTranslatef(-0.4, -0.4, 0);
    glutSolidTeapot(0.2);
    glTranslatef(0.8, 0, 0);
    glutSolidTeapot(0.2);
  }

  /*After filling in the side diagonals,
  fill in the rest of the teapots in a typewriter fashion by filling in the rows with for loops*/

  //adjust position to move across bottom row
  glTranslatef(-1.6, 0, 0);
  glutSolidTeapot(0.2);

  //fill in bottom row with teapots
  for(int i=0; i<3; i++){
    glTranslatef(-0.8,0,0);
    glutSolidTeapot(0.2);
  }

  //move to higher row
  glTranslatef(0.4, 0.4, 0);
  glutSolidTeapot(0.2);
  for(int i=0; i<3; i++){
    glTranslatef(0.8, 0, 0);
    glutSolidTeapot(0.2);
  }

  //move to higher row, positioned after last placement in previous row
  glTranslatef(-1.2, 0.4, 0);
  glutSolidTeapot(0.2);
  for(int i=0; i<2; i++){
    glTranslatef(-0.8, 0, 0);
    glutSolidTeapot(0.2);
    glTranslatef(1.2, 0.4, 0);
  }
}

void problem4() {
    // TODO: Your code here!
  glTranslatef(-3, 0, 0);
  //sine wave of cubes with teapots on top
  //initial cube matrix
  
  
  //creating the sine wave
    for(int i=0; i<16; i++){
      glPushMatrix();
        glTranslatef(i/3.0f, sin(i), 0);
        glutSolidCube(0.33);

        //nested push matrix for teapots on top
        glPushMatrix();
          glTranslatef(0, 0.3, 0);
          glScalef(i*0.075f, i*0.25f, 1);
          glutSolidTeapot(0.15);

        //pop the matrix
         glPopMatrix();
  
    }

  //finally, pop the cube matrix
      glPopMatrix();

  //render the 2d triangles by feeding in coordinates
  glBegin(GL_TRIANGLES);
     glVertex2f(1.0f, 0.0f);
     glVertex2f(1.4f, 1.4f); 
     glVertex2f(2.0f, 0.0f); 
  glEnd();
  


}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
