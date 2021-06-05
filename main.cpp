#include <stdio.h>    
#include <GL/glut.h>  

#include "visuals.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1600, 1600);
    glutInitWindowPosition(30, 30);

    glutCreateWindow("Texturing Examples");

    Setup();

    glutDisplayFunc(Render);
    glutIdleFunc(Idle);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(processSpecialKeys);

    glutMainLoop();


   // Close();

    return 0;
}
