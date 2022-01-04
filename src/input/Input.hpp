#ifndef GOAT_ENGINE_INPUT_HPP
#define GOAT_ENGINE_INPUT_HPP

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <map>
#include <vector>
#include "KeyCode.hpp"
#include "InputRegistry.hpp"

    class Input {
        public:
            Input(Input const&) = delete;
            void operator=(Input const&) = delete;
            static Input& getInstance() {
                static Input instance;
                return instance;
            }

            // input
            void update();
            // Keyboard
            [[nodiscard]] bool anyKey() const;
            [[nodiscard]] bool anyKeyUp() const;
            [[nodiscard]] bool anyKeyDown() const;
            [[nodiscard]] bool getKey(KeyCode code) const;
            [[nodiscard]] bool getKeyUp(KeyCode code) const;
            [[nodiscard]] bool getKeyDown(KeyCode code) const;


        private:
            // Singleton
            Input()= default;
            // Globals
            // input state
            InputRegistry _registry{};
            int _mousePositionX{}, _mousePositionY{};
            // Helper methods
            void registerEvents();
        };
#endif //GOAT_ENGINE_INPUT_HPP