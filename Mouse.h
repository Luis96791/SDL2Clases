#ifndef MOUSE_H
#define MOUSE_H
#include "Character.h"
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Mouse
{
    public:
        Mouse();
        bool click(SDL_Event event, SDL_Rect rect, int button);
        virtual ~Mouse();
    protected:
    private:
};

#endif // MOUSE_H
