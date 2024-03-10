#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void linearSearch(int size, int elementsint[size], int num, FILE *outFile) {
    int flag = 0;
    clock_t start, end;                    //measure time take to search
    start = clock();
    for (int i = 0; i < size; i++) {
        if (elementsint[i] == num) {
            end = clock();
            fprintf(outFile, "Input Position Search_time\n");
            fprintf(outFile, "%d %d %d\n", num, i, (int)end);
            flag = 1;
        }
    }
    if (flag == 0) {
        fprintf(outFile, "Element not found\n");
    }
}

int binarySearch(int size, int elementsint[size], int num, FILE *outFile2) {
    int left = 0;
    int right = size-1;
    int mid = (left + right)/2;
    clock_t start, end;                  //meaure time taken to search
    start = clock();
    while (left <= right) {
        if (num > elementsint[mid]) {
            left = mid + 1;
            mid = (left + right)/2;
        }
        else if (num < elementsint[mid]) {
            right = mid - 1;
            mid = (left + right)/2;
        }
        else if (num == elementsint[mid]) {
            end = clock();
            fprintf(outFile2, "Input Position Search_time\n");
            fprintf(outFile2, "%d %d %d", num, mid, (int)end);
            return 0;
        }
    }
        fprintf(outFile2, "Element not found\n");
    
}

int main() {
    int size, num;
    char a[2];
    char elements[100];
    
    FILE *fptr = fopen("testCaseSize.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    if (fgets(a, sizeof(a), fptr)) {
        size = atoi(a);                                    //converting size from fgets string to int
    }
    fclose(fptr);
    
    if (size > 15) {
        printf("Invalid size\n");
        exit(1);
    }
    
    printf("Enter number to be searched: ");
    scanf("%d", &num);
    
    FILE *fptr2 = fopen("searchTestCase.txt", "r");
    if (fptr2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fgets(elements, sizeof(elements), fptr2);
    fclose(fptr2);

    int elementsint[size];
    int i = 0;
    char *token = strtok(elements, " ");
    elementsint[0] = atoi(token);                      //using string tokenizer to separate individual numbers and store in array
    while ((token = strtok(NULL, " ")) != NULL) {
        i++;
        elementsint[i] = atoi(token);
    }

    FILE *outFile = fopen("linearSearchResults.txt", "w");
    if (outFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    linearSearch(size, elementsint, num, outFile);
    fclose(outFile);
    
    FILE *outFile2 = fopen("binarySearchResults.txt", "w");
    if (outFile2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    binarySearch(size, elementsint, num, outFile2);
    fclose(outFile2);

    return 0;
}
