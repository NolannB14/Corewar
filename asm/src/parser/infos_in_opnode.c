/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** infos_in_cmd_node
*/

#include <stdbool.h>
#include <stdlib.h>
#include "redcode.h"
#include "my.h"

static const op_t op[] = {
    {"live", 1, {T_DIR}, LIVE, 10, "alive", false, {false}},
    {"ld", 2, {T_DIR | T_IND, T_REG}, LD, 5, "load", true, {false, false}},
    {"st", 2, {T_REG, T_IND | T_REG}, ST, 5, "store", true, {false, false}},
    {"add", 3, {T_REG, T_REG, T_REG}, ADD, 10, "addition", true,
    {false, false, false}},
    {"sub", 3, {T_REG, T_REG, T_REG}, SUB, 10, "soustraction", true,
    {false, false, false}},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, AND, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3", true, {false, false, false}},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, OR, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3", true, {false, false, false}},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, XOR, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3", true, {false, false, false}},
    {"zjmp", 1, {T_DIR}, ZJUMP, 20, "jump if zero", false, {true}},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, LDI, 25,
    "load index", true, {true, true, false}},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, STI, 25,
    "store index", true, {false, true, true}},
    {"fork", 1, {T_DIR}, FORK, 800, "fork", false, {true}},
    {"lld", 2, {T_DIR | T_IND, T_REG}, LLD, 10, "long load", true,
    {false, false}},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, LLDI, 50,
    "long load index", true, {true, true, false}},
    {"lfork", 1, {T_DIR}, LFORK, 1000, "long fork", false, {true}},
    {"aff", 1, {T_REG}, AFF, 2, "aff", true, {false}},
    {0}
};

static int check_opargs(char **temp_instruction, opnode_t *node, int i, int y)
{
    char **move_array = temp_instruction + 1;
    int size = array_size(move_array);

    if (size != op[i].nbr_args)
        return print_error(PARSER_ERR_NBARG, y, FAILURE);
    node->type = op[i].cmd;
    node->params_type = op[i].print_params;
    node->cycle = op[i].nbr_cycles;
    return get_params(node, op[i], temp_instruction);
}

static int get_optype(opnode_t *node, char **line, int y)
{
    if (!node || !line || !(*line))
        return FAILURE;
    for (unsigned int i = 0; op[i].mnemonique; i += 1) {
        if (my_strcmp(op[i].mnemonique, line[0]) == SUCCESS)
            return check_opargs(line, node, i, y);
    }
    return print_error(PARSER_ERR_INST, y, FAILURE);
}

static int is_name(char *poss_name)
{
    int size = my_strlen(poss_name) - 1;

    if (poss_name[size] == LABEL_CHAR)
        return 1;
    return 0;
}

int infos_in_opnode(char *line, opnode_t *node, int y)
{
    char **arr = NULL;
    int index = 0;

    if (!line || !node || y < 0)
        return FAILURE;
    if (!(arr = str_to_array_choice(line, SEPARATOR)))
        return print_error(PARSER_ERR_DUP, y, FAILURE);
    if ((index = is_name(arr[0])))
        node->fun_name = my_strndup(arr[0], my_strlen(arr[0]) - 1);
    if (get_optype(node, arr + index, y) != SUCCESS && !index)
        return FAILURE;
    if (node->fun_name && is_label(node->fun_name) != SUCCESS)
        return print_error(PARSER_ERR_LAB, 0, FAILURE);
    free_array((void **)arr);
    return SUCCESS;
}
