#include "renderutils.h"

void R_DrawModelTransform(const Model &model, const Matrix &transform)
{
    for(int i = 0; i < model.meshCount; i++)
    {
        DrawMesh(model.meshes[i], model.materials[model.meshMaterial[i]], transform);
    }
}