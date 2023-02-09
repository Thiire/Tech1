/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include "op.h"
    #include "get_next_line.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <string.h>

    typedef struct instru_s
    {
        char *type;
        void (*fptr)(char *, int);
    } instru_t;

    //vm
    typedef struct vm_s
    {
        __uint32_t *stock;
        __uint32_t tmp;
        int running;
    } vm_t;

    union reverse
    {
        unsigned char letter[4];
        int number;
    };

    //lib
    int my_strlen(char *);
    int my_tablen(char **);
    void my_put_err(char *);
    void my_putstr(char *);
    void my_puttab(char  **);
    void free_tab(char **);
    void my_putchar(char);
    void putchar_err(char);
    int my_putnbr_base(int, char const *);
    int my_putnbr_base_error(int, char const *);
    int str_compare(char *, char *);
    int my_er(char *, int);
    char *cni(int);
    char *cn(char *);
    char *get_next_line(int fd);
    int my_strcmp(char const *, char const *);
    char *my_getnbr_base(long, char *);
    char *my_strcat(char *, char *);
    char *get_next_line(int );
    int strcmp_begin(char *, char *);
    char *summ_calc(char *, char *, int);
    int my_getnbr(char const *);
    void my_revbit(char *);
    int spe_num(char *);
    char **str_to_wordtab(char *, char);
    char **my_str_tab(char *);
    char *bin_hex(char *);
    char *cnc(char *, char *);
    void aff_err(void);
    char **my_double_malloc(int, int);
    void not_header(char **, int);
    void living(char **, int);
    void lding(char **, int);
    void sting(char **, int);
    void adding(char **, int);
    void subing(char **, int);
    void anding(char **, int);
    void oring(char **, int);
    void xoring(char **, int);
    void zjmping(char **, int);
    void ldiing(char **, int);
    void stiing(char **, int);
    void forking(char **, int);
    void llding(char **, int);
    void lldiing(char **, int);
    void lforking(char **, int);
    void clive(char *,int); //
    void cld(char *, int); // % = 90 premiere valeur
    void cst(char *, int); //
    void cadd(char *, int); //
    void csub(char *, int); //
    void cand(char *, int); //
    void cor(char *, int); //
    void cxor(char *, int); //
    void czjmp(char *, int); //
    void cldi(char *, int); //
    void csti(char *, int); //
    void cfork(char *, int); //
    void clld(char *, int); //
    void clldi(char *, int); //
    void clfork(char *, int); //
    void caff(char *, int); //

    //asm
    int asming(char *name);
    int setting_comment(char *, header_t *);
    int setting_name(char *, header_t *);
    int display_header(header_t *, char *);

#endif /* !COREWAR_H_ */