#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Text.h"
#include "Background.h"
#include "Character.h"
#include "KeyPressed.h"
#include "Mouse.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

int main()
{

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        exit(1);
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 0;
    if((window = SDL_CreateWindow("Background's", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
        return 0;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == NULL)
    {
        cout<< SDL_GetError() <<endl;
        return 0;
    }

    Background* background = new Background(renderer, "rectangle2.png", 0, 0, 1200, 600);
    Text* text = new Text("Vera.ttf", 30, renderer);
    text->editText("Hello World...!");
    text->setColor(120, 56, 96, 0);
    text->positionOfTexture(90, 20);

    while( 1 )
    {
        while( SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                return 0;
        }

        SDL_RenderClear(renderer);
        background->showBackground(renderer);
        text->showText();

        SDL_RenderPresent(renderer);
    }

    return 0;
}
