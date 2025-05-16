/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Draw texts stuffs
*/
#include "corewar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

void draw_text(virtual_machine_t *vm, int cycles)
{
    char cycles_str[50];
    sfVector2f pos = {1700, 50};

    snprintf(cycles_str, 50, "Cycles:\n%d/%d", cycles, vm->cycle_to_die);
    sfText_setString(vm->display->text, cycles_str);
    sfText_setPosition(vm->display->text, pos);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE * 3);
    sfRenderWindow_drawText(vm->display->window, vm->display->text, NULL);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE - 3);
}
