#ifndef COMMON_RENDERUTILS_H
#define COMMON_RENDERUTILS_H
#include <raylib.h>

struct MeshDrawCommand
{
    Mesh mesh;
    Material material;
    Matrix transform;
};

struct CompareMeshDrawCommand
{
    bool operator()(MeshDrawCommand a, MeshDrawCommand b)
    {
        bool value = false;
        value = a.mesh.vaoId < b.mesh.vaoId;
        value = a.material.shader.id < b.material.shader.id;
        return value;
    }
};

// void R_DrawModelTransform(const Model& model, const Matrix& transform);

#endif