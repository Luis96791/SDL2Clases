#ifndef KEYPRESSED_H
#define KEYPRESSED_H
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class KeyPressed
{
    public:
        SDL_Event event;
        SDL_Keycode keyCode;
        KeyPressed(SDL_Event event, SDL_Keycode keyCode);
        void tecla();
        virtual ~KeyPressed();
    protected:
    private:
};

#endif // KEYPRESSED_H
