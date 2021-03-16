/*
** EPITECH PROJECT, 2020
** score
** File description:
** calc & display score
*/

#include "include/my.h"

text_t *create_text(char *namefont)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile(namefont);
    text->t = sfText_create();
    return (text);
}

void calc_score(all_object_t *obj)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(obj->c_score)) >= 2) {
        obj->point += 1000;
        sfClock_restart(obj->c_score);
    }
}

void display_score(all_object_t *obj, sfRenderWindow *window)
{
    char *score;
    sfVector2f pos = {660, 535};

    calc_score(obj);
    score = int_to_char(obj->point);
    sfText_setString(obj->text->t, score);
    sfText_setFont(obj->text->t, obj->text->font);
    sfText_setCharacterSize(obj->text->t, 45);
    sfText_setPosition(obj->text->t, pos);
    free(score);
}