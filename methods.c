
#include "methods.h"
#include <stdlib.h>
#include <stdio.h>

void read_file(char* file){
// файл чтения
    char * filename = file;
    // буфер для считавания данных из файла
    char buffer[256];
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(buffer, 256, fp)) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    } 
}

void write_file(char *message, char *filename)
{
    // файл для записи
    // char * filename = "data.txt";
    // запись в файл
    FILE *fp = fopen(filename, "w");
    if(fp)
    {
        // записываем строку
        fputs(message, fp);
        fclose(fp);
        printf("File has been written\n");
    }
}