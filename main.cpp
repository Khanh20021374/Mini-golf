#include "GameManager.h"

int main( int argc, char* args[] )
{
    GameManager* game = GameManager::getInstance();
    game->Run();

    game->Free();
	return 0;
}

