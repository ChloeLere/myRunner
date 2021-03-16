/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** destroy
*/

#include "include/my.h"

void destroy_obj(sfRenderWindow *window, game_object_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

void destroy_part2(sfRenderWindow *window, all_object_t *obj)
{
    sfClock_destroy(obj->clock);
    sfClock_destroy(obj->clockpar1);
    sfClock_destroy(obj->clockpar2);
    sfClock_destroy(obj->clockpar3);
    sfClock_destroy(obj->c_score);
    sfClock_destroy(obj->c_obs);
    sfClock_destroy(obj->c_obs2);
    sfText_destroy(obj->text->t);
    sfFont_destroy(obj->text->font);
    sfText_destroy(obj->best_score->t);
    sfFont_destroy(obj->best_score->font);
    sfMusic_destroy(obj->jump_sound);
    sfRenderWindow_destroy(window);
}

void destroy(sfRenderWindow *window, all_object_t *obj)
{
    destroy_obj(window, obj->background1);
    destroy_obj(window, obj->background2);
    destroy_obj(window, obj->background3);
    destroy_obj(window, obj->perso);
    destroy_obj(window, obj->obstacle);
    destroy_obj(window, obj->ghost);
    destroy_obj(window, obj->pause);
    sfSprite_destroy(obj->start->sprite);
    sfTexture_destroy(obj->start->texture);
    sfSprite_destroy(obj->game_over->sprite);
    sfTexture_destroy(obj->game_over->texture);
    sfSprite_destroy(obj->victory->sprite);
    sfTexture_destroy(obj->victory->texture);
    sfSprite_destroy(obj->scr_pause->sprite);
    sfTexture_destroy(obj->scr_pause->texture);
    destroy_part2(window, obj);
}