#ifndef __FONT_H__
#define __FONT_H__

void init_font(const char* name, int size);
void draw_char(SDL_Surface* surface, unsigned char symbol, int x, int y, unsigned short color);
void draw_string(SDL_Surface* surface, const char* text, int x, int y, unsigned short color);
void draw_string_s(SDL_Surface* surface, const char* text, int x, int y, unsigned short color);
void drawText(char *text, SDL_Surface *screen, int x, int y, SDL_Color color);
void font_size(const char* c, int* w, int* h);
#endif
