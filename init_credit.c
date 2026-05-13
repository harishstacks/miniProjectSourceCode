// This program initializes credit.dat with 100 empty clientData records
#include <stdio.h>
#include <stdlib.h>

struct clientData {
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main() {
    FILE *cfPtr;
    struct clientData blankClient = {0, "", "", 0.0};
    int i;
    if ((cfPtr = fopen("credit.dat", "wb")) == NULL) {
        puts("File could not be created.");
        exit(1);
    }
    for (i = 0; i < 100; ++i) {
        fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
    }
    fclose(cfPtr);
    puts("credit.dat initialized with 100 empty records.");
    return 0;
}
