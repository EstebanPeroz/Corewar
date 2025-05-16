/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** free_vm
*/

#include "corewar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

void free_virtual_machine(virtual_machine_t *virtual_machine)
{
    if (virtual_machine->champion)
        free_champion(virtual_machine->champion);
    sfRenderWindow_destroy(virtual_machine->display->window);
    sfClock_destroy(virtual_machine->display->sim_clock.clock);
    free(virtual_machine->display);
    free(virtual_machine);
}
