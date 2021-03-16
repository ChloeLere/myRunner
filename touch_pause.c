/*
** EPITECH PROJECT, 2021
** touch_pause
** File description:
** event pause
*/

#include "include/my.h"

void contin_re_new(all_object_t *obj, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 183 && event.mouseButton.y < 250
        && event.mouseButton.x > 280 && event.mouseButton.x < 512)
            obj->status = 2;
        if (event.mouseButton.y > 315 && event.mouseButton.y < 380
        && event.mouseButton.x > 280 && event.mouseButton.x < 510) {
            new_game(obj, 2);
        }
        if (event.mouseButton.y > 455 && event.mouseButton.y < 525
        && event.mouseButton.x > 280 && event.mouseButton.x < 510)
            sfRenderWindow_close(window);
    }
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            obj->status = 2;
    }
}