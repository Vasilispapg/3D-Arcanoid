#include <GL/freeglut_std.h>
#include <GL/gl.h>

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>   
#include <string>

#include "visuals.h"

#include "Game.cpp"

float distances = -700;

int blend = 0; // Blending OFF/ON? ( NEW )
int blend_scene = 0;

float angleX = 0.0f;
float xr = 0, yr = 0;
float mpros_pisw_kamera = 0;
float panw_katw_kamera=0;
Game game;

void AutoMoveMenu(int value){

    switch(value){
        case 1:
            game.auto_is_on=false;
        break;
        case 2:
            game.auto_is_on=true;
        break;
    }
}

void drawSpace(float size) {
  glBegin(GL_TRIANGLES);
  // Front
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-size / 2.f, -size / 2.f, size * 3 / 2.f); //(-, - ,+)
  glVertex3f(size / 2.f, -size / 2.f, size * 3 / 2.f);  //(+ - +)
  glVertex3f(size / 2.f, size / 2.f, size * 3 / 2.f);   //(+ + +)
  glVertex3f(-size / 2.f, -size / 2.f, size * 3 / 2.f); //(-, - ,+)
  glVertex3f(size / 2.f, size / 2.f, size * 3 / 2.f);   //(+ + +)
  glVertex3f(-size / 2.f, size / 2.f, size * 3 / 2.f);  //(- + +)

  // Back
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-size / 2.f, -size / 2.f, -size * 3 / 2.f); //(-, - ,-)
  glVertex3f(size / 2.f, -size / 2.f, -size * 3 / 2.f);  //(+ - -)
  glVertex3f(size / 2.f, size / 2.f, -size * 3 / 2.f);   //(+ + -)
  glVertex3f(-size / 2.f, -size / 2.f, -size * 3 / 2.f); //(-, - ,-)
  glVertex3f(size / 2.f, size / 2.f, -size * 3 / 2.f);   //(+ + -)
  glVertex3f(-size / 2.f, size / 2.f, -size * 3 / 2.f);  //(- + -)

  // Top
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-size / 2.f, size / 2.f, size * 3 / 2.f); //(- + +)
  glVertex3f(size / 2.f, size / 2.f, size * 3 / 2.f);  //(+ + +)
  glVertex3f(size / 2.f, size / 2.f, -size * 3 / 2.f); //(+ + -)

  glVertex3f(-size / 2.f, size / 2.f, size * 3 / 2.f);  //(- + +)
  glVertex3f(size / 2.f, size / 2.f, -size * 3 / 2.f);  //(+ + -)
  glVertex3f(-size / 2.f, size / 2.f, -size * 3 / 2.f); //(- + -)

  // Bottom
  glVertex3f(-size / 2.f, -size / 2.f, size * 3 / 2.f); //(- - +)
  glVertex3f(size / 2.f, -size / 2.f, size * 3 / 2.f);  //(+ - +)
  glVertex3f(size / 2.f, -size / 2.f, -size * 3 / 2.f); //(+ - -)

  glVertex3f(-size / 2.f, -size / 2.f, size * 3 / 2.f);  //(- - +)
  glVertex3f(size / 2.f, -size / 2.f, -size * 3 / 2.f);  //(+ - -)
  glVertex3f(-size / 2.f, -size / 2.f, -size * 3 / 2.f); //(- - -)

  // Right
  glVertex3f(size / 2.f, size / 2.f, size * 3 / 2.f);   //(+ + +)
  glVertex3f(size / 2.f, size / 2.f, -size * 3 / 2.f);  //(+ + -)
  glVertex3f(size / 2.f, -size / 2.f, -size * 3 / 2.f); //(+ - -)

  glVertex3f(size / 2.f, size / 2.f, size * 3 / 2.f);   //(+ + +)
  glVertex3f(size / 2.f, -size / 2.f, -size * 3 / 2.f); //(+ - -)
  glVertex3f(size / 2.f, -size / 2.f, +size * 3 / 2.f); //(+ - +)

  // Left
  glVertex3f(-size / 2.f, -size / 2.f, -size * 3 / 2.f); //(- - -)
  glVertex3f(-size / 2.f, -size / 2.f, size * 3 / 2.f);  //(- - +)
  glVertex3f(-size / 2.f, size / 2.f, size * 3 / 2.f);   //(- + +)

  glVertex3f(-size / 2.f, -size / 2.f, -size * 3 / 2.f); //(- - -)
  glVertex3f(-size / 2.f, size / 2.f, -size * 3 / 2.f);  //(- + - )
  glVertex3f(-size / 2.f, size / 2.f, size * 3 / 2.f);   //(- + +)

  glEnd();
}

