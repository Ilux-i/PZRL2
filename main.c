// -r замена текста на новый
// -d удаление текста
// -i -f добавить текст в начало
// -f -b добавить текст в конец

#include <stdio.h>
#include <stdlib.h>
#include "methods.h"

// #define FILE "data.txt"
// #define MESS "Hello METANIT.COM!\nAn apple a day keeps the doctor away\n"

  
int main(int argc, const char *argv[])
{

    int count = 0;
    while(argv[count] != '\0'){
        count++;
    }

    // char file[] = argv[1];
    char file[] = "data.txt";
    char flag_1, flag_2;

    if(count > 3){
        flag_1 = argv[2][1];

        switch(flag_1){
        case 'r':
            Replace(file, argv[3], argv[4]);
            break;

        case 'd':
            Delete(file, argv[3]);
            break;

        case 'i':
            flag_2 = argv[3][1];
            Insert(file, flag_2, argv[4]);
            break;

        default:
            printf("Не правильная запись\n");
            break;
        }

    } else if(count == 5){

        printf("Регулярные выражения\n");

    } else {

        printf("Не правильная запись\n");

    }
    
    return 0;
}
  