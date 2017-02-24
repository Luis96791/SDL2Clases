#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class Background
{
    public:
        SDL_Rect rect_texture;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
        int x, y, w, h;
        /**
            \brief Crea un fondo para la ventana(Constructor).
            \param SDL_Renderer* pasado de parametro a IMG_LoadTexture(SDL_Renderer*, char*)
            \param char* nombre de la imagen a mostrar
            \param int posicion en x
            \param int posicion en y
            \param int ancho
            \param int altura
        */
        Background(char* name_texture, SDL_Renderer* renderer);
        /**
            \brief Muestra el background en pantalla
        */
        void setPosition(int x, int y);
        void resizeBackground(int w, int h);
        void showBackground();
        virtual ~Background();
    protected:
    private:
};

#endif // BACKGROUND_H
