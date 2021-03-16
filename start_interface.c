/*
** EPITECH PROJECT, 2020
** start_interface
** File description:
** start
*/

#include "include/my.h"

int analyse_event_start(sfRenderWindow *window, sfEvent event, int update)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 170 && event.mouseButton.y < 230
        && event.mouseButton.x > 280 && event.mouseButton.x < 500)
            update = 2;
        if (event.mouseButton.y > 335 && event.mouseButton.y < 395
        && event.mouseButton.x > 285 && event.mouseButton.x < 505)
            sfRenderWindow_close(window);
    }
    return (update);
}

int find_event_start(sfRenderWindow *window, sfEvent event, int update)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event);
        update = analyse_event_start(window, event, update);
    }
    return (update);
}

int start_interface(sfRenderWindow *window, sfEvent event, all_object_t *obj)
{
    int update = 1;

    update = find_event_start(window, event, update);
    sfRenderWindow_drawSprite(window, obj->start->sprite, NULL);
    return (update);
}
