#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>

#include "buttons.hpp"

int fixedX = 10;

int main() 
{
  sf::CircleShape tabel[3];
  sf::RenderWindow window(sf::VideoMode(640, 480), "Calculator");
  sf::Font font;
  font.loadFromFile("Fonts/static/OpenSans-Medium.ttf");

  for (int i = 0; i < 3; i++) 
    {
      tabel[i] = CircleButton(25, fixedX, 10);
      fixedX += 40;
    }

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
  //  window.draw(CircleButton(25, 10, 10));
  //  window.draw(DisplayText(10, 10, 10, "1",font));  
    
    for (int x = 0; x < 3; x++) 
    {
      window.draw(tabel[x]);
    } 

      //Update window changes
    window.display();
  }
}
