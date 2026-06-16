#include <string.h>
#include <stdio.h>
#include "scan.h"
#include "menu.h"

int main(void) {
    Menu menu_list[7] = {
        {1, "View Tasks"},
        {2, "Add Tasks"},
        {3, "Complete Tasks"},
        {4, "Edit Tasks"},
        {5, "Delete Tasks"},
        {6, "Save Tasks"},
        {7, "Exit"},
    };

    while(1) {
        int menu_len = sizeof(menu_list) / sizeof(menu_list[0]);

        print_menu(menu_list, menu_len);

        int select = select_menu();
        if (!select) {
            fprintf(stderr, "Invalid option. Please choose a number from 1 to 7.\n\n");
            continue;
        }

        if (select == 2) {
            while (1) {
                char title[101];
                if (!prompt_str("Enter task title: ", title, sizeof(title))) {
                    fprintf(stderr, "Maximum title length: 100 characters\n");
                    continue;
                }

                if (strlen(title) == 0) {
                    fprintf(stderr, "Title cannot be empty.\n");
                    continue;
                }

                printf("title: %s\n", title);
                printf("len: %lu\n", strlen(title));
                break;
            }
        }

        printf("\n");

    }

    return 0;
}

