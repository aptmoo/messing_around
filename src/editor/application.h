#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H
#include <string>
#include "common/types.h"
#include "common/renderer3D.h"

struct AppDesc
{
    std::string Name = "DefaultName";
    int Width = 1280;
    int Height = 720;
};

class EditorApplication
{
public:
    EditorApplication(const AppDesc& desc = AppDesc());
    ~EditorApplication();

    EditorApplication* Get(){ return s_Instance; }

    void Run();
private:
    void OnUpdate();
    void OnRender();

    AppDesc m_Desc;

    Renderer3D m_Renderer;
    Camera3D m_EditorCamera;

    static EditorApplication* s_Instance;
    bool m_IsRunning = false;
};

#endif