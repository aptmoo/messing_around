#ifndef SHARED_ARGS_H
#define SHARED_ARGS_H
#include <vector>
#include <unordered_map>
#include <string>

static std::string s_EmptyString = "";  // lmfao

class Args
{
public:
    /**
     * @brief Args constructor.
     * It's a good practice to pass argv and argc from main without any processing.
     *
     * @param argc
     * @param argv
     */
    Args(int argc, const char **argv);
    Args() = default;

    std::size_t Size()
    {
        return m_Args.size();
    }

    const std::string &at(std::size_t i)
    {
        if (i + 1 > m_Args.size())
            return s_EmptyString; // lmaoo
        return m_Args.at(i);
    }

    const std::string &operator[](std::size_t i)
    {
        return this->at(i);
    }

private:
    std::vector<std::string> m_Args;
};

class ParsedArgs
{
public:
    ParsedArgs(int argc, const char **argv);
    ParsedArgs() = default;
    ~ParsedArgs() = default;

    std::size_t Size()
    {
        return m_Args.size();
    }

    bool Exists(const std::string &name)
    {
        return (m_Args.find(name) != m_Args.end());
    }

    const std::string &GetOrDefault(const std::string &key, const std::string &d)
    {
        if (this->Exists(key))
        {
            return this->at(key);
        }

        return d;
    }

    const std::string &at(const std::string &key)
    {
        return m_Args.at(key);
    }

    const std::string &operator[](const std::string &key)
    {
        return m_Args.at(key);
    }

private:
    std::unordered_map<std::string, std::string> m_Args;
};

#endif