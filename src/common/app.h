#ifndef COMMON_APP_H
#define COMMON_APP_H
#include <string>
#include <raylib.h>
#include "args.h"

struct AppDesc
{
    std::string Name = "DefaultName";
    int Width = 1280;
    int Height = 720;
    ParsedArgs Args;
};

class IApplication
{
public:
    virtual ~IApplication() = default;

    virtual void Run() = 0;
    virtual void Shutdown() = 0;

    static IApplication& Get();// { return *s_Instance; };
protected:
    static void SetInstance(IApplication* instance);// { s_Instance = instance; };
};


#endif