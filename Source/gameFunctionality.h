#pragma once
#include "raylib.h"
#include "playerFunc.h"
typedef struct buildings
{
    float platformsDistances ;
    int platformsYcord;
    Vector2 platformSize;
    Rectangle platforms[5];

    void createBuildings()
    {
        platforms[0] = {0 ,(float) platformsYcord , platformSize.x + 500, platformSize.y};
        for (int i = 1; i < 5; i++)
        {
            platforms[i] = {0 + (i * (platformsDistances)) + platformSize.x,(float) platformsYcord , platformSize.x, platformSize.y};
        }
    }
    void y_check_collisions(Sprite *sprite)
    {
        for (int i = 0; i < 5; i++)
        {
            if (CheckCollisionRecs(sprite->luffyRect, platforms[i]))
            {
                //if luffy's y position is greater than the platforms y position,
                //luffy's position is made to be at max the bottom of the platform
                /*
                    luffy has collided with the platform
                    if his y position is greater than the platform,
                    it necessitates that luffy is below the platform:
                    in programming, the pivot point is the top left.
                    If luffy collides with the platform and his y pos
                    is greater than the platform, it means he has entered
                    the platform from the bottom.
                */
                if (sprite->luffyRect.y > platforms[i].y)
                {
                    sprite->luffyRect.y = platforms[i].y + platforms[i].height;
                }
                else
                {
                    sprite->luffyRect.y = platforms[i].y - sprite->luffyRect.height;
                }
            }
            
        }
    }
    void x_check_collisions(Sprite *sprite)
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (CheckCollisionRecs(sprite->luffyRect, platforms[i]))
            {
                if (sprite->luffyRect.x > platforms[i].x)
                {
                    sprite->luffyRect.x = platforms[i].x + platforms[i].height;
                }
                else
                {
                    sprite->luffyRect.x = platforms[i].x - sprite->luffyRect.height;
                }
            }
        }
    }

} buildings;
