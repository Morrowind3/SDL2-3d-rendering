#include <iostream>
#include <algorithm>
#include "SDL.h"
#undef main

#include "src/view/GraphPlotter.h"
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

void processEvents(SDL_Event& event){
    SDL_WaitEvent(&event);

    if(event.type == SDL_QUIT)
    {
        quit = true;
    }

}

int main(int argc, char *args[])
{
    SDL_Window *window = launch_window();
    SDL_Renderer* renderer = launch_renderer(window);
/* Creating the surface. */
    SDL_Surface *surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
    GraphPlotter plotter(renderer);
    plotter.setCenter(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

//    MathsVector A(180,180, "FFFB00FF");
//    MathsVector B(-120,140, "FF0000FF");
//    Matrix A { {{0, 20, 30, 40, 60, 40, 30, 20},
//                       {30, 40, 60, 40, 30, 20, 0, 20},
//                       {1, 1, 1, 1, 1, 1, 1, 1}}};

    Matrix A { {{30, 50, 50, 30},
                       {50, 50, 30, 30},
                       {1, 1, 1, 1}}};
    Transform t;
//    t.scale({4, 4}, 40, 40);
    t.rotate(45, 40, 40);
    t.apply(A);

    while(!quit)
    {
        SDL_Event e;
        processEvents(e);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        plotter.drawGrid(20,20,1200);
        plotter.drawAxis( 400, 400, 20);

        plotter.drawMatrix(A);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

