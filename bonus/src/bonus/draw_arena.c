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

static sfColor set_color(unsigned char *owner_map, int i)
{
    sfColor color = sfColor_fromRGB(50, 50, 50);

    if (owner_map[i] == 1)
        color = sfColor_fromRGB(150, 0, 0);
    if (owner_map[i] == 2)
        color = sfColor_fromRGB(0, 132, 0);
    if (owner_map[i] == 3)
        color = sfBlue;
    if (owner_map[i] == 4)
        color = sfColor_fromRGB(117, 0, 135);
    return color;
}

void draw_cell(int i, sfText *text,
    virtual_machine_t *vm, sfRectangleShape *cell)
{
    int x = (i % GRID_WIDTH) * CELL_SIZE;
    int y = (i / GRID_WIDTH) * CELL_SIZE;
    sfColor color;
    char hex_str[4];
    sfVector2f pos = {x, y};
    sfVector2f text_pos = {x + 2, y - 1};

    sfRectangleShape_setPosition(cell, pos);
    color = set_color(vm->owner_map, i);
    sfRectangleShape_setFillColor(cell, color);
    sfRenderWindow_drawRectangleShape(vm->display->window, cell, NULL);
    snprintf(hex_str, sizeof(hex_str), "%02X", vm->arena[i]);
    sfText_setString(text, hex_str);
    sfText_setPosition(text, text_pos);
    sfRenderWindow_drawText(vm->display->window, text, NULL);
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
