/*
** EPITECH PROJECT, 2021
** infinity
** File description:
** for infinity mode
*/

#include "include/my.h"

void find_event_i(sfRenderWindow *window, sfEvent event, all_object_t *obj)
{
    jump_or_run(obj);
    parallax(obj);
    display_score(obj, window);
    display_enemy(obj);
    lose_z(obj);
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event);
        space_touch(window, event, obj);
        touch_pause(event, obj);
    }
    draw_all_obj(obj, window);
}

void display_enemy(all_object_t *obj)
{
    if (obj->random == 0)
        obj->random = rand() % 10;
    if (obj->random < 5 || obj->g == 1)
        enemy_ghost(obj);
    if (obj->random > 5 || obj->z == 1)
        enemy(obj);
    if (obj->random == 5)
        wait(obj);
}

void lose_z(all_object_t *obj)
{
    if ((obj->perso->position.x + obj->perso->box.width) >=
    obj->obstacle->position.x + 50
    && (obj->perso->position.x + obj->perso->box.width)  <=
    obj->obstacle->position.x + obj->obstacle->box.width
    && obj->perso->position.y + obj->perso->box.width >= 400) {
        set_display_score(obj);
        new_game(obj, 3);
    }
    lose_ghost(obj);
}

void lose_ghost(all_object_t *obj)
{
    if ((obj->perso->position.x + obj->perso->box.width) >=
    obj->ghost->position.x + 30
    && (obj->perso->position.x + obj->perso->box.width)  <=
    obj->ghost->position.x + obj->ghost->box.width
    && obj->perso->position.y + obj->perso->box.width >= 400) {
        set_display_score(obj);
        new_game(obj, 3);
    }
}