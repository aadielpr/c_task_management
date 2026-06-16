#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scan.h"
#include "menu.h"

// TODO: seperate this
typedef struct {
    int ID;
    char title[101];
    int done;
} Task;

// TODO: i think, i need to create a custom print function
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

    int ID = 1;
    size_t task_count = 0;
    Task *tasks = NULL;

    while(1) {
        int menu_len = sizeof(menu_list) / sizeof(menu_list[0]);

        print_menu(menu_list, menu_len);

        int select = select_menu();
        if (!select) {
            fprintf(stderr, "Invalid option. Please choose a number from 1 to 7.\n\n");
            continue;
        }

        if (select == 1) {
            // TODO: create this into a function
            if (task_count == 0) {
                printf("No tasks found. Add a task first.\n\n");
                continue;
            }

            printf("===== TASKS =====\n\n");
            for (size_t i = 0; i < task_count; i++) {
                Task task = tasks[i];
                printf("%d [%c] %s\n", task.ID, task.done ? 'x' : ' ', task.title);
            }
        } else if (select == 2) {
            // TODO: create this into a function
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

                // TODO: can i make this into a function ?
                Task *temp = realloc(tasks, (task_count + 1) * sizeof(Task));
                if (temp == NULL) {
                    fprintf(stderr, "Out of memory.\n");
                    free(tasks);
                    exit(1);
                }

                Task task = { .ID = ID++, .done = 0 };
                strcpy(task.title, title);

                tasks = temp;
                tasks[task_count++] = task;

                printf("Task added successfully.\n");

                printf("%d. [%c] %s\n", task.ID, task.done ? 'x' : ' ', task.title);
                break;
            }
        }

        printf("\n");
    }

    return 0;
}

