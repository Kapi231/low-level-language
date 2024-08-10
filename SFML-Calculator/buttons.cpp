#include "buttons.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

sf::CircleShape CircleButton(float radius, float x, float y) 
{
  //GUI
  sf::CircleShape circle;
  circle.setRadius(radius);
  circle.setPosition(x, y);
  circle.setOutlineColor(sf::Color::Red);
  circle.setOutlineThickness(5);
  circle.setFillColor(sf::Color::Blue);

  return circle;
}

sf::Text DisplayText(float size, float x, float y, std::string txt, sf::Font font) 
{
  sf::Text text;
  text.setCharacterSize(size);
  text.setFont(font);
  text.setString(txt);
  text.setPosition(x, y);

  return text;
}
