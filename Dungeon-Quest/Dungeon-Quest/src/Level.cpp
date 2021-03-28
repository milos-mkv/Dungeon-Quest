#include <Level.hpp>

#include <Assets.h>
#include <Defines.h>
#include <EntityFactory.hpp>
#include <components/CharacterComponent.h>

Level::Level(int level)
{
    mapSprite.setTexture(Assets::MapTextures[level - 1]);
    camera = CreatePTR<sf::View>(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    uiview = CreatePTR<sf::View>(sf::FloatRect(0, 32, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    for (int i = 0; i < sizeof(LEVEL1_WALLS) / (sizeof(int)*4); i++)
    {
        walls.push_back(EntityFactory::CreateWall(
            { (float) LEVEL1_WALLS[i][0] * (float)TILE_SIZE, (float)LEVEL1_WALLS[i][1] * (float)TILE_SIZE }, { (float)LEVEL1_WALLS[i][2] * (float)TILE_SIZE,(float)LEVEL1_WALLS[i][3] * (float)TILE_SIZE })
        );
    }
    player = EntityFactory::CreateHero(CharacterType::WIZZARD, { 100, 100 });
    enemies.push_back(EntityFactory::CreateEnemy(CharacterType::BIG_ZOMBIE, { 350, 100 }));
    enemies.push_back(EntityFactory::CreateEnemy(CharacterType::ORC_SHAMAN, { 350, 350 }));
    enemies.push_back(EntityFactory::CreateEnemy(CharacterType::SKELET,     { 250, 100 }));
    enemies.push_back(EntityFactory::CreateEnemy(CharacterType::MASKED_ORC, { 270, 100 }));
}
