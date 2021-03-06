/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** struct.h
*/

#ifndef STRUCT_COREWAR_H_
    #define STRUCT_COREWAR_H_

    #include <sys/types.h>
    #include "corewar/infos.h"

/*
* @brief A warrior in the VM
* @param name The name of the warrior
* @param id The id of the warrior
* @param instruction_address The address of the next instruction of the warrior
*/
typedef struct warrior_s {
    char *filename;
    char *name;
    int id;
    int size;
    int pc;
    int cycle_rest;
    int carry;
    int *reg;
    char *save;
    char *warrior_code;
    u_int instruction_address;
    struct warrior_s *next;
    struct warrior_s *prev;
} warrior_t;

/*
* @brief The list of the warriors in the VM
* @param head THe head of the linked list of warriors
* @param nbr_of_warriors The number of warriors on the VM
*/
typedef struct warriors_list_s {
    warrior_t *head;
    u_int id_of_warriors;
    u_int nbr_of_warriors;
} warriors_list_t;

typedef struct parameters_s {
    char *n_parameter;
    char *a_parameter;
} parameters_t;

/*
* @brief General structure for the Corewar VM
* @param nbr_cycles The number of cycles
* @param nbr_of_cycle in order to dump memory
* @param warrior_list List of all the warriors
* @param memory The actual memory of the VM
* @param old_memory The old memory of the VM
*/
typedef struct corewar_s {
    int nbr_cycles;
    warriors_list_t warrior_list;
    parameters_t *params;
    int dump_cycles;
    char memory[MEM_SIZE];
    char old_memory[MEM_SIZE];
} corewar_t;

/*
* @brief General structure for instructions of Corewar
* @param instruction The instructions of the Corewar in hexadecimal format
* @param ptr The pointers that redirect to the execution of instructions
*/
typedef struct instructions_s {
    int instruction;
    int (*ptr)(warrior_t *warrior, corewar_t *corewar);
} instructions_t;

typedef struct arguments_s {
    int t_argrs[3];
    unsigned char reg[3];
    unsigned char ind[3];
    unsigned char dir[3];
} argument_t;

#endif /* !STRUCT_COREWAR_H_ */
