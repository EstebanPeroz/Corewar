/*
** EPITECH PROJECT, 2025
** Corewar bonus
** File description:
** Init
*/

#include "corewar.h"
#include <SFML/Graphics/Font.h>
int init_display(virtual_machine_t *vm)
{
    vm->display = malloc(sizeof(display_t));

    vm->display->mode.height = 1080;
    vm->display->mode.width = 1920;
    vm->display->mode.bitsPerPixel = 32;
    vm->display->window = sfRenderWindow_create(vm->display->mode,
        "Corewar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(vm->display->window, 60);
    vm->display->sim_clock.clock = sfClock_create();
    vm->display->sim_clock.seconds = 0;
    vm->display->sim_timer = 0;
    vm->display->font = sfFont_createFromFile("assets/font.ttf");
    if (!vm->display->font) {
        printf("Missing fonts !\n");
        exit(84);
    }
    return 0;
}
