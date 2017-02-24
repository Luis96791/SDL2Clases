#include "Background.h"

/**
    \brief Crea un nuevo Background
*/
Background::Background(SDL_Renderer* renderer, char* name_texture, int x, int y, int w, int h)
{
    this->texture = IMG_LoadTexture(renderer, name_texture);
    this->rect_texture.x = x;
    this->rect_texture.y = y;
    this->rect_texture.w = w;
    this->rect_texture.h = h;
}

/**
    @param mostrar Background
*/
void Background::showBackground(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, this->texture, NULL, &this->rect_texture);
}

Background::~Background()
{
    SDL_DestroyTexture(this->texture);
}
