#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct playerCharacteristics
{
    int speed;
    const Vector2 size = {50, 50};
    Rectangle player;
    Vector2 coordinates;
    void movement()
    {
        if (IsKeyDown(KEY_D))
        {
            printf("PRESSED D!! \n");
            coordinates.x += speed;
            printf("coordinates.x : %f\n", coordinates.x);
        }
        if (IsKeyDown(KEY_A))
        {
            printf("PRESSED A!! \n");
            coordinates.x -= speed;
            printf("coordinates.x : %f\n", coordinates.x);
        }
        if (IsKeyDown(KEY_W))
        {
            printf("PRESSED W!! \n");
            coordinates.y -= speed;
            printf("coordinates.y : %f\n", coordinates.y);
        }
        if (IsKeyDown(KEY_S))
        {
            printf("PRESSED W!! \n");
            coordinates.y += speed;
            printf("coordinates.y : %f\n", coordinates.y);
        }
    }
    float gravitySpeed = 0.2f;
    int fallingSpeed = 70;
    void gravity()
    {
        coordinates.y += fallingSpeed * gravitySpeed;
        fallingSpeed += 5;
        int time = 0;
        while (time < 60){
            time += 1;
        }
    }

    void collision()
    {
        printf("IGNORE");
        
    }
};
struct buildings
{
    float platformsDistances;
    int platformsYcord;
    Vector2 platformSize;
    Rectangle platforms[14];
    
    void createBuildings()
    {
        for (int i = 1; i < 14; i++)
        {
            platforms[i] = {0 + (i * platformsDistances) +  platformSize.x,(float) platformsYcord , platformSize.x, platformSize.y};
        }
    }
};

int main()
{
    Vector2 screen = {800, 600};
    
    
    InitWindow(screen.x, screen.y, "Gravity test");
    int count = 0;

    buildings builds = buildings();
    builds.platformsDistances = 1000;
    builds.platformSize = {500, 500};
    builds.platformsYcord = 500;
    builds.platforms[0] = {0,(float) builds.platformsYcord , builds.platformSize.x + 500, builds.platformSize.y};
    builds.createBuildings();


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


