#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
void insertionSort(int elementsint[], int n) {
    int i, temp, j;
    for (i = 1; i <= n+1; i++) {
        temp = elementsint[i];
        j = i - 1;

        while (j >= 0 && elementsint[j] > temp) {
            elementsint[j + 1] = elementsint[j];
            j = j - 1;
        }
        elementsint[j + 1] = temp;
    }
}

void linearSearch(int size, int elementsint[], int num, FILE *outFile) {
    int flag = 0;
    clock_t start, end;                    //measure time take to search
    start = clock();

    insertionSort(elementsint, size);

    for (int i = 0; i <= size+1; i++) {
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

int binarySearch(int size, int elementsint[], int num, FILE *outFile2) {
    int left = 0;
    int right = size-1;
    int mid = (left + right)/2;
    clock_t start, end;                  //meaure time taken to search
    start = clock();

    insertionSort(elementsint, size);

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
    int size, num, line;
    char a[20];
    char *elements = (char *)malloc(3000000 * sizeof(char));

    printf("Enter test case size from 1 to 15: ");
    scanf("%d", &line);
    if (line > 15 || line < 1) {
        printf("Invalid size\n");
        exit(1);
    }

    FILE *fptr = fopen("testCaseSize.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for(int i = 1; i <= line; i++) {
        (fgets(a, sizeof(a), fptr));            //jumping to line of size provided by user in testCaseSize file
        }
        fclose(fptr);
        size = atoi(a);
    
    printf("Enter number to be searched: ");
    scanf("%d", &num);
    
    FILE *fptr2 = fopen("searchTestCase.txt", "r");
    if (fptr2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for(int i = 1; i <= line; i++) {
        fgets(elements, 3000000, fptr2);        //saving all characters of that line in char array
    }
    fclose(fptr2);

    int *elementsint = (int *)malloc(491520 * sizeof(int));
    int i = 0;
    char *token = strtok(elements, " ");
    elementsint[0] = atoi(token);
    while ((token = strtok(NULL, " ")) != NULL) {            //tokenizing each individual element in the char array to an int array
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
