/*
** EPITECH PROJECT, 2020
** my
** File description:
** functions in libmy.a
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <time.h>

typedef struct game_object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect box;
    sfVector2f scale;
}game_object_t;

typedef struct text_s
{
    sfFont *font;
    sfText *t;
}text_t;

typedef struct screen_s
{
    sfSprite *sprite;
    sfTexture *texture;
}screen_t;

typedef struct all_object_s
{
    game_object_t *background1;
    game_object_t *background2;
    game_object_t *background3;
    game_object_t *perso;
    game_object_t *obstacle;
    game_object_t *ghost;
    game_object_t *pause;
    screen_t *start;
    screen_t *game_over;
    screen_t *victory;
    screen_t *scr_pause;
    text_t *text;
    text_t *best_score;
    sfClock *clock;
    sfClock *clockpar1;
    sfClock *clockpar2;
    sfClock *clockpar3;
    sfClock *c_score;
    sfClock *c_obs;
    sfClock *c_obs2;
    sfClock *c_ghost;
    sfClock *c_ghost2;
    sfMusic *jump_sound;
    int status;
    int point;
    int jump;
    int random;
    int c;
    int g;
    int z;
    char *map;
}all_object_t;

typedef struct info_s
{
    sfIntRect rect1;
    sfIntRect rect2;
    sfIntRect rect3;
    sfIntRect rect4;
    sfIntRect rect5;
    sfIntRect rect6;
    sfIntRect rectp;
    sfVector2f pos;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfVector2f pos4;
    sfVector2f pos5;
    sfVector2f posp;
    sfVector2f sc;
    sfVector2f sc2;
    sfVector2f sc3;
    sfVector2f sc4;
    sfVector2f sc5;
    sfVector2f sc6;
    sfVector2f scp;
}info_t;

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *s, ...);
int edit_add(char *str, va_list argv, int add);
int space_or_plus(char str, va_list argv, int add);
void display_all_char (char *str);
int add_zero_or_space_int(char *str, va_list argv, int add);
void check_string(char *type, va_list argv);
void check_int(char *type, va_list argv);
void check_char(char *type, va_list argv);
int check_other(char *type, va_list argv);
void convert(va_list argv, int base);
void convert_hexa_lower(va_list argv);
void convert_hexa_upper(va_list argv);
int my_put_nbr_pr(int nb);
void my_put_nbr_oct(int nb);
void my_put_nbr_uns(unsigned int nb);
void my_put_nbr_long(long nb);
double my_put_float(double nbr);
void my_put_short(short nb);
void display_p(char *str, va_list argv);
int add_zero_or_space(char *str, va_list argv, int add);
void space_char(va_list argv, int nbr);
void zero_or_space_int(char str, va_list argv, int nb_z);
int my_getnbr_with_i (char const *str, int i);
int my_nbrlen(int str);
void convert_hexa_lower_int(int nbr, va_list argv);
void convert_hexa_lower_long(unsigned long nbr, va_list argv);

void display_h(void);
int open_project(char *argv);
static sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title);
void status_game(sfRenderWindow *window, sfEvent event, all_object_t *obj,
int i);
void open_window(int i, char *name_map);
int load_file_in_mem(char const *filepath);
int open_map(char **argv);
all_object_t *create_all_obj(char *name_map);
all_object_t *create_obj_2(all_object_t *all, info_t *data);
struct game_object_s *create_object(const char *name_sprite,
sfVector2f pos, sfIntRect rect, sfVector2f sc);
screen_t *create_screen(char *name);
all_object_t *create_object_clock(all_object_t *all);
all_object_t *create_object_int(all_object_t *all);
info_t *give_data(void);
info_t *give_data2(info_t *data);
info_t *give_data3(info_t *data);
int analyse_event_start(sfRenderWindow *window, sfEvent event, int update);
int find_event_start(sfRenderWindow *window, sfEvent event, int update);
int start_interface(sfRenderWindow *window, sfEvent event, all_object_t *obj);
void analyse_event(sfRenderWindow *window, sfEvent event);
void space_touch(sfRenderWindow *window, sfEvent event, all_object_t *obj);
void find_event(sfRenderWindow *window, sfEvent event, all_object_t *obj);
void map_read(all_object_t *obj);
void parallax(all_object_t *obj);
int jump_or_run(all_object_t *obj);
void jump(all_object_t *obj);
void run(all_object_t *obj);
void enemy(all_object_t *obj);
void lose_or_win(all_object_t *obj);
void enemy_ghost(all_object_t *obj);
text_t *create_text(char *namefont);
void display_score(all_object_t *obj, sfRenderWindow *window);
void calc_score(all_object_t *obj);
char *inverse_char(int size, char *nbr);
char *int_to_char(int nbr);
void display_window(sfRenderWindow *window);
void set_game_obj(game_object_t *obj, sfRenderWindow *window);
void draw_all_obj(all_object_t *obj, sfRenderWindow *window);
void set_all_obj(all_object_t *obj, sfRenderWindow *window);
void draw_obj(game_object_t *obj, sfRenderWindow *window);
void set_display_score(all_object_t *obj);
void restart_or_exist(all_object_t *obj, sfEvent event, sfRenderWindow *window);
void restart(all_object_t *obj, sfRenderWindow *window, sfEvent event,
int lose);
void new_game(all_object_t *obj, int s);
void find_event_i(sfRenderWindow *window, sfEvent event, all_object_t *obj);
void display_enemy(all_object_t *obj);
void lose_z(all_object_t *obj);
void lose_ghost(all_object_t *obj);
char *file_op(char *filepath, char *error);
char *find_the_bigger(int n, char *nbr);
void destroy_obj(sfRenderWindow *window, game_object_t *obj);
void destroy_part2(sfRenderWindow *window, all_object_t *obj);
void destroy(sfRenderWindow *window, all_object_t *obj);
void wait(all_object_t *obj);
void pause_m(all_object_t *obj, sfRenderWindow *window, sfEvent event);
void touch_pause(sfEvent event, all_object_t *obj);
void contin_re_new(all_object_t *obj, sfEvent event, sfRenderWindow *window);