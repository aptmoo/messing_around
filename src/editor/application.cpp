#include "application.h"
#include <raylib.h>
#include <iostream>

#include "ui/raygui.h"

EditorApplication* EditorApplication::s_Instance = nullptr;

EditorApplication::EditorApplication(const AppDesc& desc)
{
    s_Instance = this;
    m_Desc = desc;

    InitWindow(desc.Width, desc.Height, desc.Name.c_str());
    InitAudioDevice();

    m_Renderer.SetSize({GetScreenWidth(), GetScreenHeight()});

    m_EditorCamera.fovy = 10;
    m_EditorCamera.position = (Vector3){10, 10, 10};
    m_EditorCamera.target = (Vector3){0, 0, 0};
    m_EditorCamera.up = (Vector3){0, 1, 0};
    m_EditorCamera.projection = CameraProjection::CAMERA_ORTHOGRAPHIC;
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

    while (!WindowShouldClose())
    {
        OnUpdate();
        OnRender();
    }
}

void EditorApplication::OnUpdate()
{
    UpdateCameraPro(&m_EditorCamera, {0, 0, 0}, {0, 0, 0}, 0.0f);   
}

void EditorApplication::OnRender()
{
    m_Renderer.SetSize({GetScreenWidth(), GetScreenHeight()});
    m_Renderer.Begin(m_EditorCamera);
        DrawGrid(20, 1);
    m_Renderer.End();

    BeginDrawing();
    ClearBackground(DARKGRAY);
    m_Renderer.Blit();
    EndDrawing();
}