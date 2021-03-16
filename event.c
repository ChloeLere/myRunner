/*
** EPITECH PROJECT, 2020
** event
** File description:
** analyse event
*/

#include "include/my.h"

void analyse_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void space_touch(sfRenderWindow *window, sfEvent event, all_object_t *obj)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            obj->perso->box.left = 0;
            obj->jump = 1;
            sfMusic_play(obj->jump_sound);
        }
    }
}

void find_event(sfRenderWindow *window, sfEvent event, all_object_t *obj)
{
    jump_or_run(obj);
    parallax(obj);
    display_score(obj, window);
    map_read(obj);
    lose_or_win(obj);
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event);
        space_touch(window, event, obj);
        touch_pause(event, obj);
    }
    draw_all_obj(obj, window);
}

void map_read(all_object_t *obj)
{
        if (obj->map[obj->c] == '1' || obj->z == 1)
            enemy(obj);
        if (obj->map[obj->c] == '2' || obj->g == 1)
            enemy_ghost(obj);
        if (obj->map[obj->c] == ' ')
            wait(obj);
        if (obj->map[obj->c] == '\n' || obj->map[obj->c] == '\0') {
            obj->status = 4;
            set_display_score(obj);
            new_game(obj, 4);
        }
}
