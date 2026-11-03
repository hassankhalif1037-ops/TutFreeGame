#pragma once
#include "raylib.h"
#include <stdio.h>


struct buildings
{
    float platformsDistances;
    int platformsYcord;
    Vector2 platformSize;
    Rectangle platforms[14];
    
    
};
void createBuildings(Rectangle platforms[14],float *platformsDistances,Vector2 *platformSize,int *platformsYcord)
{
    for (int i = 1; i < 14; i++)
    {
        platforms[i] = {0 + (i * (*platformsDistances)) +  platformSize->x,(float) *platformsYcord , platformSize->x, platformSize->y};
    }
}