/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** IRenderer
*/

#pragma once

#include "GUI/Abstraction/IPlugin.hpp"
#include "GUI/Abstraction/IClient.hpp"
#include "GUI/KeyBoard.hpp"
#include "GUI/Map/Map.hpp"
#include "GUI/Egg.hpp"
#include "GUI/Player.hpp"

namespace gui {

    class IRenderer : public IPlugin {

        public:

            virtual void setFPS(unsigned int FPS) = 0;

            [[nodiscard]] virtual IClient& getClient() = 0;
            [[nodiscard]] virtual bool isRunning() = 0;

            virtual void init(const std::string &name, std::pair<const unsigned int,const unsigned int> resolution, unsigned int bitsPerPixel) = 0;
            virtual void render(Map &map, std::vector<Egg> &egg, std::vector<Player> &players, std::vector<std::string> &teamNames, bool animations) = 0;
            [[nodiscard]]

            virtual KeyBoard::Key getEvents() = 0;
            virtual void close() = 0;

    }; // class IRenderer

} // namespace gui
