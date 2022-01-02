#include <iostream>
#include <algorithm>
#include "SDL.h"
#undef main

#include "src/view/Rendering.h"
#include "src/algebra/Transform.h"

#define SCREEN_WIDTH    1200
#define SCREEN_HEIGHT   1200


bool quit = false;

SDL_Window* launch_window(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    // Create window
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


void renderObjects(Rendering& rendering, SDL_Renderer* SDL){
    //TODO: Class that owns and manipulates the objects.
    Matrix A { {{30, 50, 50, 30, 30, 50, 50, 30},
                       {50, 50, 30, 30, 50, 50, 30, 30},
                       {10, 10, 10, 10, 40, 40, 40, 40},
                       {1,   1,  1, 1, 1, 1, 1, 1}}};
    Transform t;
//    t.scale({3,6,3}, {40,40,15});
    t.apply(A);

    SDL_SetRenderDrawColor(SDL, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(SDL);
    rendering.drawGrid(20,20,1200);
    rendering.drawAxis( 400, 400, 20);
    rendering.drawMatrix(A);

    SDL_RenderPresent(SDL);

}

void processEvents(SDL_Event& event, Rendering& renderer){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_1: renderer.setPerspective(Rendering::Perspective::FRONT);
                break;
                case SDLK_2: renderer.setPerspective(Rendering::Perspective::SIDE);
                break;
                case SDLK_3: renderer.setPerspective(Rendering::Perspective::TOP);
                break;
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *args[])
{
    SDL_Window *window = launch_window();
    SDL_Renderer* SDL = launch_renderer(window);

    Rendering renderer(SDL);
    renderer.setCenter({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2});

    while(!quit)
    {
        SDL_Delay(20);
        Uint64 start = SDL_GetPerformanceCounter();
        renderObjects(renderer, SDL);

        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        // Cap to 60 FPS
        SDL_Delay(floor(16.666f - elapsedMS));

        SDL_Event event;
        processEvents(event, renderer);
    }

    SDL_DestroyRenderer(SDL);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

