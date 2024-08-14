#include "args.h"
#include <iostream>

Args::Args(int argc, const char** argv)
{
    if(argc <= 1)
        return;

    for(int i = 1; i < argc; i++)
    {
        m_Args.push_back(std::string(argv[i]));
    }
}

ParsedArgs::ParsedArgs(int argc, const char** argv)
{
    if(argc <= 1)
        return;

    std::vector<std::string> args(argv+1, argv+argc);

    /* TODO: Sucks ass */
    for(int i = 0; i < args.size(); i++)
    {
        std::string key, value;
        key = args.at(i);
        if(key.find("--") != std::string::npos)
        {
            /* Value is next one in the list */
            if(i + 1 < args.size())
                value = args.at(i+1);
            
            /* Values beginning with "--" are not values, so empty them */
            if(value.find("--") != std::string::npos)
                value = "";

            /* Erase the "--" part */
            key.erase(0, 2);
            m_Args.emplace(key, value);
        }
    }
    #ifndef NDEBUG
    for(auto& c : m_Args)
    {
        std::cout << c.first << " : " << c.second << '\n';
    }
    #endif
}
