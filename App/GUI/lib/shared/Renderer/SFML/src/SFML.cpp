/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include "GUI/SFML.hpp"

static gui::KeyBoard::Key KEY_CODE_ARRAY[sf::Keyboard::KeyCount];

gui::KeyBoard::Key gui::SFML::getKeyboardEvent(const sf::Event &event)
{
    return event.key.code >= sf::Keyboard::KeyCount ? gui::KeyBoard::Key::NONE : KEY_CODE_ARRAY[event.key.code];
}

void gui::SFML::init(const std::string &name, std::pair<const unsigned int,const unsigned int> resolution, const unsigned int bitsPerPixel)
{
    std::fill_n(KEY_CODE_ARRAY, sf::Keyboard::KeyCount, KeyBoard::Key::NONE);
    KEY_CODE_ARRAY[sf::Keyboard::Escape] = KeyBoard::Key::KEY_ESCAPE;
    KEY_CODE_ARRAY[sf::Keyboard::Enter] = KeyBoard::Key::KEY_ENTER;
    KEY_CODE_ARRAY[sf::Keyboard::Left] = KeyBoard::Key::KEY_LEFT;
    KEY_CODE_ARRAY[sf::Keyboard::Right] = KeyBoard::Key::KEY_RIGHT;
    KEY_CODE_ARRAY[sf::Keyboard::Up] = KeyBoard::Key::KEY_UP;
    KEY_CODE_ARRAY[sf::Keyboard::Down] = KeyBoard::Key::KEY_DOWN;
    KEY_CODE_ARRAY[sf::Keyboard::Space] = KeyBoard::Key::KEY_SPACE;

    m_window.create(sf::VideoMode(resolution.first, resolution.second, bitsPerPixel), name, sf::Style::Resize | sf::Style::Close);
    m_timeoutClock.restart();
}

bool gui::SFML::checkConnection(sf::Clock clock)
{
    if (!getClient().isConnected()) {
        clock.restart();
        while (clock.getElapsedTime().asSeconds() < TIMEOUT) {
            if (getClient().isConnected()) {
                return true;
            }
        }
        return false;
    }
    return true;
}

void gui::SFML::render()
{
    m_window.display();
    m_window.clear({0, 0, 0, 0});
}
