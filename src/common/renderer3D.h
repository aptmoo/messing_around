#ifndef COMMON_RENDERER_H
#define COMMON_RENDERER_H
#include "common/types.h"
#include "renderutils.h"
#include <raylib.h>
#include <queue>

struct TargetSize
{
    int Width, Height;
};

class Renderer3D
{
public:
    Renderer3D(int width = 64, int height = 64);

    /* ---- Renderer management funcs ----- */
    void Init();
    void Shutdown();

    void Begin(const Camera3D& camera);
    void End();

    void Blit();
    void Blit(Rectangle target);

    void SetSize(TargetSize size){ m_Size = size; };
    TargetSize GetSize(){ return m_Size; }

    /* ----- Draw funcs -----*/
    void DrawModel(Model& model, const Matrix& transform);

private:
    TargetSize m_Size;
    TargetSize m_OldSize;
    
    RenderTexture m_Target;

    std::priority_queue<MeshDrawCommand, std::vector<MeshDrawCommand>, CompareMeshDrawCommand> m_MeshQueue;
};

#endif