#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Calculator");

  while (window.isOpen()) {
    sf::Event event;
    
    //While there is event called
    while (window.pollEvent(event)) {
      //If event type is to close window
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    window.display();
  }
}
