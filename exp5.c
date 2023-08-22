#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the Follow sets for non-terminals
const char *followSets[] = {
    "$",            // Follow(E)
    "+-$",          // Follow(T)
    "*+-$",         // Follow(F)
    "$"             // Follow(S)
};

// Function to check if a given terminal is in the Follow set of a non-terminal
bool isInFollowSet(char nonTerminal, char terminal) {
    const char *followSet = followSets[nonTerminal - 'E']; // Convert 'E' to 0, 'T' to 1, etc.

    if (strchr(followSet, terminal) != NULL) {
        return true;
    }

    return false;
}

int main() {
    char nonTerminal;
    char terminal;

    printf("Enter a non-terminal (E, T, F, S): ");
    scanf(" %c", &nonTerminal);

    printf("Enter a terminal: ");
    scanf(" %c", &terminal);

    if (isInFollowSet(nonTerminal, terminal)) {
        printf("%c is in the Follow set of %c.\n", terminal, nonTerminal);
    } else {
        printf("%c is NOT in the Follow set of %c.\n", terminal, nonTerminal);
    }

    return 0;
}
