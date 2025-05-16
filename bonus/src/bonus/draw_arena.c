/*
** EPITECH PROJECT, 2025
** Coreware bonus
** File description:
** Draw arena
*/
#include <SFML/Graphics.h>
#include "corewar.h"

int draw_arena(virtual_machine_t *vm, display_t *graphic)
{
    while (sfRenderWindow_pollEvent(graphic->window, &(graphic->event))){
            analyse_events(graphic, graphic->event);
        }
        sfRenderWindow_clear(graphic->window, sfBlack);
        graphic->sim_timer += graphic->sim_clock.seconds;
        graphic->sim_clock.seconds = sfClock_restart(graphic->
            sim_clock.clock).microseconds / 1000000.0;
        sfRenderWindow_display(graphic->window);
    return 0;
}
