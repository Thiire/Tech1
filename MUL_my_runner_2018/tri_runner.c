/*
** EPITECH PROJECT, 2018
** tri_runner.c
** File description:
** tri_runner.c
*/

#include "include/imagebuffer.h"

static int pos;
static char *name;

int my_put_nbr(int score)
{
    long nbs = score;

    if ( nbs >= 10) {
        my_put_nbr(nbs / 10);
    }
    name[pos] = nbs % 10 + 48;
    pos++;
    return (0);
}

int scorer(sfRenderWindow *window, int score)
{
    sfFont *font = sfFont_createFromFile("Bonus/SugarPunch.otf");
    sfText *text = sfText_create();

    name = malloc(sizeof(char) * 20);
    name[0] = 's';
    name[1] = 'c';
    name[2] = 'o';
    name[3] = 'r';
    name[4] = 'e';
    name[5] = ':';
    name[6] = ' ';
    pos = 7;
    my_put_nbr(score);
    name[pos] = '\0';
    sfText_setString(text, name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    return (score + 1);
}

int victory(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *victend = sfTexture_createFromFile
    ("Bonus/txt/victory.png", NULL);
    sfSprite *vic = sfSprite_create();

    sfSprite_setTexture(vic, victend, sfFalse);
    sfRenderWindow_drawSprite(window, vic, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape))
                sfRenderWindow_close(window);
    }
    return (0);
}

int move_decal(imagebuffer_t **image)
{
    for (int i = 0; i < 3; i++)
        for (int n = 6; n < 15; n++)
            image[(i * 10) + n] = image[(i * 10) + n + 1];
    return (0);
}

imagebuffer_t *tri_text1(imagebuffer_t *image, char **stc, int y, int x)
{
    if (stc[y][x] != '1' && stc[y][x] != '2') {
        image = image_ctr("Empty.png", (sfIntRect)
        {0, 0, 218, 253}, (sfVector2f){(x - 1) * 218, 200+y * 218}, EMPTY);
        return (image);
    }
    if (stc[y][x] == '2') {
        image = image_ctr("Bonus/txt/flag.png", (sfIntRect)
        {0, 0, 218, 436}, (sfVector2f){(x - 1) * 218, y * 218}, VICTORY);
        return (image);
    }
    if (stc[y - 1][x] != ' ')
        image = image_ctr("Bonus/txt/dirt.png", (sfIntRect)
        {0, 0, 218, 218}, (sfVector2f){(x - 1) * 218, 200+y * 218}, OBSTACLE);
    if (stc[y - 1][x] != '1')
        image = image_ctr("Bonus/txt/grass.png", (sfIntRect)
        {0, 0, 218, 218}, (sfVector2f){(x - 1) * 218, 200+y * 218}, OBSTACLE);
    return (image);
}