#include "Background.h"

/**
    \brief Crea un nuevo Background
*/
Background::Background(char* name_texture, SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->texture = IMG_LoadTexture(this->renderer, name_texture);
    this->rect_texture.x = 0;
    this->rect_texture.y = 0;
    this->rect_texture.w = 200;
    this->rect_texture.h = 200;
}

void Background::setPosition(int x, int y)
{
    this->rect_texture.x = x;
    this->rect_texture.y = y;
}

void Background::resizeBackground(int w, int h)
{
    this->rect_texture.w = w;
    this->rect_texture.h = h;
}

/**
    @param mostrar Background
*/
void Background::showBackground()
{
    SDL_RenderCopy(this->renderer, this->texture, NULL, &this->rect_texture);
}

Background::~Background()
{
    SDL_DestroyTexture(this->texture);
}
