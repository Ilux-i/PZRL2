
#include "methods.h"
#include <stdlib.h>
#include <stdio.h>

// void Read_file(char* file){
// // файл чтения
//     char * filename = file;
//     // буфер для считавания данных из файла
//     char buffer[256];
//     // чтение из файла
//     FILE *fp = fopen(filename, "r");
//     if(fp)
//     {
//         // пока не дойдем до конца, считываем по 256 байт
//         while((fgets(buffer, 256, fp)) != NULL)
//         {
//             printf("%s", buffer);
//         }
//         fclose(fp);
//     } 
// }

// void Write_file(char *message, char *filename){
//     // файл для записи
//     // char * filename = "data.txt";
//     // запись в файл
//     FILE *fp = fopen(filename, "w");
//     if(fp)
//     {
//         // записываем строку
//         fputs(message, fp);
//         fclose(fp);
//         printf("File has been written\n");
//     }
// }

void Replace(char *file, const char *old_text, const char *new_text){
    printf("Succes replace\n");
}

void Delete(char *file, const char *del_text){
    printf("Succes delete\n");
}

void Insert(char *file, char flag, const char *insert_text){
    
    switch(flag){
    case 'f':
        printf("Succes insert front\n");
        break;

    case 'b':
        printf("Succes insert back\n");
        break

    default:
        break;
    }
}