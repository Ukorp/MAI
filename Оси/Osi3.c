#include <stdio.h>
#include <stdlib.h>

typedef enum errors{
    OK, ARGUMENT_ERROR, FILE_ERROR 
}errors;

int main(int argc, char * argv[]){
    FILE * file1, * file2;
    char tmp;
    if (argc != 3){
        printf("Неверное число аргументов\n");
        return ARGUMENT_ERROR;
    }
    if ((file1 = fopen(argv[1], "r")) == 0){
        printf("Ошибка открытия файла\n");
        return FILE_ERROR;
    }
    if ((file2 = fopen(argv[2], "w+")) == 0){
        printf("Ошибка открытия файла\n");
        fclose(file1);
        return FILE_ERROR;
    }
    while((tmp = fgetc(file1)) != EOF){
        fputc(tmp, file2);
    }
    printf("Выполнено\n");
    fclose(file1);
    fclose(file2);
    return OK;
}