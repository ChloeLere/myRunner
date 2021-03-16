/*
** EPITECH PROJECT, 2020
** lose_win
** File description:
** lost game or win game
*/

#include "include/my.h"

void set_display_score(all_object_t *obj)
{
    sfVector2f pos_score = {180, 248};
    sfVector2f best_score_pos = {300, 329};
    char *first_score = int_to_char(obj->point);
    char *best_score = find_the_bigger(obj->point, first_score);

    obj->text->font = sfFont_createFromFile("element/cour.ttf");
    sfText_setString(obj->text->t, first_score);
    sfText_setFont(obj->text->t, obj->text->font);
    sfText_setCharacterSize(obj->text->t, 42);
    sfText_setPosition(obj->text->t, pos_score);
    sfText_setString(obj->best_score->t, best_score);
    sfText_setFont(obj->best_score->t, obj->best_score->font);
    sfText_setCharacterSize(obj->best_score->t, 42);
    sfText_setPosition(obj->best_score->t, best_score_pos);
    free(first_score);
}

void restart_or_exit(all_object_t *obj, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 476 && event.mouseButton.y < 533
        && event.mouseButton.x > 94 && event.mouseButton.x < 314)
            obj->status = 1;
        if (event.mouseButton.y > 480 && event.mouseButton.y < 535
        && event.mouseButton.x > 490 && event.mouseButton.x < 714)
            sfRenderWindow_close(window);
    }
}

void restart(all_object_t *obj, sfRenderWindow *window, sfEvent event,
int lose)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event);
        restart_or_exit(obj, event, window);
    }
    if (lose == 1)
        sfRenderWindow_drawSprite(window, obj->game_over->sprite, NULL);
    else
        sfRenderWindow_drawSprite(window, obj->victory->sprite, NULL);
    sfRenderWindow_drawText(window, obj->text->t, NULL);
    sfRenderWindow_drawText(window, obj->best_score->t, NULL);
}

void new_game(all_object_t *obj, int s)
{
        obj->obstacle->position.x = 850;
        obj->ghost->position.x = 900;
        obj->status = s;
        obj->point = -1000;
        obj->random = 0;
        obj->perso->position.y = 315;
        obj->perso->box.left = 0;
        obj->perso->box.top = 0;
        obj->jump = 0;
        obj->c = 0;
        obj->g = 0;
        obj->z = 0;
        sfMusic_stop(obj->jump_sound);
}