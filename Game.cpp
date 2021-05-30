#include "Ball.cpp"
#include "Enemy.cpp"
#include "Player.cpp"
#include <time.h>

class Game {

public:
  Enemy enemies[16][16];
  Ball ball;
  Player player;

  float r[16][4];
  float g[16][4];
  float b[16][4];
  bool flagcolor = true;
  
  float r_ball;
  float sxdia2_player;
  float sydia2_player;
  float szdia2_player;

  float savex = 1;
  float savey = 1;
  float savez = 1;

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
      savez *= -1;
      ball.z -= 0.3;
      cout << endl
           << endl
           << endl
           << "Xtypisa player morti" << endl
           << endl
           << endl
           << endl;
    }
    // cout<<  "x= "<<abs(player.x-ball.x) << " "<< +r_ball+sxdia2_player  <<
    // endl; cout<<  "y= "<<abs(player.y-ball.y) << " "<< +r_ball+sydia2_player
    // << endl; cout<<  "z= " << abs(player.z-ball.z) << " "<<
    // +(r_ball+szdia2_player)/10  << endl; cout << "playerx= " << player.x << "
    // playery= " << player.y << " playerz= " << player.z << endl; cout <<
    // "ballx= " << ball.x <<" bally= " << ball.y  << " ballz= " <<  ball.z <<
    // endl;
  }

  void hitTheEnemy() {
    if (ball.z < -350) {
      int count = 0;
      for (auto &enemy : enemies) {
        for (auto &e : enemy) {
          count++;
          if (count == 81)
            break;
          // printf("count=%d\n",count);
          if (e.flag && abs(e.x - ball.x) < 90 && abs(e.y - ball.y) < 90 &&
              abs(e.z - ball.z) < (r_ball + e.szdia2) / 18) {
            if (e.flag && (abs(e.x - ball.x) < r_ball + e.sxdia2 * 3) &&
                (abs(e.y - ball.y) < r_ball + e.sydia2 * 5) &&
                (abs(e.z - ball.z) < (r_ball + e.szdia2) / 20)) {
              savez *= -1;
              ball.z += 0.3;
              e.flag = false;
              cout << endl
                   << endl
                   << endl
                   << "Xtypisa morti enemy" << endl
                   << endl
                   << endl
                   << endl;
            }
            // e.sxdia2=15
            // r=15
            cout << "x= " << abs(e.x - ball.x) << " < " << r_ball + e.sxdia2 * 3
                 << endl;
            cout << "y= " << abs(e.y - ball.y) << " < " << r_ball + e.sydia2 * 3
                 << endl;
            cout << "z= " << abs(e.z - ball.z) << " < "
                 << (r_ball + e.szdia2) / 20 << endl;
            cout << "ex= " << e.x << " ey= " << e.y << " ez= " << e.z << endl;
            cout << "ballx= " << ball.x << " bally= " << ball.y
                 << " ballz= " << ball.z << endl
                 << endl;
          }
          // cout<<  "x= "<<abs(e.x-ball.x) << " "<< +r_ball+sxdia2_player  <<
          // endl; cout<<  "y= "<<abs(e.y-ball.y) << " "<< +r_ball+sydia2_player
          // << endl; cout<<  "z= " << abs(e.z-ball.z) << " "<<
          // +(r_ball+szdia2_player)/10  << endl; cout << "ex= " << e.x << " ey=
          // "
          // << e.y << " ez= " << e.z << endl; cout << "ballx= " << ball.x <<"
          // bally= " << ball.y  << " ballz= " <<  ball.z << endl;
        }
        if (count == 81)
          break;
      }
    }

    // cout << "ballx= " << ball.x <<" bally= " << ball.y  << " ballz= " <<
    // ball.z
    // << endl;
  }

  void boundBall() {
    if (ball.x > 75) {
      ball.x = 75;
      savex *= -1;
    }

    if (ball.y > 75) {
      ball.y = 75;
      savey *= -1;
    }

    if (ball.x < -75) {
      ball.x = -75;
      savex *= -1;
    }
    if (ball.y < -75) {
      ball.y = -75;
      savey *= -1;
    }
    if (ball.z < -450) {
      ball.z = -450;
      savez *= -1;
    }
    if (ball.z > 30) {
      ball.z = 30;
      savez *= -1;
    }
  }

  void moveBall() {
    float g = 10;
    float dt = 0.01;
    float prev_x = ball.x;
    float prev_y = ball.y;
    float prev_z = ball.z;

    ball.z = prev_z + (ball.vz * savez);
    ball.x = prev_x + ball.vx * savex; // ayto paei moni tis i mpala
    ball.y = prev_y + ball.vy * savey;

    // edw paei me ton paixti
    // ball.x=player.x;
    // ball.y=player.y;

    player.x = ball.x;
    player.y = ball.y;

    // cout << "savey= "<<savey << " savex="<< savex << "bally= "<<ball.y << "
    // balx="<< ball.x <<endl ;

    boundBall();
    hitThePlayer();
    hitTheEnemy();
  }

  void findColors() {
    if (flagcolor) {
      srand((unsigned)time(NULL));
      for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 4; j++) {
          r[i][j] = (float)rand() / RAND_MAX;
          g[i][j] = (float)rand() / RAND_MAX;
          b[i][j] = (float)rand() / RAND_MAX;
        }
      }
    }
    flagcolor = false;
    // gia na min jana allazei apo tin idle
  }

  bool do_once = true;
  void Deije() {
    if (do_once == true) {
      for (int i = 0; i <= 15; i++) {
        for (int j = 0; j <= 4; j++) {
          printf("j=%d, i=%d, x=%3.f y=%3.f z=%3.f\n", j, i, (enemies[i][j].x),
                 enemies[i][j].y, enemies[i][j].z);
        }
      }
      ball.printInformation();
    }
  }
};