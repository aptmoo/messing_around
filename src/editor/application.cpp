#include "application.h"
#include <raylib.h>
#include <iostream>

EditorApplication* EditorApplication::s_Instance = nullptr;

EditorApplication::EditorApplication(const AppDesc& desc)
{
    SetInstance(this);
    m_Desc = desc;

    InitWindow(desc.Width, desc.Height, desc.Name.c_str());
    InitAudioDevice();
}

EditorApplication::~EditorApplication()
{
    CloseAudioDevice();
    CloseWindow();
}

void EditorApplication::Run()
{
    if(m_IsRunning)
        return;
    m_IsRunning = true;

    while (!WindowShouldClose() && m_IsRunning)
    {
        OnUpdate();
        OnRender();
    }
}

void EditorApplication::OnUpdate()
{

}

void EditorApplication::OnRender()
{
    BeginDrawing();
    EndDrawing();
}