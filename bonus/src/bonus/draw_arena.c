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

void draw_champs(display_t *graphic, unsigned char *arena, unsigned char *owner_map)
{
    sfRectangleShape *cell = sfRectangleShape_create();
    sfText *text = sfText_create();
    sfVector2f size = {CELL_SIZE - 1, CELL_SIZE - 1};
    sfRectangleShape_setSize(cell, size);

    sfText_setFont(text, graphic->font);
    sfText_setCharacterSize(text, CELL_SIZE - 2);
    sfText_setFillColor(text, sfWhite);

    char hex_str[4];

    for (int i = 0; i < MEM_SIZE; ++i) {
        int x = (i % GRID_WIDTH) * CELL_SIZE;
        int y = (i / GRID_WIDTH) * CELL_SIZE + 56;
        sfVector2f pos = {x, y};
        sfRectangleShape_setPosition(cell, pos);

        sfColor color = sfColor_fromRGB(50, 50, 50);
        if (owner_map[i] == 1)
            color = sfColor_fromRGB(150, 0, 0);
        else if (owner_map[i] == 2)
            color = sfColor_fromRGB(0, 132, 0);
        else if (owner_map[i] == 3)
            color = sfBlue;
        else if (owner_map[i] == 4)
            color = sfColor_fromRGB(117, 0, 135);
        sfRectangleShape_setFillColor(cell, color);
        sfRenderWindow_drawRectangleShape(graphic->window, cell, NULL);
        snprintf(hex_str, sizeof(hex_str), "%02X", arena[i]);
        sfText_setString(text, hex_str);
        sfVector2f text_pos = {x + 1, y - 2};
        sfText_setPosition(text, text_pos);
        sfRenderWindow_drawText(graphic->window, text, NULL);
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
        draw_champs(graphic, vm->arena, vm->owner_map);
        sfRenderWindow_display(graphic->window);
    return 0;
}
