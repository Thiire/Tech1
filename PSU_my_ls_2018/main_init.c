/*
** EPITECH PROJECT, 2019
** main_init.c
** File description:
** main_init.c
*/

#include "subject.h"

char *my_strcat(char *path)
{
    char *result;
    int length1 = 0;
    int length2 = 0;
    int n = 0;

    if (name[0] == ".")
        return (path);
    for (length1 = 0; name[0][length1] != '\0'; length1++);
    for (length2 = 0; path[length2] != '\0'; length2++);
    result = malloc(sizeof(char) * (length1 + length2) + 1);
    for (int i = 0; name[0][i] != '\0'; i++)
        result[i] = name[0][i];
    result[length1 + 1] = '/';
    for (int i = length1 + 1; path[n] != '\0'; i++, n++)
        result[i] = path[n];
    result[length1 + length2] = '\0';
    return (result);
}

void flago(void)
{
    flg.R = 0;
    flg.l = 0;
    flg.d = 0;
    flg.r = 0;
    flg.t = 0;
}

void l2_flag(struct stat fileStat)
{
    my_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
}

int l_flag(DIR *fichier, struct dirent *lecture, struct stat fileStat)
{
    struct passwd *user;
    struct group *scd_user;
    char *timer;

    while ((lecture = readdir(fichier)) != NULL) {
        if (lecture->d_name[0] != '.') {
            stat(my_strcat(lecture->d_name),&fileStat);
            timer = ctime(&fileStat.st_mtime);
            timer += 4;
            timer[12] = '\0';
            user = getpwuid(fileStat.st_uid);
            scd_user = getgrgid(fileStat.st_gid);
            l2_flag(fileStat);
            my_printf(" %d %s", fileStat.st_nlink, user->pw_name);
            my_printf(" %s", scd_user->gr_name);
            my_printf(" %d", fileStat.st_size);
            my_printf(" %s", timer);
            my_printf(" %s\n", lecture->d_name);
        }
    }
}

int total(DIR *fichier, struct dirent *lecture, struct stat fileStat)
{
    long total = 0;

    while ((lecture = readdir(fichier)) != NULL) {
        if (lecture->d_name[0] != '.') {
            stat(my_strcat(lecture->d_name),&fileStat);
            total += fileStat.st_blocks / 2;
        }
    }
    closedir(fichier);
    opendir(name[0]);
    my_printf("total %ld\n", total);
    return (l_flag(fichier, lecture, fileStat));
}

int chooser(DIR *fichier)
{
    struct dirent *lecture;
    struct stat fileStat;

    if (flg.l == 0 && flg.d == 0 && flg.R == 0 && flg.r == 0 && flg.t == 0)
        while ((lecture = readdir(fichier)) != NULL)
            if (lecture->d_name[0] != '.')
                my_printf("%s\n", lecture->d_name);
    if (flg.l == 1 && flg.d == 0 && flg.R == 0 && flg.r == 0 && flg.t == 0)
        total(fichier, lecture, fileStat);
    return (0);
}

int namer(int ac, char **av)
{
    for (int i = 1; i < ac && av[i][0] == '-'; i++) {
        for (int n = 1; av[i][n] != '\0' && i != 0; n++) {
            flg.l = (flg.l != 1 && av[i][n] == 'l') ? 1 : 0;
            flg.R = (flg.R != 1 && av[i][n] == 'R') ? 1 : 0;
            flg.d = (flg.d != 1 && av[i][n] == 'd') ? 1 : 0;
            flg.r = (flg.r != 1 && av[i][n] == 'r') ? 1 : 0;
            flg.t = (flg.t != 1 && av[i][n] == 't') ? 1 : 0;
            i = (av[i][n] != 'l' && av[i][n] != 'R' && av[i][n] != 'd' &&
            av[i][n] != 'r' && av[i][n] != 't') ? 0 : i;
        }
        if (i == 0)
            return (2);
    }
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            name[position] = av[i];
            position++;
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    DIR *fichier;

    position = 0;
    name = malloc(sizeof(char *) * ac);
    for (int i = 0; i < ac; i++)
        name[i] = malloc(sizeof(char) * ac);
    flago();
    name[0] = ".";
    if (namer(ac, av) == 2) {
        my_printf("Invalid flag\n");
        return (84);
    }
    fichier = opendir(name[0]);
    if (fichier == NULL) {
        my_printf("Invalid folder\n");
        return (84);
    }
    chooser(fichier);
    return (0);
}