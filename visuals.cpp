#include <GL/freeglut_std.h>
#include <GL/gl.h>
#define MY_PI 3.141592f

#include <iostream>
#include <GL/glut.h>  
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */

#include "visuals.h"

float z = -500;

int blend = 0; // Blending OFF/ON? ( NEW )
int blend_scene = 0;

float angleX = 0.0f;
float xr = 0, yr = 0;
float mpros_pisw_kamera=0;
float v=40;


void drawSpace(float size){
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

void drawCube(float size){
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

float r[16][4];
float g[16][4];
float b[16][4];
bool flagcolor=true;
void findColors(){
    if(flagcolor){
        srand((unsigned)time(NULL));
            for(int i=0;i<=16;i++){
                for(int j=0;j<=4;j++){
                    r[i][j] = (float) rand()/RAND_MAX;
                    g[i][j] =(float) rand()/RAND_MAX;
                    b[i][j] = (float) rand()/RAND_MAX;
                }
            }
    }
    flagcolor=false;
    //gia na min jana allazei apo tin idle
}

void drawEnemy(float size){
    int sizey=4;
    int sizex=sizey*sizey;
    glRotatef(45, 0, 1, 0); //για να γυρισουν πλαγια
    findColors();//gia na orisei ta xrwmata stoys kivous
    for(int j=0;j<=sizey;j++){

        glPushMatrix(); //για τον αξονα z

        for(int i =0;i<=sizex;i++){

            glPushMatrix(); // για τον αξονα y

            if(i){//an einai 0 na min sxediasi
                glColor3f(r[i][j],g[i][j],b[i][j]);
                drawCube(size);
                glTranslatef(size+7, 0, 0);
            }

            if(!(i%sizey)){ //για να εχω 3 σε καθε γραμμη
                glPopMatrix();//αξονας y
                glTranslatef(0, size+7, 0); //μολις βρω το 3ο τοτε ξανα παω στην θεση χ=0, και το ανεβαζω στον αξονα y κατα size+7 
            }

            if(i==sizex){
                glPopMatrix(); //αξονας z
                glTranslatef(0, 0, size/2);
            }
        }
        
    }
}

float ball=0;

void DrawEverything(){
//kwdikas gia setup
    glPushMatrix();
        glTranslatef(0, 0, mpros_pisw_kamera);
        glRotatef(yr, 0, 1, 0);
        glRotatef(xr, 1, 0, 0);

        glPushMatrix();
            glTranslatef(-250, -90, -310); //gia na mpei mes to koyti
            //to - ston x se paei aristera
            //οσο πιο μικρο y τοσο πιο κατω
            drawEnemy(30.0f);
        glPopMatrix();

        //paiktis
        glPushMatrix();
            glRotatef(45, 0, 1, 0);
            glTranslatef(100, 0, 60);
            glColor3f(0, 0.2, 0.7);
            drawCube(50.0f);
        glPopMatrix();

        //ball
        glPushMatrix();
            glRotatef(45, 0, 1, 0);
            glTranslatef(0, 0, ball);
            glTranslatef(100, 0, -40);
            // glColor3f((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX);
            drawBall(30.0f);
        glPopMatrix();

        //xwros paixnidiou
        glPushMatrix();
            glRotatef(45, 0, 1, 0);
            glTranslatef(100, 0, -175);
            glColor4f(0.396, 0.572, 0.49,.5); //r g b a
            drawSpace(180.0f);
        glPopMatrix();
        
    glPopMatrix();
}



void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, z);

    DrawEverything();
    glutSwapBuffers();
}

void Idle()
{
    float g = 10;
    float dt = 0.01;
    
    if(ball>-300){
        ball=ball+v*dt;
    }
    else if(ball<1){ //to ball=0 mas dinei 0.688
        ball=ball-v*dt;
    }

    // ball=ball+v*dt;

    // printf("ball=%f v=%f\n",ball,v);
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': xr+=2; break;
        case 's':  xr-=2; break;
        case 'a':    yr -= 2.0f; break;
        case 'd':  yr += 2.0f; break;
        case 'c': mpros_pisw_kamera +=10.0f;break;
        case 'v': mpros_pisw_kamera -=10.0f;break;
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


