#include "Input.hpp"
#include <algorithm>
#include <SDL.h>

void Input::update() {
    _registry.flushForNextFrame();
    registerEvents();
}

void Input::registerEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) _registry.storeKeyDown(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_KEYUP) _registry.storeKeyUp(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_QUIT) exit(0);
    }
}

// Gets

bool Input::anyKeyUp() const {
    return _registry.anyKeyInState(PressState::RELEASED);
}

bool Input::anyKeyDown() const {
    return _registry.anyKeyInState(PressState::PRESSED);
}

bool Input::getKey(KeyCode code) const {
    return _registry.keyStatus(code) != PressState::UNDETECTED;
}

bool Input::getKeyUp(KeyCode code) const {
    return _registry.keyStatus(code) == PressState::RELEASED;
}

bool Input::getKeyDown(KeyCode code) const {
    return _registry.keyStatus(code) == PressState::PRESSED;
}


