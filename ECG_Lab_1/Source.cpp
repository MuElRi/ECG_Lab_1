#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
using namespace glm;

GLuint VBO;

void RenderSceneCB() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.64f, 0.0f);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POLYGON, 0, 6);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01");
	glutDisplayFunc(RenderSceneCB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	vec3 Vertices[6]{
		{-0.25f, -0.5f, 0.0f},
		{0.25f, -0.5f, 0.0f },
		{0.5f, 0.0f, 0.0f},
		{0.25f, 0.5f, 0.0f},
		{-0.25f, 0.5f, 0.0f},
		{-0.5f, 0.0f, 0.0f}
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glutMainLoop();
}
//