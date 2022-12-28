#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *file;


void replaceChar(char *str, char find, char replace);


void createTaskField() {
    printf("+----+--------------------+--------------------------+\n");
    printf("| ID | NAME               | CREATED AT               |\n");
    printf("+----+--------------------+--------------------------+\n");
}

char *getDateTime() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime (timeinfo);
}

void createdTask() {
    printf("What task do you want to create?\n");
    char userTask[20];
    for(int i = 0; i < 20; i++) {
        userTask[i] = ' ';
    }
    userTask[19] = '|';

    char tmp[19];
    fgets(tmp, sizeof(tmp), stdin);
    int k = 0;
    while (tmp[k] != NULL) {
        userTask[k] = tmp[k];
        k++;
    };
    printf("k = %d\n", k);

    if (userTask[0] != '\0') {
        file = fopen("tasks.txt", "a");
            char userTaskAndData[100];
            char *dateTime = getDateTime();
            replaceChar(userTask, '\n', ' ');
            replaceChar(dateTime, '\n', ' ');
            sprintf(userTaskAndData, "%s %s|\n", userTask, dateTime);
            fprintf(file, "%s", userTaskAndData);
        fclose(file);
    } else {
        printf("You didn't enter a task.\n");
    }

    printf("Task created.\n");
}

void getAllTasksInTable(){
    file = fopen("tasks.txt", "r");
    char currentLine[100];

    int idOfTask = 1;
    createTaskField();
    while(fgets(currentLine, sizeof(currentLine), file) != NULL) {
        printf("| %d  | %s", idOfTask, currentLine);
        printf("+----+--------------------+--------------------------+\n");
        idOfTask++;
    }


}

int main(int argc, char *argv[])
{
    createdTask();
    getAllTasksInTable();
    return 0;
}


void replaceChar(char *str, char find, char replace) {
    while(*str) {
        if(*str == find) {
            *str = replace;
        }
        str++;
    }
}