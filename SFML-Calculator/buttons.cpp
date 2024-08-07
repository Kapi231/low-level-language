#include "buttons.hpp"
#include <SFML/Graphics.hpp>

sf::CircleShape CircleButton(float radius, float x, float y) {
  sf::CircleShape circle;
  circle.setRadius(radius);
  circle.setPosition(x, y);
  circle.setOutlineColor(sf::Color::Red);
  circle.setOutlineThickness(5);
  circle.setFillColor(sf::Color::Blue);

  return circle;
}
