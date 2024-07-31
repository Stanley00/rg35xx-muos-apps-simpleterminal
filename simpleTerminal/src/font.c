#include <SDL/SDL.h>
#include "font.h"

#include <SDL/SDL_ttf.h>

static TTF_Font* font = NULL;
#define FONT_SIZE 14
#define FONT_NAME ".dingux/res/SourceCodePro-Regular.ttf"


void init_font(const char* name, int size)
{
    if (font) {
        TTF_CloseFont(font);
    }
    font = TTF_OpenFont(name, size);
}


void drawText_(char *text, SDL_Surface *screen, int x, int y, SDL_Color color)
{
    if (!font) {
        font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
    }
    SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, text, color);
    SDL_Rect dst = {x, y, 0, 0};
    SDL_BlitSurface(textSurface, NULL, screen, &dst);
    SDL_FreeSurface(textSurface);
}



void drawText(char *text, SDL_Surface *screen, int x, int y, SDL_Color color)
{
    // Split the text into lines. Change y based on font height
    char *textCopy = strdup(text);
    char *token;
    int fontHeight = TTF_FontHeight(font);
    while ((token = strsep(&textCopy, "\n"))) {
        if (strlen(token) > 0) {
            drawText_(token, screen, x, y, color);
        }
        y += fontHeight;
    }
    free(textCopy);

}

void font_size(const char* c, int* w, int* h)
{
    if (!font) {
        font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
    }
    TTF_SizeUTF8(font, c, w, h);
}
