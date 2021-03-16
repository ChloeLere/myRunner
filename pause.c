/*
** EPITECH PROJECT, 2021
** pause
** File description:
** pause menu
*/

#include "include/my.h"

void wait(all_object_t *obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clockpar3)) >= 900) {
        obj->c += 1;
        obj->random = 0;
        sfClock_restart(obj->clockpar3);
    }
}

void pause_m(all_object_t *obj, sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event);
        contin_re_new(obj, event, window);
    }
    sfRenderWindow_drawSprite(window, obj->scr_pause->sprite, NULL);
}

void touch_pause(sfEvent event, all_object_t *obj)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 23 && event.mouseButton.y < 90
        && event.mouseButton.x > 700 && event.mouseButton.x < 778)
            obj->status = 5;
    }
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            obj->status = 5;
    }
}