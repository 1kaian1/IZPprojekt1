#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 101

char names[MAX_ENTRIES][MAX_LENGTH]; // Pole pro jména
char phone_numbers[MAX_ENTRIES][MAX_LENGTH]; // Pole pro telefonní čísla

void read_input_list() {
    char string[MAX_LENGTH];
    int index = 0;

    // Čtení vstupu, dokud je k dispozici
    while (index < MAX_ENTRIES) {
        // Načtení jména
        printf("Zadejte jméno (nebo stiskněte Enter pro konec): ");
        if (fgets(string, sizeof(string), stdin) == NULL || strcmp(string, "\n") == 0) {
            break; // Konec, pokud je vstup prázdný
        }

        // Odstranění nového řádku
        string[strcspn(string, "\n")] = '\0';
        strcpy(names[index], string);

        // Načtení telefonního čísla
        printf("Zadejte telefonní číslo: ");
        if (fgets(string, sizeof(string), stdin) == NULL || strcmp(string, "\n") == 0) {
            break; // Konec, pokud je vstup prázdný
        }

        // Odstranění nového řádku
        string[strcspn(string, "\n")] = '\0';
        strcpy(phone_numbers[index], string);
        index++;
    }

    // Výpis uložených jmen a telefonních čísel
    printf("\nNačtené záznamy:\n");
    for (int i = 0; i < index; i++) {
        printf("Jméno: %s, Telefonní číslo: %s\n", names[i], phone_numbers[i]);
    }
}

int main() {
    read_input_list();
    return 0;
}
