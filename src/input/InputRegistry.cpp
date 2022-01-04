#include "InputRegistry.hpp"
#include <algorithm>


// All keys that were pressed last frame are now in a held state
// All keys that were released last frame are now in an undetected state
void InputRegistry::flushForNextFrame() {
    for (auto& key : _keyStates) {
        if (key.second == PressState::PRESSED) key.second = PressState::HELD;
        if (key.second == PressState::RELEASED) key.second = PressState::UNDETECTED;
    }
}

void InputRegistry::storeKeyDown(KeyCode key) {
    // Key down event gets sent multiple times when key is held, which is useful in a text editor but not in a game
    if (keyStatus(key) != PressState::HELD) _keyStates[key] = PressState::PRESSED;
}

void InputRegistry::storeKeyUp(KeyCode key) {
    _keyStates[key] = PressState::RELEASED;
}

bool InputRegistry::anyKeyRegistered() const {
    return std::find_if(_keyStates.begin(),_keyStates.end(),
                        [](const auto& key){return key.second != PressState::UNDETECTED;}) == _keyStates.end();
}

bool InputRegistry::anyKeyInState(PressState state) const {
    return std::find_if(_keyStates.begin(),_keyStates.end(),
                        [state](const auto& key){return key.second == state;}) != _keyStates.end();
}

PressState InputRegistry::keyStatus(KeyCode key) const {
    auto keyIterator = _keyStates.find(key);
    return keyIterator != _keyStates.end() ? keyIterator->second : PressState::UNDETECTED;
}


