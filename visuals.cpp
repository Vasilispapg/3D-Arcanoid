#include <GL/freeglut_std.h>
#include <GL/gl.h>
#define MY_PI 3.141592f

#include <iostream>
#include <GL/glut.h>  
#include <string.h>
#include <time.h>
#include <math.h>

#include "visuals.h"

float z = -500;
// unsigned int tex01, tex02, tex03, tex04, texBlend, texBgMap;

float xrot = 0.f; // X Rotation
float yrot = 0.f; // Y Rotation
float xspeed = 0.2f; // X Rotation Speed
float yspeed = 0.5f; // Y Rotation Speed

int blend = 0; // Blending OFF/ON? ( NEW )
int blend_scene = 0;



void drawCuby(float size){
    glBegin(GL_TRIANGLES);
        //Front
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-size/2.f,-size/2.f,size*3/2.f); //(-, - ,+)
        glVertex3f(size / 2.f, -size / 2.f, size *3/ 2.f); //(+ - +)
        glVertex3f(size / 2.f, size / 2.f, size*3 / 2.f); //(+ + +) 
        glVertex3f(-size/2.f,-size/2.f,size*3/2.f); //(-, - ,+)
        glVertex3f(size / 2.f, size / 2.f, size*3 / 2.f); //(+ + +)
        glVertex3f(-size / 2.f, size / 2.f, size*3 / 2.f);//(- + +)

        //Back
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-size/2.f,-size/2.f,-size*3/2.f); //(-, - ,-)
        glVertex3f(size / 2.f, -size / 2.f, -size*3 / 2.f); //(+ - -)
        glVertex3f(size / 2.f, size / 2.f, -size*3 / 2.f); //(+ + -) 
        glVertex3f(-size/2.f,-size/2.f,-size*3/2.f); //(-, - ,-)
        glVertex3f(size / 2.f, size / 2.f, -size*3 / 2.f); //(+ + -)
        glVertex3f(-size / 2.f, size / 2.f, -size*3 / 2.f);//(- + -) 

        //Top
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-size / 2.f, size / 2.f, size*3 / 2.f);//(- + +)
        glVertex3f(size / 2.f, size / 2.f, size*3 / 2.f); //(+ + +) 
        glVertex3f(size / 2.f, size / 2.f, -size*3 / 2.f); //(+ + -)

        glVertex3f(-size / 2.f, size / 2.f, size*3 / 2.f);//(- + +)
        glVertex3f(size / 2.f, size / 2.f, -size*3 / 2.f);//(+ + -) 
        glVertex3f(-size / 2.f, size / 2.f, -size*3 / 2.f);//(- + -)

        //Bottom
        glVertex3f(-size / 2.f, -size / 2.f, size*3 / 2.f);//(- - +)
        glVertex3f(size / 2.f, -size / 2.f, size*3 / 2.f); //(+ - +) 
        glVertex3f(size / 2.f, -size / 2.f, -size*3 / 2.f); //(+ - -)

        glVertex3f(-size / 2.f, -size / 2.f, size*3 / 2.f);//(- - +)
        glVertex3f(size / 2.f, -size / 2.f, -size*3 / 2.f);//(+ - -) 
        glVertex3f(-size / 2.f, -size / 2.f, -size*3 / 2.f);//(- - -) 

        //Right
        glVertex3f(size / 2.f, size / 2.f, size*3 / 2.f);//(+ + +)
        glVertex3f(size / 2.f, size / 2.f, -size*3 / 2.f); //(+ + -) 
        glVertex3f(size / 2.f, -size / 2.f, -size*3 / 2.f); //(+ - -)

        glVertex3f(size / 2.f, size / 2.f, size*3 / 2.f);//(+ + +)
        glVertex3f(size / 2.f, -size / 2.f, -size*3 / 2.f);//(+ - -) 
        glVertex3f(size / 2.f, -size / 2.f, +size*3 / 2.f);//(+ - +) 

        //Left
        glVertex3f(-size / 2.f, -size / 2.f, -size*3 / 2.f); //(- - -)
        glVertex3f(-size / 2.f, -size / 2.f, size*3 / 2.f);//(- - +)
        glVertex3f(-size / 2.f, size / 2.f, size*3 / 2.f); //(- + +) 
    
        glVertex3f(-size / 2.f, -size / 2.f, -size*3 / 2.f);//(- - -)
        glVertex3f(-size / 2.f, size / 2.f, -size*3 / 2.f);//(- + - ) 
        glVertex3f(-size / 2.f, size / 2.f, size*3 / 2.f);//(- + +) 
        

    glEnd();
}