void drawBall(float size) {
  glutSolidSphere(size / 2.f, 40, 40);
  game.r_ball = size / 2.f;
}

void drawCube(float size) {
  glBegin(GL_QUADS);

  // front
  glVertex3f(-size / 2.f, -size / 2.f, size / 16.f); //--+
  glVertex3f(size / 2.f, -size / 2.f, size / 16.f);  // +-+
  glVertex3f(size / 2.f, size / 2.f, size / 16.f);   //+++
  glVertex3f(-size / 2.f, size / 2.f, size / 16.f);  //-++

  // back
  glVertex3f(-size / 2.f, -size / 2.f, -size / 16.f); //---
  glVertex3f(size / 2.f, -size / 2.f, -size / 16.f);  // +--
  glVertex3f(size / 2.f, size / 2.f, -size / 16.f);   //++-
  glVertex3f(-size / 2.f, size / 2.f, -size / 16.f);  //-+-

  // up
  glVertex3f(-size / 2.f, size / 2.f, size / 16.f);  //-++
  glVertex3f(size / 2.f, size / 2.f, size / 16.f);   //+++
  glVertex3f(size / 2.f, size / 2.f, -size / 16.f);  // ++-
  glVertex3f(-size / 2.f, size / 2.f, -size / 16.f); //-+-

  // down
  glVertex3f(-size / 2.f, -size / 2.f, size / 16.f);  //--+
  glVertex3f(size / 2.f, -size / 2.f, size / 16.f);   //+-+
  glVertex3f(size / 2.f, -size / 2.f, -size / 16.f);  // +--
  glVertex3f(-size / 2.f, -size / 2.f, -size / 16.f); //---

  // aristera
  glVertex3f(-size / 2.f, -size / 2.f, size / 16.f);  //--+
  glVertex3f(-size / 2.f, size / 2.f, size / 16.f);   //-++
  glVertex3f(-size / 2.f, size / 2.f, -size / 16.f);  // -+-
  glVertex3f(-size / 2.f, -size / 2.f, -size / 16.f); //---

  // dejia
  glVertex3f(size / 2.f, -size / 2.f, size / 16.f);  //+-+
  glVertex3f(size / 2.f, size / 2.f, size / 16.f);   //+++
  glVertex3f(size / 2.f, size / 2.f, -size / 16.f);  // ++-
  glVertex3f(size / 2.f, -size / 2.f, -size / 16.f); //+--

  glEnd();
}

void keimeno(const char *str)
{
    glPushMatrix();
 glScalef(.3, .3, 1);
  glColor3f(1,1,1);
    for (unsigned int i = 0; i < strlen(str); i++)  {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
    }
    
    glPopMatrix();

}


void drawEnemy(float size) {
  int walls = 4;
  int num_of_enemies = 16;

  float find_pos_x = 0;
  float find_pos_y = 0;
  float find_pos_z = 0;

  game.findColors(); // gia na orisei ta xrwmata stoys kivous
  for (int j = 0; j < walls; j++) {

    glPushMatrix(); //για τον αξονα z

    for (int i = 0; i < num_of_enemies; i++) {
      glPushMatrix(); // για τον αξονα y

        glColor3f(game.r[i][j], game.g[i][j], game.b[i][j]);
        if (game.enemies[i][j].flag){
          drawCube(size);
        }
        
        glTranslatef(size + 7, 0, 0);
        find_pos_x += size+7;
        
        if (game.do_once) {
          game.enemies[i][j].x = find_pos_x-95;
          game.enemies[i][j].y = find_pos_y-55;
          game.enemies[i][j].z = find_pos_z-400;
        }

      if (i==3 || i==7 || i==11 || i==15) { //για να εχω 4 σε καθε γραμμη
        glPopMatrix();    //αξονας y
        glTranslatef(0, size + 7,0); 
        //μολις βρω το 3ο/7o/11o/15o τοτε ξανα παω στην θεση χ=0, και το
        //ανεβαζω στον αξονα y κατα size+7
        find_pos_y += size + 7;
        find_pos_x=0; //ξανα οριοθετω τον χ
      }

      if (i == 15) {
        glPopMatrix(); //αξονας z
        glTranslatef(0, 0, -size / 2);
        find_pos_z -= size / 2;
        find_pos_x=0;
        find_pos_y=0;
      }
    }
  }
}

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z1=5.0f;

