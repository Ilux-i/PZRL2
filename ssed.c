
#include "ssed.h"

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sed_replace(char *filename, char *before, char *after) {
    
    FILE *tmp = tmpfile(); // Временный файл
    FILE *f = fopen(filename, "r");
    
    //Копирование основной файл во временный
    int c;
    while ((c = fgetc(f)) != EOF) {
        fputc(c, tmp);
    }

    fseek(tmp, 0, SEEK_SET);
    fclose(f);

    f = fopen(filename, "w");

    size_t trash;
    size_t len;
    char *line = malloc(sizeof(char) * 32);

    while ((len = getline(&line, &trash, tmp)) != -1) {
        char *line_s = line;
    
        while (*line_s != '\0') {

            while (strncmp(before, line_s, strlen(before)) != 0 && strlen(line_s) >= strlen(before)) {
                putc(*line_s, f);
                line_s++;
            }
            if (strlen(line_s) >= strlen(before)) {
                fputs(after, f);
                line_s += strlen(before);
            } else {
                fputs(line_s, f);
                line_s += strlen(line_s);
            }
        }
    }

    free(line);
    fclose(f);
    fclose(tmp);
}

void sed_delete(char *filename, char *pattern) {
    //Перенаправление в Replace с пустой строчкой after
    char after[] = "";
    sed_replace(filename, pattern, after);
}

void sed_add_suffix(char *filename, char *text) {
    FILE *f = fopen(filename, "a");
    fwrite(text, sizeof(char), strlen(text), f);
    fclose(f);
}

/*
создаём временный файл в начало которого пишем text
копируем основной файл перед text
копируем временный файл в основной(на тот момент уже пустой)
*/
void sed_add_prefix(char *filename, char *text) {
    FILE *tmp = tmpfile();
    FILE *f = fopen(filename, "r");
    fwrite(text, sizeof(char), strlen(text), tmp);
    
    int c;
    while ((c = fgetc(f)) != EOF) {
        fputc(c, tmp);
        printf("%c", c);
    }
    
    fclose(f);
    fseek(tmp, 0, SEEK_SET);
    f = fopen(filename, "w");
    
    while ((c = fgetc(tmp)) != EOF) {
        fputc(c, f);
        printf("%c", c);
    }
    
    fclose(f);
    fclose(tmp);
}

