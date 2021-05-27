#include <stdio.h>    
#include <GL/glut.h>  

#include "visuals.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(30, 30);

    glutCreateWindow("Texturing Examples");

    Setup();

    glutDisplayFunc(Render);
    glutIdleFunc(Idle);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();

   // Close();

    return 0;
}
