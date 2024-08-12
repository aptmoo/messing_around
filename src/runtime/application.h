#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H
#include <string>
#include "common/types.h"
#include "game/game.h"

struct AppDesc
{
    std::string Name = "DefaultName";
    int Width = 1280;
    int Height = 720;
};

class RuntimeApplication
{
public:
    RuntimeApplication(const AppDesc& desc = AppDesc());
    ~RuntimeApplication();

    RuntimeApplication& Get(){ return *s_Instance; }

    void Run();
private:
    void OnUpdate();
    void OnRender();

    AppDesc m_Desc;

    Game m_Game;

    static RuntimeApplication* s_Instance;
    bool m_IsRunning = false;
};

#endif