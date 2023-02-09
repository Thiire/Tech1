/*
** EPITECH PROJECT, 2018
** runner.c
** File description:
** runner.c
*/

#include "include/imagebuffer.h"

static int score;

int end_game(sfRenderWindow *window, int death)
{
    sfEvent event;
    sfTexture *endin = sfTexture_createFromFile
    ("Bonus/txt/GameOver.png", NULL);
    sfSprite *end = sfSprite_create();

    if (death == 2)
        return (victory(window));
    sfSprite_setTexture(end, endin, sfFalse);
    sfRenderWindow_drawSprite(window, end, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape))
                sfRenderWindow_close(window);
    }
    return (0);
}

int do_ops(char **stc)
{
    imagebuffer_t **image = creator(stc);
    sfRenderWindow *window;
    sfTexture *backgrd = sfTexture_createFromFile("Bonus/txt/Back.png", NULL);
    sfSprite *back = sfSprite_create();
    sfVideoMode mode = {1920, 1080, 32};
    sfClock *clocker = sfClock_create();
    int ret = 2;
    int death = 0;

    window = sfRenderWindow_create(mode, "My window", sfDefaultStyle, NULL);
    sfSprite_setTexture(back, backgrd, sfFalse);
    while (sfRenderWindow_isOpen(window) && death == 0) {
        sfRenderWindow_setFramerateLimit(window, 60);
        sfRenderWindow_drawSprite(window, back, NULL);
        ret = displayer(window, image, clocker, ret);
        death = platform(stc, image, window);
        score = scorer(window, score);
        ret = check(window, clocker, ret, image);
    }
    return (end_game(window, death));
}

int to_cut(char *stack, int size)
{
    int n = 1;
    int i = 0;
    char **stc = malloc(sizeof(char) * size);

    for (int y = 0; y < size; y++)
        stc[y] = malloc(sizeof(char) * size);
    for (int y = 0; stack[y] != '\0'; y++) {
        stc[n][i] = stack[y];
        if (stack[y] == '\n') {
            stc[n][i] = '\0';
            i = 0;
            n++;
        } else
            i++;
    }
    stc[n][0] = '\0';
    stc++;
    return (do_ops(stc));
}

int recup(char *av)
{
    int of = 0;
    char *stack;
    struct stat board;

    of = open(av, O_RDONLY);
    stat(av, &board);
    stack = malloc(sizeof(char) * board.st_size);
    if (of == -1) {
        write(0, "invalid files\n", 15);
        return (84);
    }
    read(of, stack, board.st_size);
    to_cut(stack, board.st_size);
    return (0);
}

int main(int ag, char **av)
{
    sfMusic *music = sfMusic_createFromFile("Bonus/Flamingo.ogg");

    score = 0;
    sfMusic_setVolume(music, 10);
    sfMusic_setLoop(music, sfTrue);
    if (ag == 1) {
        sfMusic_destroy(music);
        return (84);
    } else if (ag == 2) {
        sfMusic_play(music);
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
            write(1, "Description:\n\nFunction should take a map with '#' as"
            " border and with '1' for ground and '2' for winning flag\nYou"
            " can refer to some map in /Bonus/map folder\n\nUsage:\n\nPress" 
            " 'space' to jump and 'escape' to exit the game\n", 218);
        } else
            recup(av[1]);
        sfMusic_destroy(music);
    }
    return (0);
}
