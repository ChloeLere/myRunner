/*
** EPITECH PROJECT, 2020
** enemy
** File description:
** gestion enemy's
*/

#include "include/my.h"

void enemy(all_object_t *obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->c_obs)) >= 900) {
        obj->z = 1;
        obj->obstacle->position.x -= 1;
        if (obj->obstacle->position.x < -20) {
            obj->obstacle->position.x = 850;
            obj->z = 0;
        }
        if (obj->obstacle->position.x == 400) {
            obj->c += 1;
            obj->random = 0;
        }
        sfClock_restart(obj->c_obs);
    }
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->c_obs2)) >= 100000) {
        obj->obstacle->box.left += 67;
        if (obj->obstacle->box.left >= 205)
            obj->obstacle->box.left = 0;
        sfClock_restart(obj->c_obs2);
    }
}

void enemy_ghost(all_object_t *obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->c_ghost)) >= 900) {
        obj->ghost->position.x -= 1;
        obj->g = 1;
        if (obj->ghost->position.x < -20) {
            obj->ghost->position.x = 850;
            obj->g = 0;
        }
        if (obj->ghost->position.x == 350) {
            obj->c += 1;
            obj->random = 0;
        }
        sfClock_restart(obj->c_ghost);
    }
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->c_ghost2))
    >= 100000) {
        obj->ghost->box.left += 50;
        if (obj->ghost->box.left >= 290)
            obj->ghost->box.left = 0;
        sfClock_restart(obj->c_ghost2);
    }
}

void lose_or_win(all_object_t *obj)
{
    lose_z(obj);
    lose_ghost(obj);
}