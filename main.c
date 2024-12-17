
#include "ssed.h"
#include "files.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char *program_name;

// Проверки на ошибку пользовательского ввода и распределение на запрсы по флагам
int main(int argc, char *args[]) {
    program_name = args[0];
    if (argc > 2) {
        if (!is_file_exist(args[1]))
            printf("File not exist: %s\n", args[1]);
        if (is_directory(args[1]))
            printf("It is directory: %s\n", args[1]);
        
        if (argc == 3) {  /*       ./ssed file cmd         */
            // sed_parse_cmd(args[1], args[2]);
            printf("It's regex function\n");
        } else {          /*  ./ssed file -flag pattern... */
            if (args[2][0] != '-') {
                // help_message();
                printf("Flag not found\n");
            }
            if (strcmp(args[2], "-r") == 0) {
                if (argc != 5)
                    printf("Replace must be: %s -r old new\n", program_name);
                sed_replace(args[1], args[3], args[4]);
            } else if (strcmp(args[2], "-d") == 0) {
                if (argc != 4)
                    printf("Delete must be: %s -d pattern\n", program_name);
                sed_delete(args[1], args[3]);
            } else if (strcmp(args[2], "-i") == 0) {
                if (argc != 5)
                    printf("Insert must be: %s -i -f/b text\n", program_name);
                
                if (strcmp(args[3], "-b") == 0) {
                    sed_add_suffix(args[1], args[4]);
                } else if (strcmp(args[3], "-f") == 0) {
                    sed_add_prefix(args[1], args[4]);
                } else {
                    printf("Unknown flag: %s\n", args[3]);    
                }
            } else {
                printf("Unknown flag: %s\n", args[2]);
            }
        }
    }
}