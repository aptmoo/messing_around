#ifndef COMMON_CONTENTMANAGER_H
#define COMMON_CONTENTMANAGER_H
#include <raylib.h>

#include <unordered_map>
#include <string>

#include "types.h"
#include "spritesheet.h"

class ContentManager
{
public:
    template<typename T>
    Ref<T> Load(const std::string& path) {static_assert(0);};
private:
    std::unordered_map<std::string, Ref<Image>> m_Images;
    std::unordered_map<std::string, Ref<Texture>> m_Textures;
};

template <>
Ref<Image> ContentManager::Load(const std::string &path);

template <>
Ref<Texture> ContentManager::Load(const std::string &path);
#endif