void drawBall(float size){
    glutSolidSphere(size/2.f, 40, 40);
}

void drawPlayer(float size){
   glBegin(GL_QUADS);
        //front
        glVertex3f(-size/2.f, -size/2.f, size/16.f); //--+
        glVertex3f(size/2.f,-size/2.f, size/16.f);// +-+
        glVertex3f(size/2.f, size/2.f,size/16.f); //+++
        glVertex3f(-size/2.f, size/2.f,size/16.f);//-++

        //back
        glVertex3f(-size/2.f, -size/2.f, -size/16.f); //---
        glVertex3f(size/2.f,-size/2.f, -size/16.f);// +--
        glVertex3f(size/2.f, size/2.f,-size/16.f); //++-
        glVertex3f(-size/2.f, size/2.f,-size/16.f);//-+-

        //up
        glVertex3f(-size/2.f, size/2.f, size/16.f); //-++
        glVertex3f(size/2.f, size/2.f,size/16.f); //+++
        glVertex3f(size/2.f,size/2.f, -size/16.f);// ++-
        glVertex3f(-size/2.f, size/2.f,-size/16.f);//-+-

        //down
        glVertex3f(-size/2.f, -size/2.f, size/16.f); //--+
        glVertex3f(size/2.f, -size/2.f,size/16.f); //+-+
        glVertex3f(size/2.f,-size/2.f, -size/16.f);// +--
        glVertex3f(-size/2.f, -size/2.f,-size/16.f);//---

        //aristera
        glVertex3f(-size/2.f, -size/2.f, size/16.f); //--+
        glVertex3f(-size/2.f, size/2.f,size/16.f); //-++
        glVertex3f(-size/2.f,size/2.f, -size/16.f);// -+-
        glVertex3f(-size/2.f, -size/2.f,-size/16.f);//---

        //dejia
        glVertex3f(size/2.f, -size/2.f, size/16.f); //+-+
        glVertex3f(size/2.f, size/2.f,size/16.f); //+++
        glVertex3f(size/2.f,size/2.f, -size/16.f);// ++-
        glVertex3f(size/2.f, -size/2.f,-size/16.f);//+--


   glEnd();
}


void drawEnemy(float size){

}
float angleX = 0.0f;
float xr = 0, yr = 0;

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, z);

    
    glRotatef(yr, 0, 1, 0);
    glRotatef(xr, 1, 0, 0);
    glColor4f(0.396, 0.572, 0.49,.5); //r g b a
    // drawCuby(80.0f);
    
    glTranslatef(50, 0, 0);
    // drawBall(80.0f);

    glTranslatef(50, 0, 0);
    drawPlayer(80.0f);

    glutSwapBuffers();
}

bool flag=true;

void Idle()
{
    if(flag){
        
        yr++;
        xr++;
    }
       
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'g':
            flag=!flag;
            break;
        case 'w': 
            xr+=2; 
            break;
        case 's':  xr-=2; break;
        case 'a':    yr -= 2.0f; break;
        case 'd':  yr += 2.0f; break;
    }
}

void Setup()
{
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuseLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightPos[] = {0.0f, 0.0f, 3.0f, 0.0f};
    GLfloat lightPos2[] = {30.0f, 30.0f,30.0f, 1.0f};
    

    // glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // BLENDING STUFF
    glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

    glLightfv(GL_LIGHT1, GL_POSITION, lightPos2);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);


    //(01) BLENDING
    glEnable(GL_BLEND);
    //                 incoming      stored //
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void Resize(int w, int h)
{
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (float) w / (float) h, 0.1, 10000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


