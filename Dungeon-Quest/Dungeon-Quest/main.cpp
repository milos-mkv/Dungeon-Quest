
#include "src/Game.h"

int main(const int argc, const char** argv)
{
    Game().Run();
    return 0;
}








/*


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>

#include "src/Hero.h"
#include "src/Defines.h"
#include <vector>
#include "src/Collision.hpp"

struct Window
{
    static inline float width, height;
};

#include "src/Camera.h"

#define TILE_SIZE 16
#define VIEWPORT_WIDTH  247 * 1.1
#define VIEWPORT_HEIGHT 135 * 1.1

int main(const int argc, const char** argv)
{
    sf::VideoMode vm = sf::VideoMode().getDesktopMode();
    Window::width  = (float)vm.width;
    Window::height = (float)vm.height;
    sf::RenderWindow window(vm, "Dungeon Quest!", sf::Style::None);
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);

    HeroAssets::LoadHeroAssets();
    PTR<Hero> hero = HeroFactory::CreateHero(Hero::Type::KNIGHT, VIEWPORT_WIDTH / 2, VIEWPORT_HEIGHT / 2);
    hero->SetState(Hero::State::RUN);

    sf::Texture curTex;
    curTex.loadFromFile("assets/frames/weapon_regular_sword.png");
    curTex.setRepeated(true);
    sf::Sprite cur;
    cur.setTexture(curTex);
    
    std::vector<CollisionBox> walls;
   // walls.push_back()
    walls.push_back(CollisionBox(TILE_SIZE *3, TILE_SIZE *2, TILE_SIZE *10, TILE_SIZE));


    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/level1.png");
    backgroundTexture.setRepeated(true);
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    sf::Clock clock;

    sf::CircleShape shape(16);

    shape.setOutlineThickness(0.5f);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color(0, 255, 0));

    Camera camera(0, 0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    float time = 0;
    int FPS = 0;

    while (window.isOpen())
    {
        FPS++;
        if (time >= 1)
        {
            std::cout << FPS << std::endl;
            time = 0;
            FPS = 0;
        }
        float delta = clock.restart().asSeconds();
        time += delta;
        camera.ProcessInput(delta, hero->speed);
        hero->Update(delta);
        shape.setPosition({ hero->getPosition().x - 8, hero->getPosition().y });
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);
        window.setView(camera);
        window.draw(background);
        window.draw(*hero);
        cur.setPosition({ camera.GetCursorPos().x , camera.GetCursorPos().y });
        window.draw(cur);
        window.draw(walls[0].shape);
      //  window.setView(window.getDefaultView());
        window.display();
    }

    return 0;
}*/