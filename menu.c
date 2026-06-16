#include <stdio.h>
#include "menu.h"
#include "scan.h"

// TODO: change integer as enum
Menu menu_list[7] = {
    {1, "View Tasks"},
    {2, "Add Tasks"},
    {3, "Complete Tasks"},
    {4, "Edit Tasks"},
    {5, "Delete Tasks"},
    {6, "Save Tasks"},
    {7, "Exit"},
};

const int menu_len = sizeof(menu_list) / sizeof(menu_list[0]);

void print_menu(Menu menu[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d %s\n", menu[i].number, menu[i].title);
    }
}

int select_menu() {
    int select;
    if (!prompt_int("Choose an option: ", 10, &select)) {
        fprintf(stderr, "Invalid option. Please choose a number from 1 to 7.\n\n");
        return 0;
    }

    for (int i = 0; i < menu_len; i++) {
        if (menu_list[i].number == select) {
            return select;
        }
    }

    return 0;
}

