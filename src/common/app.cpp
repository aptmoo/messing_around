#include "app.h"

static IApplication* s_Instance;

IApplication &IApplication::Get() { return *s_Instance; };

void IApplication::SetInstance(IApplication *instance) { s_Instance = instance; };