/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_direct
*/

#include "redcode.h"

int compile_direct(args_t *param, FILE *fd)
{
    int dir = 0x0;

    if (!param || !fd)
        return FAILURE;
    if (param->is_lab)
        return SUCCESS;
    dir |= my_getnbr(param->arg);
    print_reversed_bytes(dir, fd, 24);
    return SUCCESS;
}