void DrawEverything() {

  glRotatef(-20, 0, 1, 0);

  glPushMatrix();
    gluLookAt(x, 1.0f, z1,
			x+lx, 1.0f,  z1+lz,
			0.0f, 1.0f,  0.0f);

  glTranslatef(0, panw_katw_kamera, mpros_pisw_kamera);

  glRotatef(yr, 0, 1, 0);
  glRotatef(xr, 1, 0, 0);

  glPushMatrix();
  glTranslatef(40, -60, -390); // gia na mpei mes to koyti
  // to - ston x se paei aristera
  //οσο πιο μικρο y τοσο πιο κατω

  float size_enemy = 30.0f;
  drawEnemy(size_enemy);
  if (game.do_once){
        game.sxdia2_enemy = size_enemy / 2;
        game.sydia2_enemy = size_enemy / 2;
        game.szdia2_enemy = size_enemy / 16;
  }
  glPopMatrix();

  // paiktis
  glPushMatrix();
  glTranslatef(game.player.x, game.player.y, 0);
  glTranslatef(100, 0, 60);
  glColor3f(0, 0.2, 0.7);
  float size_player = 50.0f;
  drawCube(size_player);
  game.sxdia2_player = size_player / 2;
  game.szdia2_player = size_player / 16;
  game.sydia2_player = size_player / 2;
  glPopMatrix();

  // ball
  glPushMatrix();
  glTranslatef(game.ball.x, game.ball.y, game.ball.z);
  glTranslatef(100, 0, 40);
  glColor3f((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float)
  rand()/RAND_MAX);
  drawBall(30.0f);
  glPopMatrix();

  // xwros paixnidiou
  glPushMatrix();
  glTranslatef(100, 0, -175);
  glColor4f(0.396, 0.572, 0.49, .5); // r g b a
  drawSpace(180.0f);
  glPopMatrix();

  glPushMatrix();
  
  //SCORE
  string str = "Score "+to_string(game.score);
  const char *cstr = str.c_str();
  glTranslatef(0,150,-500);
  keimeno(cstr);

  //ZWES
  glTranslatef(0,50,0);
  str = "Lifes: "+to_string(game.life);
  cstr = str.c_str();
  keimeno(cstr);

  //ENEMIES
  glTranslatef(0,50,0);
  str = "Enemies: "+to_string(game.winning_counter);
  cstr = str.c_str();
  keimeno(cstr);
  glPopMatrix();

  glPopMatrix();
}

void drawLose(){
  glPushMatrix();
    glRotatef(-45,  0, 1, 0);
    glTranslatef(-150, 0, 0);
    string str = "You lost!";
    const char * cstr = str.c_str();
    keimeno(cstr);
  glPopMatrix();
}

void drawWin(){
  
  glPushMatrix();
    glRotatef(-45,  0, 1, 0);
    glTranslatef(-100, 0, 0);
    string str = "You won!";
    const char * cstr = str.c_str();
    keimeno(cstr);
  glPopMatrix();
}

void Render() {
  
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, distances);

  glRotatef(45, 0, 1, 0);
  if(game.life>0 && game.winning_counter!=0){
    DrawEverything();
  }
  else{
    drawLose();
  }
  if(game.winning_counter==0){
    drawWin();
  }
  
  game.do_once = false;
  glutSwapBuffers();
}


void Idle() {
  game.moveBall();
  game.boundPlayer();
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {
  float fraction = 0.1f;
  switch (key) {
  case 'w':
    xr += 2;
    break;
  case 's':
    xr -= 2;
    break;
  case 'a':
    yr -= 2.0f;
    break;
  case 'd':
    yr += 2.0f;
    break;
  case 'c':
    mpros_pisw_kamera += 10.0f;
    break;
  case 'z':
      x += lx * fraction+10;
			distances += lz * fraction+10;
      break;
  case 'x' :
			x -= lx * fraction+10;
			distances -= lz * fraction+10;
			break;
  case 'v':
    mpros_pisw_kamera -= 10.0f;
    break;
  case '6':
    game.player.x += 15;
    break;
  case '8':
    game.player.y += 15;
    break;
  case '4':
    game.player.x -= 15;
    break;
  case '5':
    game.player.y -= 15;
    break;
  }
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.03f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.03f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
      panw_katw_kamera-=10;
			break;
		case GLUT_KEY_DOWN :
			panw_katw_kamera+=10;
			break;
	}
}

void Setup() {
  GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat diffuseLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
  GLfloat lightPos[] = {0.0f, 0.0f, 3.0f, 0.0f};
  GLfloat lightPos2[] = {30.0f, 30.0f, 30.0f, 1.0f};


  glFrontFace(GL_CCW);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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

void Resize(int w, int h) {
  if (h == 0)
    h = 1;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (float)w / (float)h, 0.1, 10000.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
