#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H
#include <string>
#include "common/types.h"
#include "common/app.h"

class EditorApplication : public IApplication
{
public:
    EditorApplication(const AppDesc& desc = AppDesc());
    virtual ~EditorApplication() override;

    virtual void Run() override;
    virtual void Shutdown() override { m_IsRunning = false; }
private:
    void OnUpdate();
    void OnRender();

    AppDesc m_Desc;
    static EditorApplication* s_Instance;
    bool m_IsRunning = false;
};

#endif