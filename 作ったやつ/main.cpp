//
// アプリ雛形
//

#include "Player.h"


enum Window {
  WIDTH  = 800,
  HEIGHT = 950
};

enum Bullet{
	MAX = 50
};

struct Enemy{
	float x;
	float y;
	bool isDead;
}enemy;

struct PlayerShot{
	float x;
	float y;
	float speed;
	bool judge;
	bool isDead;
}P_shot;

struct EnemyShot{
	float x;
	float y;
	float speed;
	bool judge;
	bool isDead;
}E_shot;

PlayerShot createShot(float player_x, float player_y ){
	PlayerShot P_shot;
	P_shot.isDead = false;
	P_shot.x = player_x + 25;
	P_shot.y = player_y + 85;

	return P_shot;
}

extern Player player;

// 
// メインプログラム
// 
int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

  Init();

  P_shot.speed = 15;
  unsigned int i = 0;
  unsigned int e = 0;
  int counter = 0;

  enemy.x = -350;
  enemy.y = 400;
  enemy.isDead = false;
  float enemy_x = 0;
  float enemy_y = 0;

  std::vector<PlayerShot>P_shots;
  std::vector<PlayerShot>::iterator it;

  it = P_shots.begin();

  while (env.isOpen()) {

	  // 自機の移動処理
	  PlayerMove(env, player);

	  // 弾の生成
	  if (counter >0)
		counter--;
	  if (env.isPressKey(GLFW_KEY_SPACE) && P_shots.size() != Bullet::MAX){
		  if (counter <= 0){
			  P_shots.push_back(createShot(player.x, player.y));
			  counter = 3;
		  }
	  }

    env.setupDraw();
	// 弾の移動
	for ( i = 0; i < P_shots.size(); ++i){
		P_shots[i].y += P_shot.speed;
		drawFillCircle(P_shots[i].x, P_shots[i].y, 5, 5, 10,
			Color(1, 1, 1));
		
		// 弾の消滅条件 
		if (P_shots[i].y > 1200){
			P_shots[i].isDead = true;
		}
	}

	for (i = 0; i < P_shots.size(); ++i){
		if (!P_shots[i].isDead){
			break;
		}
	}
	if (i == P_shots.size()){
		P_shots.clear();
	}

	// 敵の処理
	for (e = 0; e < 10; ++e){
		enemy_x = enemy.x + 70 * e;
		drawFillBox(enemy_x, enemy.y, 60, 60,
			Color(1, 1, 1));
	}

	drawFillBox(player.x, player.y, 50, 80,
		Color(1, 1, 1));

    env.update();
  }
}
