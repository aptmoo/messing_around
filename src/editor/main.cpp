#include "application.h"

int main(int argc, char const *argv[])
{
    AppDesc desc
    {
        "Editor",
        1280,
        720,
        {argc, argv},
    };

    EditorApplication app(desc);
    app.Run();
    return 0;
}
