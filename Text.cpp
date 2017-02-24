#include "Text.h"

Text::Text(char* TTF_file, int font_size, SDL_Renderer* renderer)
{
    if(TTF_Init() == -1)
    {
        cout<<"Error al inicializar TTF"<<endl;
        return;
    }

    this->font = TTF_OpenFont(TTF_file, font_size);

    this->text = " ";
    this->rect.x = 0;
    this->rect.y = 0;
    this->color = { 0,0,0,0 };
    this->renderer = renderer;
}

char* Text::itoa(int number)
{
    static char buffer[32] = {0};

    int x;

    for(x = 30; number && x; --x, number /= 10)
    {
        buffer[x] = "0123456789"[number % 10];
    }

    return &buffer[x+1];
}

SDL_Texture* Text::surfaceToTexture(SDL_Surface* surface)
{
    SDL_Texture* text;

    text = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    return text;
}

void Text::positionOfTexture(int x, int y)
{
    this->rect.x = x;
    this->rect.y = y;
}

void Text::setColor(int C, int M, int Y, int K)
{
    this->color = { C, M, Y, K };
}

void Text::showText()
{
    this->surface = TTF_RenderText_Solid(this->font, this->text, this->color);
    this->texture = surfaceToTexture(surface);
    SDL_QueryTexture(this->texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(this->renderer, this->texture, NULL, &rect);
}

void Text::editText(char* text)
{
    this->text = text;
}

Text::~Text()
{
    //dtor
}
