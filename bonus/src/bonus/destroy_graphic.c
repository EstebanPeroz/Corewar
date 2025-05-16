/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Destroy graphics
*/
#include "corewar.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Clock.h>

void destroy_graphic(display_t *display)
{
    sfRenderWindow_destroy(display->window);
    sfClock_destroy(display->sim_clock.clock);
    sfFont_destroy(display->font);
    sfText_destroy(display->text);
    sfRectangleShape_destroy(display->cell);
    free(display);
}
