#ifndef CHARACTER_H
#define CHARACTER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class Character
{
    public:
        SDL_Rect rect_character;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
        const Uint8* state;
        int x, y, w, h;

        Character(SDL_Renderer* renderer, char* name_character);
        void setPositionOfCharacter(int x, int y);
        void setSize(int w, int h);
        void showCharacter();
        void moveToRight(int move_units, SDL_Keycode keycode);
        void moveToLeft(int move_units, SDL_Keycode keycode);
        void moveToUp(int move_units, SDL_Keycode keycode);
        void moveToDown(int move_units, SDL_Keycode keycode);
        int getRectPositionX();
        bool collisionWithBorder(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, string direction);
        bool collisionBetweenCharacters(SDL_Rect rect_character1, SDL_Rect rect_character2);
        virtual ~Character();
    protected:
    private:
        bool collisionUp();
        bool collisionDown(const int WINDOW_HEIGHT);
        bool collisionRight(const int WINDOW_WIDTH);
        bool collisionLeft();
};

#endif // CHARACTER_H
