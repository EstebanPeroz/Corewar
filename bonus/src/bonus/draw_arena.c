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

static sfText *init_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, CELL_SIZE - 3);
    sfText_setFillColor(text, sfWhite);
    return text;
}

void draw_champs(display_t *graphic, virtual_machine_t *vm)
{
    sfRectangleShape *cell = sfRectangleShape_create();
    sfText *text = init_text(graphic->font);
    sfVector2f size = {CELL_SIZE - 1, CELL_SIZE - 1};

    sfRectangleShape_setSize(cell, size);
    for (int i = 0; i < MEM_SIZE; i++) {
        draw_cell(i, text, vm, cell);
    }
    draw_pc(vm, cell, text);
    sfText_destroy(text);
    sfRectangleShape_destroy(cell);
}

int draw_arena(virtual_machine_t *vm, display_t *graphic)
{
    while (sfRenderWindow_pollEvent(graphic->window, &graphic->event)) {
            analyse_events(graphic, graphic->event);
        }
        sfRenderWindow_clear(graphic->window, sfBlack);
        graphic->sim_timer += graphic->sim_clock.seconds;
        graphic->sim_clock.seconds = sfClock_restart(graphic->
            sim_clock.clock).microseconds / 1000000.0;
        draw_champs(graphic, vm);
        sfRenderWindow_display(graphic->window);
    return 0;
}
