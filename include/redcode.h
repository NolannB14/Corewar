/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include "redcode/compil.h"
    #include "redcode/infos.h"
    #include "redcode/lexer_parser.h"
    #include "my.h"

    #include <stdlib.h>
    #include <stdio.h>

    #define HELP_ASM "assets/asm_help.txt"
    #define SUCCESS 0
    #define FAILURE 84
    #define FAILURE_LEX -1
    #define SUCCESS_LEX 2

int launch(int argc, char * const argv[]);

/* Utils */

int my_strcmp_insensitive(const char *s1, const char *s2);
char *load_file(char *filepath);
char **str_sep_to_array(char *str, char sep);
int reverse_int_bytes(int to_reverse);
int print_reversed_bytes(int to_reverse, FILE *fd, int complete_byte);

/* Headers function */

int create_header(infos_t *infos);

/* Filename management */

char *get_output_filename(char *input_filename);
char *get_output_filename_no_ext(char *output_filename);

/* Error handling */

int check_args(char * const argv[]);
int check_name_and_comment(char **file_lines);

int check_args(char * const argv[]);
int print_error(char *str, int i, int status);

/* destroy collected infos */
void free_collected_infos(infos_t *infos);
void free_instructions(infos_t *infos);

#endif /* !ASM_H_ */
