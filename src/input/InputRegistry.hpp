#ifndef GOAT_ENGINE_INPUTREGISTRY_HPP
#define GOAT_ENGINE_INPUTREGISTRY_HPP

#include "PressState.hpp"
#include "KeyCode.hpp"
#include <map>

// Only callable by input
    class InputRegistry {
        friend class Input;
        InputRegistry() = default;
        void flushForNextFrame();
        void storeKeyDown(KeyCode key);
        void storeKeyUp(KeyCode key);
        [[nodiscard]] bool anyKeyRegistered() const;
        [[nodiscard]] bool anyKeyInState(PressState state) const;
        [[nodiscard]] PressState keyStatus(KeyCode key) const;
        [[nodiscard]] bool anyMouseRegistered() const;
        [[nodiscard]] bool anyMouseInState(PressState state) const;
        std::map<KeyCode,PressState> _keyStates {};
    };

#endif //GOAT_ENGINE_INPUTREGISTRY_HPP
