#include "game.h"
#include <raylib.h>

Game::Game()
{

}

Game::~Game()
{

}

void Game::OnUpdate(double dt)
{

}

void Game::OnRender(const Renderer3D &renderer)
{
    DrawGrid(20, 10);
}