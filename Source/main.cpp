#include "raylib.h"
#include <stdio.h>
#include "gameFunctionality.h"
#include "playerFunc.h"
typedef struct 
{
    Vector2 velocity;
    Texture2D Sprite;
}Sprite;



int main()
{
    Vector2 screen = {800, 600};
    
    
    InitWindow(screen.x, screen.y, "Gravity test");

    buildings builds = buildings();
    builds.platformsDistances = 1000;
    builds.platformSize = {500, 500};
    builds.platformsYcord = 500;
    builds.platforms[0] = {0,(float) builds.platformsYcord , builds.platformSize.x + 500, builds.platformSize.y};
    createBuildings(&builds.platforms[14],&builds.platformsDistances , &builds.platformSize, &builds.platformsYcord);


    playerCharacteristics pc = playerCharacteristics();
    Camera2D camera = {0};
    //PLAYER DATA:
    pc.coordinates = {0, 400};
    pc.player = {pc.coordinates.x, pc.coordinates.y, pc.size.x, pc.size.y};
    pc.speed = 20;
    //PLAYER CAMERA
    

    camera.target = (Vector2){pc.coordinates.x + pc.player.width, pc.coordinates.y + pc.player.height}; // The object's pivot point is the top left.
    camera.offset = (Vector2) {GetRenderWidth()/2.0f, GetRenderHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    
    SetTargetFPS(60);
    // GAME LOOP
    while (!WindowShouldClose())
    {
        
        pc.player = {pc.coordinates.x, pc.coordinates.y, pc.size.x, pc.size.y};
        printf("X Position: %f,  Y Position %f \n", pc.coordinates.x, pc.coordinates.y);

        pc.movement();

        camera.target = (Vector2){pc.coordinates.x, pc.coordinates.y};
        BeginDrawing();

        ClearBackground({0, 30, 140, 255});
        BeginMode2D(camera);
            DrawRectangleRec({pc.coordinates.x, pc.coordinates.y, pc.size.x, pc.size.y}, {255, 255, 255, 255});
            
            DrawRectangleRec(builds.platforms[0], {255, 255, 255, 255});
            for (int i = 1; i < 14; i++)
            {
                DrawRectangleRec(builds.platforms[i], {255, 255, 255, 255});
                
            }
            EndMode2D();

            EndDrawing();
    }
 
    CloseWindow();
 
    return 0;
}


