#include "lib/defines.hpp"
#include "lib/appEnv.hpp"

struct Player{
	float x;
	float y;
	float speed_x;
	float slow_speed_x;
	float life;
};

void Init();
void PlayerMove(AppEnv& env, Player& player);