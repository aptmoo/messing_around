#ifndef CORE_TYPES_H
#define CORE_TYPES_H
#include <memory>
#include <cstdint>

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... TArgs>
Ref<T> MakeRef(TArgs&&... args)
{
    return std::make_shared<T>(std::forward<TArgs>(args)...);
}

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... TArgs>
Ref<T> MakeScope(TArgs&&... args)
{
    return std::make_unique<T>(std::forward<TArgs>(args)...);
}

#endif