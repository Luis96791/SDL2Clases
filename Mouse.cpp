#include "Mouse.h"


Mouse::Mouse()
{
    //ctor
}

bool Mouse::click(SDL_Event event, SDL_Rect rect, int button)
{
    if(event.button.button == button)
    {
        if(event.button.x >= rect.x && event.button.y >= rect.y
            && event.button.x <= (rect.x + rect.w) && event.button.y <= (rect.y + rect.h))
        {
            if(event.button.type == SDL_MOUSEBUTTONDOWN)
            {
                return true;
            }
        }
    }
    return false;
}

Mouse::~Mouse()
{
    //dtor
}
