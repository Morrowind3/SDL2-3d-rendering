#include <iostream>
#include <algorithm>
#include "SDL.h"
#undef main

#include "src/view/Rendering.h"
#include "src/algebra/Transform.h"
#include "src/model/World.h"
#include "src/input/Input.hpp"
#include "src/env.hpp"

bool quit = false;


void switchViewPort(SDL_Renderer* SDL, const SDL_Rect* viewport){
    SDL_RenderSetViewport( SDL, viewport);
    //put border around viewport;
    SDL_SetRenderDrawColor(SDL, 200, 200, 200, 255);
    SDL_RenderDrawRect(SDL, NULL);
}

SDL_Window* launch_window(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window *window = SDL_CreateWindow("Bethesda presents Starfield™ ALPHA RELEASE DO NOT LEAK!!!",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    }
    return window;
}

SDL_Renderer* launch_renderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    }
    return renderer;
}

int main(int argc, char *args[])
{
    SDL_Window *window = launch_window();
    SDL_Renderer* SDL = launch_renderer(window);

    std::shared_ptr<Rendering> renderer = std::make_shared<Rendering>(SDL);
    renderer->setCenter({SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 4});
    World world {renderer};

    static const SDL_Rect topLeftViewport {0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    static const SDL_Rect topRightViewport {SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    static const SDL_Rect bottomViewport {0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT /2};

    while(!quit)
    {
        SDL_Delay(10);
        Input::getInstance().update();
        world.onUpdate();
        SDL_SetRenderDrawColor(SDL, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(SDL);

        Transform t;

        renderer->setPerspective(Rendering::Perspective::CAMERA);
      //  switchViewPort(SDL, &bottomViewport);
        world.RenderObjects();

//        renderer->setPerspective(Rendering::Perspective::TOP);
//        switchViewPort(SDL, &topRightViewport);
//        world.RenderObjects();
//
//        renderer->setPerspective(Rendering::Perspective::SIDE);
//        switchViewPort(SDL, &topLeftViewport);
//        world.RenderObjects();

        SDL_RenderPresent(SDL);

//        SDL_Event event;
//        SDL_PollEvent(&event);
//        if(event.type == SDL_QUIT) quit = true;
    }

    SDL_DestroyRenderer(SDL);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

