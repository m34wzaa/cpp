#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
// make a tower defense game or smth
int main() {
    //code
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Sim");
    window.setFramerateLimit(60);
    Player player("hero", 100);
    sf::RectangleShape shape(sf::Vector2f(20.f, 20.f));
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.f);
    shape.setOrigin(10.f, 10.f);
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    sf::Text statusText;
    statusText.setFont(font);
    statusText.setCharacterSize(18);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(10.f, 10.f);
    while (window.isOpen() && player.isAlive()) {
        //equivalent of an anim loop, put all repeated code within this.
        sf::Event event;
        if (event.type == sf::Event::Closed) window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move( 2.0f,  0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) player.move(-2.0f,  0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up   )) player.move( 0.0f, -2.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down )) player.move( 0.0f,  2.0f);
        //add physics here later
        shape.setPosition(player.getX(), player.getY());
        statusText.setString( player.getName() + " | HP: " + std::to_string(static_cast<int>(100)) + " | Pos: (" + std::to_string(static_cast<int>(player.getX())) + ", " + std::to_string(static_cast<int>(player.getY())) + ")" );
        window.clear(sf::Color::Blue);
        window.draw(shape);
        window.draw(statusText);
        window.display();
    }
};