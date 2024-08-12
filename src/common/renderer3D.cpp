#include "renderer3D.h"
#include <raymath.h>

Renderer3D::Renderer3D(int width, int height)
    : m_Size{width, height}, m_OldSize{m_Size}
{}

void Renderer3D::Init()
{
    m_Target = LoadRenderTexture(m_Size.Width, m_Size.Height);
}

void Renderer3D::Shutdown()
{
    UnloadRenderTexture(m_Target);
}

void Renderer3D::Begin(const Camera3D &camera)
{
    if(m_Size.Width != m_OldSize.Width || m_Size.Height != m_OldSize.Height)
    {
        m_OldSize = m_Size;
        UnloadRenderTexture(m_Target);
        m_Target = LoadRenderTexture(m_Size.Width, m_Size.Height);
    }

    BeginTextureMode(m_Target);
    BeginMode3D(camera);
    ClearBackground(DARKGRAY);
}

void Renderer3D::End()
{
    while(!m_MeshQueue.empty())
    {
        // TODO: unnecesary copy?
        MeshDrawCommand cmd = m_MeshQueue.top();
        DrawMesh(cmd.mesh, cmd.material, cmd.transform);
        m_MeshQueue.pop();
    }

    EndMode3D();
    EndTextureMode();
}

void Renderer3D::Blit()
{
    DrawTextureRec(m_Target.texture, (Rectangle){0, 0, GetScreenWidth(), -GetScreenHeight()}, {0,0}, WHITE);
}

void Renderer3D::Blit(Rectangle target)
{
    DrawTextureRec(m_Target.texture, target, {0, 0}, WHITE);
}

void Renderer3D::DrawModel(Model &model, const Matrix &transform)
{
    for(int i = 0; i < model.meshCount; i++)
    {
        m_MeshQueue.emplace((MeshDrawCommand){model.meshes[i], model.materials[model.meshMaterial[i]], model.transform});
    }
}
