#include "Ball.cpp"
#include "Enemy.cpp"
#include "Player.cpp"
#include <time.h>

class Game {

public:
  
  static const int num_of_enemies=16;
  static const int num_of_walls=4;
  Enemy enemies[num_of_enemies][num_of_walls];
  Ball ball;
  Player player;

  float r[num_of_enemies][num_of_walls],g[num_of_enemies][num_of_walls],b[num_of_enemies][num_of_walls];

  float r_ball;
  float sxdia2_player,sydia2_player,szdia2_player;
  float sxdia2_enemy,sydia2_enemy,szdia2_enemy;;

  float change_dir_x = 1;
  float change_dir_y = 1;
  float change_dir_z = 1;

  int score=0;
  int life=3;
  int winning_counter=num_of_walls*num_of_enemies;

  bool do_once = true;
  bool flagcolor = true;
  bool auto_is_on=false;

  void boundPlayer() {
    if (player.x > 60)
      player.x = 60;
    if (player.y > 60)
      player.y = 60;
    if (player.x < -60)
      player.x = -60;
    if (player.y < -60)
      player.y = -60;
  }


  void hitThePlayer() {
    if ((abs(player.x - ball.x) < r_ball + sxdia2_player) &&
        (abs(player.y - ball.y) < r_ball + sydia2_player) &&
        (abs(player.z - ball.z) < (r_ball + szdia2_player) / 10)) {
        change_dir_z *= -1; //allagi kateytinsis

      if(player.x<ball.x && player.y<ball.y){ //gia tis gwnies
        //dejia gwnia
        ball.vx=0.4;
        change_dir_x=1;
      }
      else if(player.x>ball.x && player.y>ball.y){
        // aristeri gwnia
        //prepei na fygei aristera
        ball.vx=0.4;
        change_dir_x=-1;
      }
      else if(player.y>ball.y){
        //i mpala einai katw
        change_dir_y=-1;
        ball.vy=0.4;
      }
      else if(player.y<ball.y){
        //i mpala einai panw
        //prepei na fygei panw
        change_dir_y=1;
        ball.vy=0.4;

      }
      ball.z -= 0.3; //gia na min kollaei metajy ton if
      // cout << "Xtypisa player morti" << endl;
    }
  }

  void hitTheEnemy() {
    if (ball.z < -380) {
      for (auto &enemy : enemies) 
      {
        for (auto &e : enemy) 
        {
          
          if (e.flag && (abs(e.x - ball.x) < r_ball + sxdia2_enemy) &&
              (abs(e.y - ball.y) < r_ball + sydia2_enemy) &&
              (abs(e.z - ball.z) < (r_ball + szdia2_enemy) /10)) 
          {
            change_dir_z *= -1; //αλλαζει κατευθυνση

            winning_counter--; //afairw enan antipalo gia na jerw oti kerdisa

            ball.vx=0.1; //ξανα προσαρμοζω τις ταχυτητες
            ball.vy=0.1; //ξανα προσαρμοζω τις ταχυτητες

            score+=250;

            e.flag = false;//για να μην σχεδιαζεται ξανα

            // cout << "Xtypisa morti enemy" << endl;
            ball.z += 1.3;
          }
        }
      }
    }
  }

  void boundBall() {
    if (ball.x > 75) {
      ball.x = 75;
      change_dir_x *= -1;
    }

    if (ball.y > 75) {
      ball.y = 75;
      change_dir_y *= -1;
    }

    if (ball.x < -75) {
      ball.x = -75;
      change_dir_x *= -1;
    }
    if (ball.y < -75) {
      ball.y = -75;
      change_dir_y *= -1;
    }
    if (ball.z < -450) {
      ball.z = -450;
      change_dir_z *= -1;
      //opote gyranei prws tin mpala tote na xamilwnei taxytita
      ball.vx=0.1;
      ball.vy=0.1;
    }
    if (ball.z > 30) {
      life--;
      ball.z = 30;
      change_dir_z *= -1;
    }
  }

  void moveBall() {
    float prev_x = ball.x;
    float prev_y = ball.y;
    float prev_z = ball.z;

    ball.z = prev_z + ball.vz * change_dir_z;
    ball.x = prev_x + ball.vx * change_dir_x;
    ball.y = prev_y + ball.vy * change_dir_y; //thesi = proigoumeni_thesi+taxytita*kateythinsi

    if(auto_is_on){
      player.x = ball.x;
      player.y = ball.y;
    }

    boundBall();
    hitThePlayer();
    hitTheEnemy();
  }

  void findColors() {
    if (flagcolor) {
      srand((unsigned)time(NULL));
      for (int i = 0; i <= num_of_enemies; i++) {
        for (int j = 0; j <= num_of_walls; j++) {
          r[i][j] = (float)rand() / RAND_MAX;
          g[i][j] = (float)rand() / RAND_MAX;
          b[i][j] = (float)rand() / RAND_MAX;
        }
      }
    }
    flagcolor = false;
    // gia na min jana allazei apo tin idle
  }

};