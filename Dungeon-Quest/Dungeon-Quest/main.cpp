#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>

#include "src/Hero.h"
#include "src/Defines.h"


struct Window
{
    static inline float width, height;
};

struct MainMenuScreen
{
    sf::Texture titleTexture;
    sf::Sprite  titleSprite;
    sf::Texture backgroundTexture;
    sf::Sprite  backgroundSprite;

    MainMenuScreen()
    {
        ASSERT(titleTexture.loadFromFile("assets/title.png"), "Failed to load texture: assets/title.png");
        titleTexture.setSmooth(true);
        titleSprite.setTexture(titleTexture);
        titleSprite.setPosition({ Window::width / 2 - titleTexture.getSize().x / 2, Window::height / 2 - titleTexture.getSize().y / 2 });
        ASSERT(backgroundTexture.loadFromFile("assets/back.png"), "Failed to load texture: assets/back.png");
        backgroundTexture.setRepeated(true);
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.scale({ 5, 5 });
    }
};


int main(const int argc, const char** argv)
{
    sf::VideoMode desktop = sf::VideoMode().getFullscreenModes()[0];
    Window::width  = (float) desktop.width;
    Window::height = (float) desktop.height;
    sf::RenderWindow window(desktop, "Dungeon Quest!", sf::Style::None);

    HeroAssets::LoadHeroAssets();

    MainMenuScreen screen;
    PTR<Hero> a = HeroFactory::CreateHero(Hero::Type::KNIGHT, Window::width / 2 - 200, Window::height / 2 - 100);
    sf::Clock clock;
    sf::View view1(sf::FloatRect(0, 0, Window::width, Window::height));
    while (window.isOpen())
    {
        float delta = clock.restart().asSeconds();
     
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          //  a->setScale(sf::Vector2f(-10, 10));
            
            a->move({ -1, 0 });
            view1.move({ -1, 0 });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
         //   a->setScale(sf::Vector2f(10, 10));
            a->move({ 1, 0 });
            view1.move({ 1, 0 });
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            a->move({ 0, -1 });
            view1.move({ 0, -1 });
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            a->move({ 0, 1 });
            view1.move({ 0, 1 });
        }
       // a->Update(delta);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        //window.setView(view1);
      //  window.draw(screen.backgroundSprite);
        window.draw(*a);
      //  window.setView(window.getDefaultView());
      //  window.draw(screen.titleSprite);
        
        window.display();
    }

    return 0;
}