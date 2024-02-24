#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define MAX_STRING_LENGTH 100

int front = -1;
int rear = -1;
char inp_array[SIZE][100];
char gpastorage[SIZE][5]; // Increased size to store a null terminator
int j = 0;
int temp = 0;

void enqueue(char inp[100]) {
    if (rear == SIZE - 1) {
        rear = -1;
    }

    rear = rear + 1;
    strcpy(inp_array[rear], inp);
}

void dequeue(FILE *outFile) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    char gpa[20];
    strncpy(gpa, inp_array[front] + 26, 4);
    float gpaint = atof(gpa);

    if (gpaint < 9) {
        strncpy(gpastorage[j], inp_array[front] + 12, 4);
        j++;
    }

    fprintf(outFile, "%s", inp_array[front]);
    printf("%s", inp_array[front]);

    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front = front + 1;
    }

    temp++;
}

int main() {
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

    // Dequeue and process, printing everything
    while (temp < 5) {
        dequeue(outFile);
    }

    printf("\nStudents with GPA < 9:");
    for (int i = 0; i < j; i++) {
        printf("\n%s", gpastorage[i]);
        fprintf(outFile, "\n%s", gpastorage[i]);
    }

    fclose(outFile);

    return 0;
}
