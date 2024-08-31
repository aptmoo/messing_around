#include "contentmanager.h"
#include <fstream>
#include "json.hpp"

ContentManager::~ContentManager()
{
    for(auto& image : m_Images)
    {
        UnloadImage(*image.second);
        image.second.reset();
    }

    for(auto& texture : m_Textures)
    {
        UnloadTexture(*texture.second);
        texture.second.reset();
    }
}


template <>
Ref<Image> ContentManager::Load(const std::string &path)
{
    if (m_Images.find(path) != m_Images.end())
    {
        return m_Images.at(path);
    }

    std::string absolutePath = m_ContentDir + path;
    m_Images.emplace(path, MakeRef<Image>(LoadImage(absolutePath.c_str())));
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

    std::string absolutePath = m_ContentDir + path;
    m_Textures.emplace(path, MakeRef<Texture>(LoadTexture(absolutePath.c_str())));
    return m_Textures.at(path);
}

template <>
Ref<SpriteSheet> ContentManager::Load(const std::string &path)
{
    std::ifstream file(m_ContentDir + path);
    nlohmann::json data = nlohmann::json::parse(file);
    std::string texturePath = data.at("path");

    SpriteSheetDesc desc;
    desc.name = path;
    desc.sheetSize.width = data.at("sheetSize").at("width");
    desc.sheetSize.height = data.at("sheetSize").at("height");
    desc.spriteSize.width = data.at("spriteSize").at("width");
    desc.spriteSize.height = data.at("spriteSize").at("height");
    desc.offset = data.at("offset");

    m_Sheets.emplace(path, MakeRef<SpriteSheet>(*Load<Image>(texturePath), desc));
    return m_Sheets.at(path);
}