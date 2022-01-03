#include <iostream>
#include <algorithm>
#include "SDL.h"
#include <math.h>
#undef main

#include "src/view/Rendering.h"
#include "src/algebra/Transform.h"

#define SCREEN_WIDTH    1200
#define SCREEN_HEIGHT   1000


bool quit = false;

void topViewport(SDL_Renderer* SDL, Rendering& rendering, Matrix& obj){
    //Top left corner viewport
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH / 2;
    topLeftViewport.h = SCREEN_HEIGHT / 2;

//    rendering.setCenter({static_cast<double>(topLeftViewport.w/2), static_cast<double>(topLeftViewport.h/2), static_cast<double>(topLeftViewport.w/2)});
    rendering.drawAxis( 400, 400, 20);
    rendering.setPerspective(Rendering::Perspective::FRONT);
    rendering.drawMatrix(obj);
    SDL_SetRenderDrawColor(SDL, 255, 0, 0, 255);
    SDL_RenderDrawLine(SDL, topLeftViewport.x+1, topLeftViewport.y-1, topLeftViewport.x+topLeftViewport.w+1, topLeftViewport.y-1);
    SDL_RenderDrawLine(SDL, topLeftViewport.x+1, topLeftViewport.y-1, topLeftViewport.x+1, topLeftViewport.y - topLeftViewport.h);
    SDL_RenderDrawLine(SDL, topLeftViewport.x, topLeftViewport.y - topLeftViewport.h, topLeftViewport.x+topLeftViewport.w, topLeftViewport.y - topLeftViewport.h);

    SDL_RenderSetViewport( SDL, &topLeftViewport );
}
void sideViewport(SDL_Renderer* SDL, Rendering& rendering, Matrix& obj){
    SDL_Rect topRightViewport;
    topRightViewport.x = SCREEN_WIDTH / 2;
    topRightViewport.y = 0;
    topRightViewport.w = SCREEN_WIDTH / 2;
    topRightViewport.h = SCREEN_HEIGHT / 2;

//    rendering.setCenter({static_cast<double>(topRightViewport.w/2), static_cast<double>(topRightViewport.h/2), static_cast<double>(topRightViewport.w/2)});

    rendering.drawAxis( 400, 400, 20);
    rendering.setPerspective(Rendering::Perspective::TOP);
    rendering.drawMatrix(obj);
    SDL_SetRenderDrawColor(SDL, 255, 0, 0, 255);
    SDL_RenderDrawLine(SDL, topRightViewport.x+1, topRightViewport.y-1, topRightViewport.x+topRightViewport.w+1, topRightViewport.y-1);
    SDL_RenderDrawLine(SDL, topRightViewport.x+1, topRightViewport.y-1, topRightViewport.x+1, topRightViewport.y - topRightViewport.h);
    SDL_RenderDrawLine(SDL, topRightViewport.x, topRightViewport.y - topRightViewport.h, topRightViewport.x+topRightViewport.w, topRightViewport.y - topRightViewport.h);

    SDL_RenderSetViewport( SDL, &topRightViewport );
}
void frontViewport(SDL_Renderer* SDL, Rendering& rendering, Matrix& obj){
    //Bottom viewport
    SDL_Rect bottomViewport;
    bottomViewport.x = 0;
    bottomViewport.y = SCREEN_HEIGHT / 2;
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 2;


//    rendering.setCenter({static_cast<double>(bottomViewport.w/2), static_cast<double>(bottomViewport.h/2), static_cast<double>(bottomViewport.w/2)});
    rendering.drawAxis( 400, 400, 20);

    rendering.setPerspective(Rendering::Perspective::SIDE);
    rendering.drawMatrix(obj);
    SDL_SetRenderDrawColor(SDL, 0, 255, 0, 255);
    SDL_RenderDrawLine(SDL, bottomViewport.x+1, bottomViewport.y-1, bottomViewport.x+bottomViewport.w+1, bottomViewport.y-1);
    SDL_RenderDrawLine(SDL, bottomViewport.x+1, bottomViewport.y-1, bottomViewport.x+1, bottomViewport.y - bottomViewport.h);
    SDL_RenderDrawLine(SDL, bottomViewport.x, bottomViewport.y - bottomViewport.h, bottomViewport.x+bottomViewport.w, bottomViewport.y - bottomViewport.h);



    SDL_RenderSetViewport( SDL, &bottomViewport );
}

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


void renderObjects(Rendering& rendering, SDL_Renderer* SDL, Transform& transform){
    //TODO: Class that owns and manipulates the objects.
    Matrix A { {{30, 50, 50, 30, 30, 50, 50, 30},
                       {50, 50, 30, 30, 50, 50, 30, 30},
                       {10, 10, 10, 10, 40, 40, 40, 40},
                       {1,   1,  1, 1, 1, 1, 1, 1}}};
    transform.apply(A);

    SDL_SetRenderDrawColor(SDL, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(SDL);
//    rendering.drawGrid(20,20,1200);

    topViewport(SDL, rendering, A);
    frontViewport(SDL, rendering, A);
    sideViewport(SDL, rendering, A);


    SDL_RenderPresent(SDL);

}

void processEvents(SDL_Event& event, Transform& transform){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                //scale
                case SDLK_KP_8: transform.scale({1,1.5,1});
                    break;
                case SDLK_KP_2: transform.scale({1,0.5,1});
                    break;
                case SDLK_KP_4: transform.scale({0.5,1,1});
                    break;
                case SDLK_KP_6: transform.scale({1.5,1,1});
                    break;
                case SDLK_KP_7: transform.scale({1,1,0.5});
                    break;
                case SDLK_KP_9: transform.scale({1,1,1.5});
                    break;
                case SDLK_KP_1: transform.scale({1.5,1.5,1.5});
                    break;
                case SDLK_KP_3: transform.scale({0.5,0.5,0.5});
                    break;


                //translate
                case SDLK_w: transform.translate({0,1,0});
                    break;
                case SDLK_a:transform.translate({-1,0,0});
                    break;
                case SDLK_s: transform.translate({0,-1,0});
                    break;
                case SDLK_d: transform.translate({1,0,0});
                    break;
                case SDLK_q: transform.translate({0,0,-1});
                    break;
                case SDLK_e: transform.translate({0,0,1});
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
    renderer.setCenter({SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 4});
    Transform t;

    while(!quit)
    {
        SDL_Delay(20);
        renderObjects(renderer, SDL, t);
        SDL_Event event;
        processEvents(event, t);
    }

    SDL_DestroyRenderer(SDL);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

