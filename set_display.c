/*
** EPITECH PROJECT, 2020
** set_display
** File description:
** set and destroy element
*/

#include "include/my.h"

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void set_game_obj(game_object_t *obj, sfRenderWindow *window)
{
    sfSprite_setScale(obj->sprite, obj->scale);
    sfSprite_setTextureRect(obj->sprite, obj->box);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
}

void draw_all_obj(all_object_t *obj, sfRenderWindow *window)
{
    draw_obj(obj->background1, window);
    draw_obj(obj->background2, window);
    draw_obj(obj->background3, window);
    draw_obj(obj->perso, window);
    draw_obj(obj->obstacle, window);
    draw_obj(obj->ghost, window);
    draw_obj(obj->pause, window);
    sfRenderWindow_drawText(window, obj->text->t, NULL);
}

void draw_obj(game_object_t *obj, sfRenderWindow *window)
{
    sfSprite_setPosition(obj->sprite, obj->position);
    sfSprite_setTextureRect(obj->sprite, obj->box);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void set_all_obj(all_object_t *obj, sfRenderWindow *window)
{
    set_game_obj(obj->background1, window);
    set_game_obj(obj->background2, window);
    set_game_obj(obj->background3, window);
    set_game_obj(obj->perso, window);
    set_game_obj(obj->obstacle, window);
    set_game_obj(obj->ghost, window);
    set_game_obj(obj->pause, window);
    sfSprite_setTexture(obj->start->sprite, obj->start->texture, sfFalse);
    sfSprite_setTexture(obj->game_over->sprite, obj->game_over->texture,
    sfFalse);
    sfSprite_setTexture(obj->victory->sprite, obj->victory->texture, sfFalse);
    sfSprite_setTexture(obj->scr_pause->sprite, obj->scr_pause->texture,
    sfFalse);
}