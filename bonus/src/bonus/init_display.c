/*
** EPITECH PROJECT, 2025
** Corewar bonus
** File description:
** Init
*/

#include "corewar.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>

static sfText *init_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, CELL_SIZE - 3);
    sfText_setFillColor(text, sfWhite);
    return text;
}

int init_display(virtual_machine_t *vm)
{
    sfVector2f size = {CELL_SIZE - 1, CELL_SIZE - 1};

    vm->display = malloc(sizeof(display_t));
    vm->display->mode.height = 1080;
    vm->display->mode.width = 1920;
    vm->display->mode.bitsPerPixel = 32;
    vm->display->window = sfRenderWindow_create(vm->display->mode,
        "Corewar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(vm->display->window, 1000);
    vm->display->sim_clock.clock = sfClock_create();
    vm->display->sim_clock.seconds = 0;
    vm->display->sim_timer = 0;
    vm->display->sim_delay = SIM_DELAY;
    vm->display->cell = sfRectangleShape_create();
    vm->display->font = sfFont_createFromFile("assets/font.ttf");
    vm->display->text = init_text(vm->display->font);
    sfRectangleShape_setSize(vm->display->cell, size);
    return 0;
}
