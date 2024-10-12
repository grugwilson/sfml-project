#include <iostream>
#include <SFML/Graphics.hpp>

sf::CircleShape drawCircle(float size, sf::Color colour, float posX, float posY)
{
    // draw a circle!!!
    sf::CircleShape circle(size);
    // set the shape color to green
    circle.setFillColor(colour);
    // sets position of shape
    circle.setPosition(posX / 2, posY);
    // draws shape!!!
    return circle;
}



int main()
{
    unsigned int windowWidth = 500u;
    unsigned int windowHeight = 500u;
    auto window = sf::RenderWindow{ { windowWidth, windowHeight}, "CMake SFML Project" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                {
                    window.close();
                }
            }


        }

        window.clear(sf::Color::Black);

        window.draw(drawCircle(50.f, sf::Color::Green, windowWidth/2 - 25.f, windowHeight/2 -25.f));
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
                rect.setFillColor(sf::Color(0,0,0));
                rect.setOutlineThickness(-5.f);
                rect.setOutlineColor(sf::Color(50,50,50));
                rect.setPosition(50.f*i,50.f*j);
                window.draw(rect);
            }
        }
        window.display();
    }
}
