#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Text
{
    public:
        char *text;
        char *TTF_file;
        int font_size;
        SDL_Renderer* renderer;
        TTF_Font* font;
        SDL_Texture* texture;
        SDL_Surface* surface;
        SDL_Rect rect;
        SDL_Color color;
        char* intToChar(int number);
        SDL_Texture* surfaceToTexture(SDL_Surface* surface);
        void setPositionOfText(int x, int y);
        void setColor(int C, int M, int Y, int K);
        void setFontSize(int font_size);
        void showText();
        void editText(char* text);
        Text(char* TTF_file, SDL_Renderer* renderer);
        virtual ~Text();
    protected:
    private:
};

#endif // TEXT_H
