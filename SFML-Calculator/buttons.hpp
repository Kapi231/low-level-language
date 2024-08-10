#ifndef BUTTONS_H
#define BUTTONS_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

sf::CircleShape CircleButton(float radius, float x, float y);

sf::Text DisplayText(float size, float x, float y, std::string txt, sf::Font font);

#endif
