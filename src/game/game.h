#ifndef GAME_H
#define GAME_H
#include "common/renderer3D.h"

enum class GameState
{
    NONE = 0,
    INGAME
};

class Game
{
public:
    Game();
    ~Game();

    void OnUpdate(double dt);
    void OnRender(const Renderer3D& renderer);

    void SetState(GameState state) { m_State = state; };
    GameState GetState() { return m_State; };
private:
    GameState m_State = GameState::NONE;
};

#endif