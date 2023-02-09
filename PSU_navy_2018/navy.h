/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** navy.h
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #define READ_SIZE (1)
    #define MAX(a, b) (a >= b ? a : b)
    #define MIN(a, b) (a <= b ? a : b)


    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <assert.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>

    typedef struct data_s
    {
        int letter;
        int number;
        pid_t p_id;
        int death;
        int life;
        int hit;
        int miss;
    } data_t;

    typedef struct Map_s {
        char **map1;
        char **map2;
        pid_t p_id;
    } Map_t;

    data_t *data;

    void my_printf(char *, ...);

    void my_er(char *, int);

    char **my_double_malloc(void);

    char **my_create_map(char *);

    char *get_next_line(int);

    int turn_gestion1(Map_t *);

    int turn_gestion2(Map_t *);

    char **my_create_other_map(void);

    int signal_manager1(Map_t *);

    int signal_manager2(Map_t *, int);

    int my_getnbr(const char *);

    char **enemy_map(void);

    int check_map(char *);

    int print_update_map(char **, int, int);

    int attack(Map_t *, int, int);

    int defense(Map_t *);

    void initial_print(Map_t *);

    int my_strlen(char *);

    int check_input(Map_t *, char *);

    int receive_hit(Map_t *, int, int);

    int transfer_hit(Map_t *, int);

    int win_check(Map_t *);

    int win(Map_t *, char **);

    int check_map3(char **, int *);

    int result_check(int *);

#endif /* !NAVY_H_ */
