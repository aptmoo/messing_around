#include "application.h"
#include <raylib.h>
#include <iostream>


RuntimeApplication* RuntimeApplication::s_Instance = nullptr;

RuntimeApplication::RuntimeApplication(const AppDesc& desc)
{
    s_Instance = this;
    m_Desc = desc;

    InitWindow(desc.Width, desc.Height, desc.Name.c_str());
    InitAudioDevice();
}

RuntimeApplication::~RuntimeApplication()
{
    CloseAudioDevice();
    CloseWindow();
}

void RuntimeApplication::Run()
{
    if(m_IsRunning)
        return;
    m_IsRunning = true;


    while (!WindowShouldClose())
    {
        OnUpdate();
        OnRender();
    }
}

void RuntimeApplication::OnUpdate()
{

}

void RuntimeApplication::OnRender()
{
    BeginDrawing();
    ClearBackground(DARKGRAY);
    EndDrawing();
}