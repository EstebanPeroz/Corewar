/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Draw texts stuffs
*/
#include "corewar.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static void draw_cycles(virtual_machine_t *vm, int cycles)
{
    char cycles_str[50];
    sfVector2f pos = {1655, 20};

    snprintf(cycles_str, 50, "Cycles:\n%d/%d", cycles, vm->cycle_to_die);
    sfText_setString(vm->display->text, cycles_str);
    sfText_setPosition(vm->display->text, pos);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE * 3);
    sfRenderWindow_drawText(vm->display->window, vm->display->text, NULL);
}

static sfColor set_color(int i)
{
    sfColor color = sfColor_fromRGB(50, 50, 50);

    if (i == 1)
        color = sfColor_fromRGB(200, 50, 50);
    if (i == 2)
        color = sfColor_fromRGB(50, 182, 50);
    if (i == 3)
        color = sfColor_add(sfBlue, sfColor_fromRGB(100, 100, 100));
    if (i == 4)
        color = sfColor_fromRGB(167, 50, 185);
    return color;
}

static void draw_champ_status(virtual_machine_t *vm, champions_t *cur,
    sfVector2f pos, int i)
{
    char status_str[300];
    sfVector2f status_pos = {pos.x - 50, pos.y + 40};
    char *live = malloc(sizeof(char) * 10);

    live = "Alive";
    sfText_setString(vm->display->text, cur->header.prog_name);
    sfText_setColor(vm->display->text, set_color(i));
    sfText_setPosition(vm->display->text, pos);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE * 2 + 5);
    sfRenderWindow_drawText(vm->display->window, vm->display->text, NULL);
    sfText_setColor(vm->display->text, sfColor_fromRGB(204, 255, 204));
    if (!cur->is_alive) {
        live = "Dead";
        sfText_setColor(vm->display->text, sfColor_fromRGB(50, 50, 50));
    }
    if (cur->is_alive && cur->last_live == -1) {
        sfText_setColor(vm->display->text, sfWhite);
        live = "Pending...";
    }
    snprintf(status_str, sizeof(status_str), "Carry: %d     Cooldown:\t%d\n"
             "Status:\t%s",
        cur->carry, cur->cylces_to_wait, live);
    sfText_setString(vm->display->text, status_str);
    sfText_setPosition(vm->display->text, status_pos);
    sfRenderWindow_drawText(vm->display->window, vm->display->text, NULL);
}

void draw_speed(virtual_machine_t *vm)
{
    char cycles_str[50];
    sfVector2f pos = {15, 1030};

    snprintf(cycles_str, 50, "Speed:\t%.2f", 1.0 / vm->display->sim_delay);
    sfText_setString(vm->display->text, cycles_str);
    sfText_setPosition(vm->display->text, pos);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE * 2);
    sfRenderWindow_drawText(vm->display->window, vm->display->text, NULL);
}

static bool is_passed(champions_t *cur, int passed[4])
{
    int j = 0;

    for (int i = 0; i < 4; i++) {
        if (cur->prog_id == passed[i]) {
            return true;
        }
    }
    for (; passed[j] != 0; j++);
    if (j < 4)
        passed[j] = cur->prog_id;
    return false;
}

void draw_text(virtual_machine_t *vm, int cycles)
{
    champions_t *cur = vm->champion;
    sfVector2f pos = {1650, 220};
    int passed[4] = {0, 0, 0, 0};

    draw_cycles(vm, cycles);
    for (int i = 1; cur != NULL; i++)
    {
        if (!is_passed(cur, passed)) {
            draw_champ_status(vm, cur, pos, i);
            pos.y += 150;
        }
        cur = cur->next;
    }
    sfText_setColor(vm->display->text, sfWhite);
    draw_speed(vm);
    sfText_setCharacterSize(vm->display->text, CELL_SIZE - 3);
}
