/*
** EPITECH PROJECT, 2020
** open_window
** File description:
** open window
*/

#include "include/my.h"

static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    sfRenderWindow *cw;

    cw = sfRenderWindow_create(video_mode, title, sfClose | sfResize, NULL);
    return (cw);
}

void status_game(sfRenderWindow *window, sfEvent event, all_object_t *obj,
int i)
{
    if (obj->status == 1)
        obj->status = start_interface(window, event, obj);
    if (obj->status == 2 && i == 0)
        find_event(window, event, obj);
    if (obj->status == 2 && i == 1)
        find_event_i(window, event, obj);
    if (obj->status == 3)
        restart(obj, window, event, 1);
    if (obj->status == 4)
        restart(obj, window, event, 0);
    if (obj->status == 5)
        pause_m(obj, window, event);
}

void open_window(int i, char *name_map)
{
    sfRenderWindow *window = create_window(800, 600, 32, "Runner");
    sfEvent event;
    all_object_t *obj = create_all_obj(name_map);
    sfMusic *music = sfMusic_createFromFile("./element/music.wav");

    sfMusic_setVolume(music, 25);
    sfMusic_setVolume(obj->jump_sound, 100);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    set_all_obj(obj, window);
    while (sfRenderWindow_isOpen(window)) {
        status_game(window, event, obj, i);
        display_window(window);
    }
    sfMusic_destroy(music);
    destroy(window, obj);
}