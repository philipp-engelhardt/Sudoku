#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 9

void print_grid(int grid[SIZE][SIZE]) {
    char c;

    printf("    ");
    for (c = 'A'; c <= 'I'; c++) {
        printf("%c ", c);
        if ((c - 'A' + 1) % 3 == 0) {
            printf("  ");
        }
    }
    printf("\n");
    printf("  +-------+-------+-------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d | ", i+1);
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("x ");
            } else {
                printf("%d ", grid[i][j]);
            }
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("|\n");
        if (i == 2 || i == 5) {
            printf("  +-------+-------+-------+\n");
        }
    }
    printf("  +-------+-------+-------+\n");
}

void eingabe(int grid[SIZE][SIZE]) {

    int ikoordinate;
    char jkoordinate;
    int wert;
    int convert = 0;



    printf("Machen Sie ihren Zug: \n");
    printf("Buchstabe zwischen A-I : ");
    scanf("%c", &jkoordinate);
    while (!isalpha(jkoordinate)) {
        scanf(" %c", &jkoordinate);
    }


    printf("Zahl zwischen 1-9: ");
    scanf("%d", &ikoordinate);
    while (ikoordinate <= 0) {
        scanf("%d", &ikoordinate);
    }


    switch (jkoordinate) {

        case 'A' :
            convert = 0;break;
        case 'B' :
            convert = 1;break;
        case 'C' :
            convert = 2;break;
        case 'D' :
            convert = 3;break;
        case 'E' :
            convert = 4;break;
        case 'F' :
            convert = 5;break;
        case 'G' :
            convert = 6;break;
        case 'H' :
            convert = 7;break;
        case 'I' :
            convert = 8;break;
    }

    ikoordinate--;

    printf("Feld füllen mit Zahl zwischen 1-9: \n");
    scanf("%d", &wert);

    grid[ikoordinate][convert] = wert;
}


int main() {
    int name;
    int grid[SIZE][SIZE];
    int ende_flag=0;
    srand(time(NULL));


    printf("Name des Spielers: ");
    scanf("%d", &name);
    getchar();

    // Fill diagonal 3x3 grids with random numbers
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            int nums[SIZE] = {1,2,3,4,5,6,7,8,9};
            for (int k = 0; k < SIZE; k++) {
                int r = rand() % (SIZE - k) + k;
                int temp = nums[r];
                nums[r] = nums[k];
                nums[k] = temp;
                int random = rand() % (SIZE + 1);
                // Randomly choose to fill a cell with a number or leave it empty
                if (random < SIZE) {
                    grid[i + k % 3][j + k / 3] = temp;
                } else {
                    grid[i + k % 3][j + k / 3] = 0;
                }
            }
        }
    }


   while (ende_flag == 0) {

    print_grid(grid);
    eingabe(grid);
    printf("\n");
   }



    return 0;
}
