#ifndef HEADER_INTERFACE_FUNCTIONS_H_INCLUDED
#define HEADER_INTERFACE_FUNCTIONS_H_INCLUDED

#include "constants.h"
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

/** base_functions.c **/
void mgotoxy (const int x, const int y);
void setColor (const int x);
void setSize (const int width, const int height);
void screenSize (const int x, const int y);
void hideCursor(bool hide);
void presets (char title[], const int color, const int width, const int heigth, bool cursor);

/** dynamic_menu.c **/
int dynamic_menu (const char* OPCS, const char* TITLE, int x, const int y, const int WIDTH, const int HEIGHT);

/** presets.c **/
int presset_main();

/** sounds.c **/
void boot_sound();
void closing_sound();
void error_sound();
void success_sound();

/** template.c **/
void simple_box(int const X, int const Y, int const WIDTH, int const HEIGTH, const char* TITLE, int const color_body, int const color_title, bool shadow);
void textViewBox (int const X, int const Y, int const WIDTH, int const HEIGTH, const char* TITLE, int const color_body, int const color_title, bool shadow, const char* text);
char* textBox (int const X, int const Y, int const WIDTH, int const HEIGTH, char const TITLE[], int const color_body, int const color_title, bool shadow);
void thin_edge (int const WIDTH, int const HEIGHT, int const X, int const Y, const char* TITLE, int const color_body, int const color_title);
char* editTextBox(const int X, const int Y, const char* varChar, const int charLimit, char* text, int const color_current_background);

#endif // HEADER_INTERFACE_FUNCTIONS_H_INCLUDED
