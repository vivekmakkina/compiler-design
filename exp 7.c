#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the symbol table
#define MAX_SIZE 100

// Structure to represent an entry in the symbol table
typedef struct {
    char name[20];
    int value;
} Entry;

// Symbol table array
Entry symbolTable[MAX_SIZE];
int symbolCount = 0;

// Function to insert an entry into the symbol table
void insert(const char *name, int value) {
    if (symbolCount < MAX_SIZE) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].value = value;
        symbolCount++;
        printf("Inserted: %s = %d\n", name, value);
    } else {
        printf("Symbol table is full. Cannot insert.\n");
    }
}

// Function to search for an entry in the symbol table
int search(const char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].value;
        }
    }
    return -1; // Not found
}

// Function to delete an entry from the symbol table
void deleteEntry(const char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Deleted: %s = %d\n", symbolTable[i].name, symbolTable[i].value);
            for (int j = i; j < symbolCount - 1; j++) {
                symbolTable[j] = symbolTable[j + 1];
            }
            symbolCount--;
            return;
        }
    }
    printf("Entry not found. Cannot delete.\n");
}

int main() {
    insert("x", 10);
    insert("y", 20);

    printf("Value of x: %d\n", search("x"));
    printf("Value of y: %d\n", search("y"));
    printf("Value of z: %d\n", search("z"));

    deleteEntry("x");
    printf("Value of x after deletion: %d\n", search("x"));

    return 0;
}
