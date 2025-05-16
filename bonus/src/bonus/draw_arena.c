/*
** EPITECH PROJECT, 2025
** Coreware bonus
** File description:
** Draw arena
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Sleep.h>
#include <SFML/System/Time.h>
#include "corewar.h"
#include "op.h"

void draw_champs(display_t *graphic, virtual_machine_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        draw_cell(i, vm->display->text, vm, vm->display->cell);
    }
    draw_pc(vm, graphic->cell, vm->display->text);
}

int draw_arena(virtual_machine_t *vm, display_t *graphic, int cycles)
{
    while (sfRenderWindow_pollEvent(graphic->window, &graphic->event)) {
            analyse_events(graphic, graphic->event);
        }
        sfRenderWindow_clear(graphic->window, sfBlack);
        graphic->sim_timer += graphic->sim_clock.seconds;
        graphic->sim_clock.seconds = sfClock_restart(graphic->
            sim_clock.clock).microseconds / 1000000.0;
        draw_champs(graphic, vm);
        draw_text(vm, cycles);
    sfRenderWindow_display(graphic->window);
    return 0;
}
