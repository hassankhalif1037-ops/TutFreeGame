#pragma once
#include "raylib.h"
#include <stdio.h>
struct playerCharacteristics
{
    int speed;
    const Vector2 size = {50, 50};
    Rectangle player;
    Vector2 coordinates;
    
    float gravitySpeed = 0.2f;
    int fallingSpeed = 70;
    

    
};
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
void gravity()
{
    coordinates.y += fallingSpeed * gravitySpeed;
    fallingSpeed += 5;
    GetFrameTime();
}
void collision()
{
    printf("IGNORE");
        
}