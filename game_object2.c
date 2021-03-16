/*
** EPITECH PROJECT, 2021
** game_object2
** File description:
** define obj
*/

#include "include/my.h"

screen_t *create_screen(char *name)
{
    screen_t *s = malloc(sizeof(screen_t));
    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile(name, NULL);
    return (s);
}

struct game_object_s *create_object(const char *name_sprite,
sfVector2f pos, sfIntRect rect, sfVector2f sc)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(name_sprite, NULL);
    obj->position = pos;
    obj->box = rect;
    obj->scale = sc;
    return (obj);
}