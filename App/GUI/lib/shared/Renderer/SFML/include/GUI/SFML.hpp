/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/SFMLClient.hpp"
#include "GUI/KeyBoard.hpp"
#include "GUI/Constant.hpp"

namespace gui {

class SFML : public IRenderer {

        public:

            SFML() = default;
            ~SFML() override = default;

            void setFPS(const unsigned int FPS) override { m_window.setFramerateLimit(FPS); };

            [[nodiscard]] std::string getPluginName() const override { return PLUGIN_RENDERER_SFML.data(); };
            [[nodiscard]] IClient& getClient() override { return m_client; };
            [[nodiscard]] KeyBoard::Key getEvents() override;
            [[nodiscard]] bool isRunning() const override { return m_window.isOpen() && m_isConnected; };

            void init(std::pair<unsigned int, unsigned int> resolution, const std::string &name) override;
            void close() override { m_window.close(); getClient().disconnect(); };
            void render() override;

            static KeyBoard::Key getKeyboardEvent(const sf::Event &event);
            bool checkConnection(sf::Clock clock);

        private:

            sf::RenderWindow m_window;
            SFMLClient m_client;
            bool m_isConnected{true};
            sf::Clock m_timeoutClock;
            bool m_connectionReceived{false};

    }; // class SFML

} // namespace sfml
