/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_world.h"

void dash_h(void)
{
    write(1, "USAGE\n  ./my_world\n  -This project is a map editor.\n\nOPTION"
    "\n  -h   print the usage and quit.\n\nUSER INTERACTIONS\n  -Press 'ESCAP"
    "E' to quit the editor map.\n  -Press 'SPACE' to reset positions.\n  -Pre"
    "ss 'Z', 'Q"
    ", 'S, 'D' to moove your map.\n  -Press 'Shift' + 'Z', 'Q', 'S', 'D' to ro"
    "tate your map.\n  -Press 'A' to zoom in and 'E' to zoom out.\n  -Left cli"
    "ck on the + to enlarge the map.\n  -Left click on the - to shrink the map"
    ".\n  -Left click on the hand to pick up the elevation tool.\n  -Left clic"
    "k on the shovel to pick up the dig tool.\n  -Left click on the interrogat"
    "ion point to have\n   the all the details about the interactions on the e"
    "ditor map.\n", 649);
}

void esc(Map_t *map, sfRenderWindow *window, sfEvent event, all_t *all)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed)
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
}

void game_loop(Map_t *map, all_t *all, sfEvent event)
{
    while (sfRenderWindow_pollEvent(map->window, &event))
        esc(map, map->window, event, all);
    sfRenderWindow_setMouseCursorVisible(map->window, 0);
    md(map, event, all);
    sfRenderWindow_clear(map->window, sfBlack);
    drawing(all, map->window, map);
    sfRenderWindow_display(map->window);
}

int main(int ac, char **av)
{
    Map_t *map = map_filler();
    all_t *all = init_struct();;
    size_t count;
    sfEvent event;
    const sfVideoMode *tab = sfVideoMode_getFullscreenModes(&count);
    
    map->mode = tab[0];
    map->window = sfRenderWindow_create(map->mode, "My_World",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(map->window, 30);
    if (ac != 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        dash_h();
        return (0);
    }
    while (sfRenderWindow_isOpen(map->window)) {
        game_loop(map, all, event);
    }
    sfRenderWindow_destroy(map->window);
    return (0);
}
