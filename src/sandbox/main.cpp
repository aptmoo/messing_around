#include <raylib.h>
#include <raymath.h>

#include "common/spritesheet.h"
#include "common/contentmanager.h"

int main(int argc, char const *argv[])
{
    InitWindow(1280, 720, "Sandbox");

    ContentManager content;
    Ref<Image> img1 = content.Load<Image>("./content/tilemaps/tilemap.png");

    SpriteSheet sheet(*img1, 18, 18, 20, 9, 1);
    SpriteSheet sheet2(LoadImage("./content/tilemaps/tilemap_packed.png"), 18, 18, 20, 9, 0);

    Ref<Texture2D> tex = content.Load<Texture>("./content/tilemaps/tilemap.png");
    float rotation = 0;

    while (!WindowShouldClose())
    {
        rotation++;
        BeginDrawing();
        ClearBackground(GRAY);
        sheet.Draw(8, 2, GetMousePosition(), {5, 10}, 0);
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}
