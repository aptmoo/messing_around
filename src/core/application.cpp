#include "application.h"
#include <raylib.h>
#include <iostream>

#include "raygui.h"
#include "draggableWindow.h"

static DraggableWindow window;

Application* Application::s_Instance = nullptr;

Application::Application(const AppDesc& desc)
{
    s_Instance = this;
    m_Desc = desc;

    InitWindow(desc.Width, desc.Height, desc.Name.c_str());
    InitAudioDevice();
}

Application::~Application()
{
    CloseAudioDevice();
    CloseWindow();
}

void Application::Run()
{
    if(m_IsRunning)
        return;
    m_IsRunning = true;

    window.SetSize({150, 100});

    while (!WindowShouldClose())
    {
        OnUpdate();
        OnRender();
    }
}

void Application::OnUpdate()
{
    window.Update();
}

void Application::OnRender()
{
    BeginDrawing();
    ClearBackground(DARKGRAY);
    window.Render();
    EndDrawing();
}