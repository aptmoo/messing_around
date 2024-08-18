#include <raylib.h>
#include <raymath.h>

#include "common/spritesheet.h"
#include "common/contentmanager.h"

int main(int argc, char const *argv[])
{
    InitWindow(1280, 720, "Sandbox");

    Camera2D cam;
    cam.target = Vector2Zero();
    cam.offset = Vector2Zero();
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    ContentManager content;
    Ref<Image> img1 = content.Load<Image>("./content/tilemaps/tilemap.png");

    SpriteSheetDesc sheetDesc = {{18, 18}, {20, 9}, 1};
    SpriteSheet sheet(*img1, sheetDesc);
    SpriteSheetDesc sheetDesc2 = {{18, 18}, {20, 9}, 0};
    SpriteSheet sheet2(LoadImage("./content/tilemaps/tilemap_packed.png"),sheetDesc2);

    Ref<Texture2D> tex = content.Load<Texture>("./content/tilemaps/tilemap.png");
    float rotation = 0;

    while (!WindowShouldClose())
    {
        rotation += 45 *GetFrameTime();

        BeginDrawing();
            ClearBackground(GRAY);
            BeginMode2D(cam);
                sheet.Draw(8, 2, GetMousePosition(), {5, 10}, rotation);
                sheet2.Draw(8, 2, GetMousePosition(), {10,5}, rotation);
            EndMode2D();
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}
