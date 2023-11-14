
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 2613
#define MAX_COLS 128
#define MAX_APR 64
#define rows 2613;
#define cols 128;
#define APR 64;


void readCSV(const char* filename, float array[MAX_ROWS][MAX_COLS]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    int row = 0;
    while (fgets(line, sizeof(line), file) != NULL && row < MAX_ROWS) {
        int col = 0;
        char* token = strtok(line, ",");
        while (token != NULL && col < MAX_COLS) {
            array[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(file);
}

// File 2

void readCSV2(const char* filename, float array[MAX_ROWS][MAX_APR]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    int row = 0;
    while (fgets(line, sizeof(line), file) != NULL && row < MAX_ROWS) {
        int col = 0;
        char* token = strtok(line, ",");
        while (token != NULL && col < MAX_COLS) {
            array[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(file);
}


void main() {
  //  int APR = 64;
    float Input[MAX_ROWS][MAX_COLS];
    float Delay[MAX_ROWS][MAX_APR];
    float bf[MAX_ROWS];
	//int cols =  128;
	//int rows  = 2613;

    // Read CSV data into Input and Delay arrays
    readCSV("Transmit65.csv", Input);
    readCSV2("Delay.csv", Delay);

    // Call the HLS-accelerated function
    CFBfun(Delay, Input, bf);

    // Additional code for processing the BF array if needed

}
