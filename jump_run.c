/*
** EPITECH PROJECT, 2020
** jump_run
** File description:
** jump or run
*/

#include "include/my.h"

int jump_or_run(all_object_t *obj)
{
    if (obj->jump == 1)
        jump(obj);
    else
        run(obj);
    if (obj->perso->box.left >= 1000)
        obj->jump = 0;
    return (0);
}

void jump(all_object_t *obj)
{
    obj->perso->box.top = 205;
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clock)) >= 119999) {
        obj->perso->box.left += 200;
        if (obj->perso->box.left < 600)
            obj->perso->position.y -= 50;
        else
            obj->perso->position.y += 50;
        if (obj->perso->box.left >= 1000) {
            obj->jump = 0;
            sfMusic_stop(obj->jump_sound);
        }
        sfClock_restart(obj->clock);
    }
}

void run(all_object_t *obj)
{
    obj->perso->box.top = 0;
    obj->perso->position.y = 315;
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clock)) >= 100000) {
        obj->perso->box.left += 200;
        if (obj->perso->box.left >= 1200)
                obj->perso->box.left = 0;
        sfClock_restart(obj->clock);
    }
}