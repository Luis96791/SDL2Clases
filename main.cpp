#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Text.h"
#include "Background.h"
#include "Character.h"
#include "KeyPressed.h"
#include "Mouse.h"
#include "StringInput.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

bool collisionBetweenCharacters(SDL_Rect rect_character1, SDL_Rect rect_character2);

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

    Background* background = new Background("rectangle1.png", renderer);
    background->resizeBackground(1200, 600);

    Character* character1 = new Character(renderer, "flecha_arriba.png");
    character1->setPositionOfCharacter(60, 90);

    Character* character2 = new Character(renderer, "flecha_arriba.png");
    character2->setPositionOfCharacter(160, 90);


    Text* text = new Text("Vera.ttf",renderer);
    text->editText("Colision");
    text->setColor(100, 100, 100, 100);
    text->setPositionOfText(90, 20);
    text->setFontSize(38);

    while( 1 )
    {
        while( SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                return 0;
        }
        character1->moveToRight(1, SDL_SCANCODE_D); //*SDL_SCANCODE siempre
        character1->moveToLeft(1, SDL_SCANCODE_A);
        character1->moveToUp(1, SDL_SCANCODE_W);
        character1->moveToDown(1, SDL_SCANCODE_S);

        character2->moveToRight(1, SDL_SCANCODE_RIGHT);
        character2->moveToLeft(1, SDL_SCANCODE_LEFT);
        character2->moveToUp(1, SDL_SCANCODE_UP);
        character2->moveToDown(1, SDL_SCANCODE_DOWN);


        SDL_RenderClear(renderer);
        background->showBackground();
        character1->showCharacter();
        character2->showCharacter();

        if(collisionBetweenCharacters(character1->rect_character, character2->rect_character))
        {
            text->showText();
        }

        SDL_RenderPresent(renderer);
    }

    return 0;
}

bool collisionBetweenCharacters(SDL_Rect rect_character1, SDL_Rect rect_character2)
{
    if(rect_character1.x > (rect_character2.x+rect_character2.h))
        return false;

    if((rect_character1.x+rect_character1.h) < rect_character2.x)
        return false;

    if(rect_character1.y < (rect_character2.y-rect_character2.w))
        return false;

    if((rect_character1.y-rect_character1.w) > rect_character2.y)
        return false;

    return true;
}
