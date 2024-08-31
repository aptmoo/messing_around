#include <raylib.h>
#include <raymath.h>

#include "common/spritesheet.h"
#include "common/contentmanager.h"

struct MovingThing
{
    Vector2 pos;
    Vector2 velocity;
};

void UpdateMovingThing(MovingThing& thing, double dt)
{
    if(thing.pos.x >= GetScreenWidth() || thing.pos.x <= 0)
        thing.velocity.x = -thing.velocity.x;

    if(thing.pos.y >= GetScreenHeight() || thing.pos.y <= 0)
        thing.velocity.y = -thing.velocity.y;

    thing.pos = Vector2Add(thing.pos, Vector2Scale(thing.velocity, dt));
}

int main(int argc, char const *argv[])
{
    InitWindow(1280, 720, "Sandbox");

    #define THING_AMOUNT 1024
    MovingThing things[THING_AMOUNT];
    for(int i = 0; i < THING_AMOUNT; i++)
    {
        things[i].pos.x = GetRandomValue(0, GetScreenWidth() - 10);
        things[i].pos.y = GetRandomValue(10, GetScreenHeight() - 10);

        things[i].velocity.x = GetRandomValue(-50, 50);
        things[i].velocity.y = GetRandomValue(-50, 50);
    }

    Camera2D cam;
    cam.target = Vector2Zero();
    cam.offset = Vector2Zero();
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    Camera3D cam3D;
    cam3D.fovy = 100;
    cam3D.position = {0, 0, 10};
    cam3D.target = {0, 0, 0};
    cam3D.projection = CAMERA_ORTHOGRAPHIC;
    cam3D.up = {0, 1, 0};

    ContentManager content;
    content.SetContentDir("../content/");
    Ref<Image> img1 = content.Load<Image>("tilemaps/tilemap.png");

    Ref<SpriteSheet> sheetRef = content.Load<SpriteSheet>("tilesheet.json");

    SpriteSheetDesc sheetDesc = {"", {18, 18}, {20, 9}, 1};
    SpriteSheet sheet(*img1, sheetDesc);
    SpriteSheetDesc sheetDesc2 = {"", {18, 18}, {20, 9}, 0};
    SpriteSheet sheet2(LoadImage("../content/tilemaps/tilemap_packed.png"), sheetDesc2);

    Ref<Texture2D> tex = content.Load<Texture>("tilemaps/tilemap.png");
    float rotation = 0;

    Model model = LoadModelFromMesh(GenMeshPlane(1, 1, 1, 1));

    while (!WindowShouldClose())
    {
        double dt = GetFrameTime();

        rotation += 10 * dt;

        for(int i = 0; i < THING_AMOUNT; i++)
        {
            UpdateMovingThing(things[i], dt);
        }


        // cam3D.position = {-(float)(GetScreenWidth() / 2), -(float(GetScreenHeight() / 2)), 10};
        // cam3D.target = {  -(float)(GetScreenWidth() / 2), -(float(GetScreenHeight() / 2)), 0};
        cam3D.position = {100, -50, 10};
        cam3D.target = {  100, -50, 0};

        UpdateCameraPro(&cam3D, Vector3Zero(), Vector3Zero(), 0.0f);

        BeginDrawing();
            ClearBackground(GRAY);

            BeginMode2D(cam);
                sheetRef->Draw(8, 6, {10, 10});
                // for(int i = 0; i < THING_AMOUNT; i++)
                // {
                //     sheetRef->Draw(8, 6, things[i].pos, {4, 4}, 0.0f);
                // }
            EndMode2D();

            BeginMode3D(cam3D);
                DrawModelEx(model, {rotation, 0, 0}, {1, 0, 0}, 90.0f, Vector3One(), WHITE);
            EndMode3D();

            DrawFPS(10, 10);
            DrawText(TextFormat("%f", rotation), 10, 40, 20, WHITE);
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}
