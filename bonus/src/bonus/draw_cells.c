/*
** EPITECH PROJECT, 2025
** Corewar bonus
** File description:
** Draw cells
*/
#include "corewar.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>

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

void draw_pc(virtual_machine_t *vm, sfRectangleShape *rect
    , sfText *text)
{
    champions_t *cur = vm->champion;
    sfColor new_color;

    while (cur != NULL) {
        draw_cell(cur->prog_counter, text, vm, rect);
        new_color = sfRectangleShape_getFillColor(rect);
        new_color = sfColor_add(new_color, sfColor_fromRGB(125, 125, 125));
        sfRectangleShape_setFillColor(rect, new_color);
        sfRenderWindow_drawRectangleShape(vm->display->window, rect, NULL);
        sfRenderWindow_drawText(vm->display->window, text, NULL);
        cur = cur->next;
    }
}
