#include "Level.h"

#include <string>
#include "Defines.h"

Level::Level(int level)
{
    mapTexture.loadFromFile("assets/level" + std::to_string(level) + ".png");
    mapSprite.setTexture(mapTexture);
    for (int i = 0; i < sizeof(LEVEL1_WALLS) / (sizeof(int)*4); i++)
    {
        walls.push_back(CollisionBox(LEVEL1_WALLS[i][0] * TILE_SIZE, LEVEL1_WALLS[i][1] * TILE_SIZE, LEVEL1_WALLS[i][2] * TILE_SIZE, LEVEL1_WALLS[i][3] * TILE_SIZE));
    }
}
