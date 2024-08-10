#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>

#include "buttons.hpp"

int main() 
{
  sf::RenderWindow window(sf::VideoMode(300, 150), "Calculator");
  sf::Font font;
  font.loadFromFile("Fonts/static/OpenSans-Medium.ttf");

    while (window.isOpen()) 
    {
    sf::Event event;
    
    //While there is event called
    while (window.pollEvent(event)) 
    {
      //If event type is to close window
      if (event.type == sf::Event::Closed) 
      {
        window.close();
      }
    }

  window.clear();
  window.draw(CircleButton(25, 10, 10));
  window.draw(DisplayText(10, 10, 10, "1",font));  
    //Update window changes
  window.display();
  }
}
