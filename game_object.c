/*
** EPITECH PROJECT, 2020
** game_object
** File description:
** management game object
*/

#include "include/my.h"

all_object_t *create_all_obj(char *namemap)
{
    all_object_t *all = malloc(sizeof(all_object_t));
    info_t *data = give_data();
    char *map2 = file_op(namemap, " ");

    all->map = map2;
    all = create_obj_2(all, data);
    all->background1 = create_object("./element/sky.jpg",
    data->pos, data->rect2, data->sc);
    all->background2 = create_object("./element/background.png", data->pos3,
    data->rect1, data->sc2);
    all->background3 = create_object("./element/ground.png",
    data->pos2, data->rect4, data->sc4);
    all->obstacle = create_object("./element/obstacle.png",
    data->pos4, data->rect5, data->sc5);
    all->perso = create_object("./element/perso.png",
    data->pos1, data->rect3, data->sc3);
    all->ghost = create_object("./element/ghost.png",
    data->pos5, data->rect6, data->sc6);
    return (all);
}

all_object_t *create_obj_2(all_object_t *all, info_t *data)
{
    all->pause = create_object("element/pause.png",
    data->posp, data->rectp, data->scp);
    all->start = create_screen("./element/start.jpg");
    all->game_over = create_screen("./element/gameover.jpg");
    all->victory = create_screen("./element/victory.jpg");
    all->scr_pause = create_screen("./element/pause.jpg");
    all->text = create_text("element/aAsianNinja.ttf");
    all->best_score = create_text("element/cour.ttf");
    all->jump_sound = sfMusic_createFromFile("./element/jump.flac");
    all = create_object_int(all);
    all = create_object_clock(all);
    return (all);
}

all_object_t *create_object_clock(all_object_t *all)
{
    all->clock = sfClock_create();
    all->clockpar1 = sfClock_create();
    all->clockpar2 = sfClock_create();
    all->clockpar3 = sfClock_create();
    all->c_score = sfClock_create();
    all->c_obs = sfClock_create();
    all->c_obs2 = sfClock_create();
    all->c_ghost = sfClock_create();
    all->c_ghost2 = sfClock_create();
    return (all);
}

all_object_t *create_object_int(all_object_t *all)
{
    all->point = 0;
    all->status = 1;
    all->jump = 0;
    all->random = 0;
    all->c = 0;
    all->g = 0;
    all->z = 0;
    return (all);
}