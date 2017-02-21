#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Background.h"
#include "Character.h"
#include "KeyPressed.h"
#include "Mouse.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

TTF_Font* font;
SDL_Texture* solidTexture;
SDL_Rect solidRect;
SDL_Color color = { 255, 255, 255, 255 };

SDL_Texture* SurfaceToTexture(SDL_Surface* surface);

SDL_Texture* SurfaceToTexture(SDL_Surface* surface)
{
    SDL_Texture* text;

    text = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    return text;
}

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

    if ( TTF_Init() == -1 )
	{
		std::cout << " Error de Inicializacion TTF: " << SDL_GetError() << std::endl;
		return false;
    }

    Background* background = new Background(renderer, "rectangle2.png", 0, 0, 1200, 600);

    string font_name = "Vera.ttf";

    //---------------------------
    font = TTF_OpenFont(font_name.c_str(), 90);
    SDL_Surface* solid = TTF_RenderText_Solid(font, "Hello World", color);
    solidTexture = SurfaceToTexture(solid);
    SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
    solidRect.x = 0;
    solidRect.y = 0;
    //---------------------------

    while( 1 )
    {
        while( SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                return 0;
        }

        SDL_RenderClear(renderer);
        background->showBackground(renderer);

        SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
        SDL_RenderPresent(renderer);
    }

    return 0;
}
