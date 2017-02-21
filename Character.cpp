#include "Character.h"

Character::Character(SDL_Renderer* renderer, char* name_character, int x, int y, int w, int h)
{
    this->texture = IMG_LoadTexture(renderer, name_character);
    this->rect_character.x = x;
    this->rect_character.y = y;
    this->rect_character.w = w;
    this->rect_character.h = h;
    this->state = SDL_GetKeyboardState(NULL);
}

int Character::getRectPositionX()
{
    return this->rect_character.x;
}

void Character::moveToRight(int move_units, SDL_Keycode keycode)
{
    if(this->state[keycode])
    {
        this->rect_character.x += move_units;
    }
}

void Character::moveToLeft(int move_units, SDL_Keycode keycode)
{
    if(this->state[keycode])
    {
        this->rect_character.x -= move_units;
    }
}

void Character::moveToUp(int move_units, SDL_Keycode keycode)
{
    if(this->state[keycode])
    {
        this->rect_character.y -= move_units;
    }
}

void Character::moveToDown(int move_units, SDL_Keycode keycode)
{
    if(this->state[keycode])
    {
        this->rect_character.y += move_units;
    }
}

bool Character::collisionWithBorder(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, string direction)
{

    if(direction == "UP")
    {
        return collisionUp();
    }

    if(direction == "DOWN")
    {
        return collisionDown(WINDOW_HEIGHT);
    }

    if(direction == "RIGHT")
    {
        return collisionRight(WINDOW_WIDTH);
    }

    if(direction == "LEFT")
    {
        return collisionLeft();
    }

    if(direction == "DEFAULT")
    {
        if(collisionUp() || collisionDown(WINDOW_HEIGHT) || collisionLeft() || collisionRight(WINDOW_WIDTH))
        {

            return true;
        }
    }
    return false;
}

bool Character::collisionUp()
{
    if(rect_character.y < 0)
    {
        return true;
    }
    return false;
}

bool Character::collisionDown(const int WINDOW_HEIGHT)
{
    if(rect_character.y > (WINDOW_HEIGHT-rect_character.h))
    {
        return true;
    }
    return false;
}

bool Character::collisionRight(const int WINDOW_WIDTH)
{
    if(rect_character.x > (WINDOW_WIDTH-rect_character.w))
    {
        return true;
    }
    return false;
}

bool Character::collisionLeft()
{
    if(rect_character.x < 0)
    {
        return true;
    }
    return false;
}

void Character::rotation(int velocity, string orientation)
{

}

void Character::showCharacter(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, this->texture, NULL, &this->rect_character);
}

Character::~Character()
{
    SDL_DestroyTexture(this->texture);
}
