#include <GL/freeglut_std.h>
#include <stdio.h>    
#include <GL/glut.h>  
#include "visuals.h"

void GoMenu(int value);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1600, 1600);
    glutInitWindowPosition(30, 30);

    glutCreateWindow("Arcanoid");

    Setup();

    glutDisplayFunc(Render);
    glutIdleFunc(Idle);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(processSpecialKeys);

    glutCreateMenu(AutoMoveMenu);
    glutAddMenuEntry("Player", 1);
    glutAddMenuEntry("Auto", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

   // Close();

    return 0;
}

