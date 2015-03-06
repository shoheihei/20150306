//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum Window {
  WIDTH  = 800,
  HEIGHT = 800
};

enum Bullet{
	MAX = 50
};

struct Player{
	float x;
	float y;
	float speed_x;
	float life;
}player;

struct Shot{
	float x;
	float y;
	float speed;
	bool judge;
	bool isDead;
};

Shot createShot(float player_x, float player_y ){
	Shot shot;
	shot.isDead = false;
	shot.x = player_x + 25;
	shot.y = player_y + 85;

	return shot;
}

// 
// メインプログラム
// 
int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Shot shot;

  player.x = -25.0;
  player.y = -300.0;
  player.life = 3;
  player.life = 5;
  player.speed_x = 8.0;
  shot.speed = 15;
  unsigned int i = 0;
  int counter = 0;

  std::vector<Shot>shots;
  std::vector<Shot>::iterator it;

  it = shots.begin();

  while (env.isOpen()) {

	  // 移動処理
	  if (env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		  player.x += player.speed_x;
	  }
	  if (env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		  player.x -= player.speed_x;
	  }
	  if (player.x >= 350){
		  player.x = 350;
	  }
	  if (player.x <= -400){
		  player.x = -400;
	  }

	  // 弾
	  if (counter >0)
		counter--;
	  if (env.isPressKey(GLFW_KEY_SPACE) && shots.size() != Bullet::MAX){
		  if (counter <= 0){
			  shots.push_back(createShot(player.x, player.y));
			  counter = 3;
		  }
	  }

    env.setupDraw();
	for ( i = 0; i < shots.size(); ++i){
		shots[i].y += shot.speed;
		drawFillCircle(shots[i].x, shots[i].y, 5, 5, 10,
			Color(1, 1, 1));
		if (shots[i].y > 450){
			shots[i].isDead = true;
		}
	}

	for (i = 0; i < shots.size(); ++i){
		if (!shots[i].isDead){
			break;
		}
	}
	if (i == shots.size()){
		shots.clear();
	}

	drawFillBox(player.x, player.y, 50, 80,
		Color(1, 1, 1));

    env.update();
  }
}
