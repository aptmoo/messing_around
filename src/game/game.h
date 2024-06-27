#ifndef GAME_H
#define GAME_H

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
    void OnRender();

    void SetState(GameState state) { m_State = state; };
    GameState GetState() { return m_State; };
private:
    GameState m_State = GameState::NONE;
};

#endif