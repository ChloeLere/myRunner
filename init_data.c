/*
** EPITECH PROJECT, 2020
** init_data
** File description:
** initialise struct info
*/

#include "include/my.h"

info_t *give_data(void)
{
    info_t *data = malloc(sizeof(info_t));
    sfIntRect r = {0, 0, 850, 250};
    sfIntRect r2 = {0, 130, 1680, 945};
    sfIntRect r3 = {0, 0, 180, 125};
    sfIntRect r4 = {0, 0, 800, 220};

    data->rect1 = r;
    data->rect2 = r2;
    data->rect3 = r3;
    data->rect4 = r4;
    data->pos.x = 0;
    data->pos.y = 0;
    data->pos1.x = -40;
    data->pos1.y = 315;
    data->pos2.x = 0;
    data->pos2.y = 370;
    data = give_data2(data);
    data = give_data3(data);
    return (data);
}

info_t *give_data2(info_t *data)
{
    sfIntRect r5 = {0, 0, 58, 53};

    data->rect5 = r5;
    data->sc.x = 0.95;
    data->sc.y = 0.95;
    data->sc2.x = 0.95;
    data->sc2.y = 0.95;
    data->sc3.x = 1.3;
    data->sc3.y = 1.3;
    data->sc4.x = 1.6;
    data->sc4.y = 1.6;
    data->pos3.x = 0;
    data->pos3.y = 280;
    data->pos4.x = 850;
    data->pos4.y = 422;
    data->sc5.x = 1;
    data->sc5.y = 1;
    return (data);
}

info_t *give_data3(info_t *data)
{
    sfIntRect r6 = {0, 0, 50, 50};
    sfVector2f pos = {850, 422};
    sfVector2f sc = {1, 1};
    sfIntRect rp = {0, 0, 165, 167};

    data->rect6 = r6;
    data->pos5 = pos;
    data->sc6 = sc;
    data->posp.x = 700;
    data->posp.y = 15;
    data->rectp = rp;
    data->scp.x = 0.5;
    data->scp.y = 0.5;
    return (data);
}