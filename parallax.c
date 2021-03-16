/*
** EPITECH PROJECT, 2020
** parallax
** File description:
** parallax scrolling
*/

#include "include/my.h"

void parallax(all_object_t *obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clockpar1)) >=
    50000) {
        obj->background1->box.left += 1;
        sfClock_restart(obj->clockpar1);
    }
    sfTexture_setRepeated(obj->background1->texture, sfTrue);
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clockpar2)) >= 2000) {
        obj->background2->box.left += 1;
        sfClock_restart(obj->clockpar2);
    }
    sfTexture_setRepeated(obj->background2->texture, sfTrue);
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clockpar3)) >= 1200) {
        obj->background3->box.left += 1;
        sfClock_restart(obj->clockpar3);
    }
    sfTexture_setRepeated(obj->background3->texture, sfTrue);
}