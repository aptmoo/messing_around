#ifndef GAME_GAMEOBJ_H
#define GAME_GAMEOBJ_H
#include <raylib.h>
#include "common/types.h"
#include "common/renderer3D.h"

class GameObject
{
public:
    virtual void Render(const Renderer3D& renderer);
private:

};

#endif