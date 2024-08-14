#include "contentmanager.h"

template <>
Ref<Image> ContentManager::Load(const std::string &path)
{
    if (m_Images.find(path) != m_Images.end())
    {
        return m_Images.at(path);
    }

    m_Images.emplace(path, MakeRef<Image>(LoadImage(path.c_str())));
    return m_Images.at(path);
}

template <>
Ref<Texture> ContentManager::Load(const std::string &path)
{
    if (m_Textures.find(path) != m_Textures.end())
    {
        return m_Textures.at(path);
    }

    if (m_Images.find(path) != m_Images.end())
    {
        m_Textures.emplace(path, MakeRef<Texture>(LoadTextureFromImage(*m_Images.at(path))));
        return m_Textures.at(path);
    }

    m_Textures.emplace(path, MakeRef<Texture>(LoadTexture(path.c_str())));
    return m_Textures.at(path);
}
