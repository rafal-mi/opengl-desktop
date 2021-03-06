/*
    Copyright 2010 Etay Meiri
*/

#include <GL/freeglut.h>
#include <stdio.h>


static void renderSceneCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

    int width = 1920;
    int height = 1080;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("Tutorial 01");
    printf("window id: %d\n", win);

    GLclampf Red = 0.0f, Green = 0.5f, Blue = 0.5f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    glutDisplayFunc(renderSceneCallback);

    glutMainLoop();

    return 0;
}
