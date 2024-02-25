#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int front = 2;
int rear = 2;
char inp_array[SIZE][100];
char gpastorage[SIZE][5];
int j = 0;
int temp = 0;

void enqueue(char inp[100]) {
    
    if (rear == SIZE - 1) {        //circular queue reset
        rear = -1;
    }
    
    rear = rear + 1;
    strcpy(inp_array[rear], inp);
}

void dequeue(FILE *outFile) {

    char gpa[20];
    strncpy(gpa, inp_array[front] + 26, 4);            //jumping to gpa in each array
    float gpaint = atof(gpa);

    if (gpaint < 9) {
        strncpy(gpastorage[j], inp_array[front] + 12, 4);    //collecting names of students below 9 GPA
        j++;
    }

    fprintf(outFile, "%s", inp_array[front]);
    printf("%s", inp_array[front]);
    
    if (front == SIZE - 1) {            //circular queue reset
        front = 0;
    } else {
        front = front + 1;
    }

    temp++;
}

int main() {
    int front = -1;
    char a[100];
    FILE *fptr = fopen("studentin.dat", "r");
    FILE *outFile = fopen("studentout.dat", "w");

    if (fptr == NULL || outFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(a, sizeof(a), fptr)) {
        enqueue(a);
    }

    fclose(fptr);

    while (temp < SIZE) {
        dequeue(outFile);
    }

    printf("\nStudents with GPA < 9:\n");
    fprintf(outFile, "\nStudents with GPA < 9:\n");
    
    for (int i = 0; i < j; i++) {
        printf("%s\n", gpastorage[i]);
        fprintf(outFile, "%s\n", gpastorage[i]);            //printing names of students below 9 GPA
    }

    fclose(outFile);

    return 0;
}
