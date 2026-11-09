#pragma once
#include "raylib.h"
#include <stdio.h>


enum SpriteDirection { Left = -1, Right = 1};
typedef struct Sprite
{
    Texture2D Sprite;
    Rectangle luffyRect;
    Vector2 vel;
    float dashVel;
    SpriteDirection dir;
} Sprite;
//when we don't move, we have no velocity. But when we do, our velocity is ____
void movement(Sprite *sprite)
{
    sprite->vel.x = 0;
    sprite->dashVel = 0;
    if (IsKeyDown(KEY_D))
    {
        DrawText("Moving RIGHT!", 0, 0, 25, WHITE);
        sprite->vel.x = 200.0f;
        sprite->dir = SpriteDirection::Right;
    }
    if (IsKeyDown(KEY_A))
    {
        DrawText("Moving LEFT!", 0, 0, 25, WHITE);
        sprite->vel.x = -200.0f;
        sprite->dir = SpriteDirection::Left;
    }
    if (IsKeyPressed(KEY_W))
    {
        sprite->vel.y = -1000.0f;
    }
    if (IsKeyPressed(KEY_Q))
    {
        sprite->dashVel = 700.0f;
    }
}
void x_apply_speed(Sprite *sprite)
{
    sprite->luffyRect.x += sprite->vel.x * GetFrameTime();
    sprite->dashVel += 5;
    sprite->luffyRect.x += sprite->dashVel * GetFrameTime();
    
    
}
void y_apply_speed(Sprite *sprite)
{
    sprite->luffyRect.y += sprite->vel.y * GetFrameTime();
}
void apply_gravity(Sprite *sprite)
{
    //All you are doing is changing velocity
    //this doesn't change global position
    //apply speed makes sure this happens
    sprite->vel.y += 50.0f;
    if (sprite->vel.y > 500.0f)
    {
        sprite->vel.y = 500.0f;
    }
}
