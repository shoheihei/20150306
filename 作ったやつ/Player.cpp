#include "Player.h"

Player player;

void Init(){
	player.x = -25.0;
	player.y = -300.0;
	player.life = 3;
	player.life = 5;
	player.speed_x = 8.0;
	player.slow_speed_x = 4.0;
}

void PlayerMove(AppEnv& env, Player& player){
	// ©‹@‚ÌˆÚ“®ˆ—
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.slow_speed_x;
	}
	else if (env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.speed_x;
	}
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.slow_speed_x;
	}
	else if (env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.speed_x;
	}
	if (player.x >= 350){
		player.x = 350;
	}
	if (player.x <= -400){
		player.x = -400;
	}
}