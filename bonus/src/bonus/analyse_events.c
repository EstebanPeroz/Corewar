/*
** EPITECH PROJECT, 2024
** analys_events
** File description:
** analyse event
*/
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>
#include <unistd.h>
#include "corewar.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>

void basic_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

void analyse_events(display_t *params, sfEvent event)
{
    basic_events(params->window, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        params->sim_delay /= 1.5;
        if (params->sim_delay < 0)
            params->sim_delay = 0;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        params->sim_delay *= 1.5;
    }
}
