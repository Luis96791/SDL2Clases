#ifndef STRINGINPUT_H
#define STRINGINPUT_H
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class StringInput
{
    public:
        string str;
        SDL_Surface *text;
        SDL_Event event;
        StringInput();
        void ingresarTexto();
        virtual ~StringInput();
    protected:
    private:
};

#endif // STRINGINPUT_H
