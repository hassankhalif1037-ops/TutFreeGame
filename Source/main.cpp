#include "raylib.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include "gameFunctionality.h"
#include "playerFunc.h"




int main()
{
    Vector2 screen = {800, 600};
    InitWindow(screen.x, screen.y, "Gravity test");
    Camera2D camera = {0};
    buildings builds = buildings{
        .platformsDistances = 1000,
        .platformsYcord = 500,
        .platformSize = {500, 500}};
    builds.createBuildings();

    

    Texture2D luffyBase = LoadTexture("Assets/Sprites/luffyBase.png");
    Sprite player = (Sprite){
        .Sprite = {luffyBase},
        .luffyRect = {
            .x = 0,
            .y = 400,
            .width = 64,
            .height = 64
        }
    };

    // PLAYER CAMERA
    camera.target = (Vector2){player.luffyRect.x + player.luffyRect.width / 2, player.luffyRect.y + player.luffyRect.height / 2 / 2}; // The object's pivot point is the top left.
    camera.offset = (Vector2){screen.x / 2.0f, screen.y / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);
    // GAME LOOP
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F)){
            ToggleFullscreen();
        }
        //UPDATE Section:
        //Sets the speeds
        movement(&player);
        apply_gravity(&player);


        y_apply_speed(&player);
        builds.y_check_collisions(&player);
        x_apply_speed(&player);
        //decelerate(&player);
        builds.x_check_collisions(&player);

        //builds.x_check_collisions(&player);

        camera.target = (Vector2){player.luffyRect.x, player.luffyRect.y};
        //DRAWING SECTION
        BeginDrawing();

        ClearBackground({SKYBLUE});
        BeginMode2D(camera);
        DrawTexturePro(player.Sprite, {0, 0, 32 * (float) (player.dir == -1 ? player.dir : 1), 32}, player.luffyRect, {0,0}, 0.0, WHITE);

        DrawRectangleRec(builds.platforms[0], {30, 20, 100, 255});
        for (int i = 0; i < 5; i++)
        {
            DrawRectangleRec(builds.platforms[i], {30, 20, 100, 255});
        }
        EndMode2D();

        EndDrawing();
    }

        UnloadTexture(luffyBase);
        CloseWindow();
    

    return 0;
}


