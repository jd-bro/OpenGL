#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

struct color{
	GLfloat r,g,b,a;
};
struct color c;

void readInput()
{
	FILE *fptr = fopen("input.txt", "r");
	if(fptr)
	{

	fscanf(fptr, "%f %f %f %f" , &(c.r), &(c.g),  &(c.b),  &(c.a));
	fclose(fptr);
	}
}


void renderFunction()
{
	glClearColor(c.r, c.g, c.b, c.a);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	readInput();
	glutCreateWindow("OpenGL - First window demo");
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	return 0;
}