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
            printf("\n===== TASKS =====\n");
            if (task_count == 0) {
                printf("Empty.\n");
                goto end_border;
            }

            for (size_t i = 0; i < task_count; i++) {
                Task task = tasks[i];
                printf("%d [%c] %s\n", task.ID, task.done ? 'X' : ' ', task.title);
            }
            
        end_border:
            printf("\n===== TASKS =====\n");
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

                printf("\nTask added successfully.\n");

                printf("%d. [ ] %s\n", task.ID, task.title);
                break;
            }
        } else if (select == 3) {
            int ID;
            if (!prompt_int("Enter task number to complete: ", &ID)) {
                fprintf(stderr, "Invalid input.\n");
                continue;
            }

            // TODO: findByID function
            int found = 0;
            for (size_t i = 0; i < task_count; i++) {
                if (tasks[i].ID == ID) {
                    tasks[i].done = 1;
                    found = 1;
                    printf("\nTask marked as completed.\n");
                    break;
                }
            }

            if (!found) {
                fprintf(stderr, "\nTask not found.\n");
            }

        } else if (select == 4) {
            while(1) {
                int ID;
                if (!prompt_int("Enter task number to edit: ", &ID)) {
                    fprintf(stderr, "Invalid input.\n");
                    continue;
                }

                // TODO: findByID function
                Task *task = NULL;
                for (size_t i = 0; i < task_count; i++) {
                    if (tasks[i].ID == ID) {
                        task = &tasks[i];
                        break;
                    }
                }

                if (task == NULL) {
                    fprintf(stderr, "\nTask not found.\n");
                    break;
                }

                printf("\nCurrent title: %s\n", task->title);
                if (!prompt_str("Enter new title: ", task->title, sizeof (task->title))) {
                    fprintf(stderr, "Invalid title format.\n");
                    continue;
                }
                printf("\nTask updated successfully.\n");
                break;
            }
        } else if (select == 5) {
            while(1) {
                // TODO: i think, just start loop from deleted index then left shift all the item ?
                int delete_ID;
                if (!prompt_int("Enter task number to delete: ", &delete_ID)) {
                    fprintf(stderr, "Invalid input.\n");
                    continue;
                }

                // TODO: findByID function
                Task *task = NULL;
                for (size_t i = 0; i < task_count; i++) {
                    if (tasks[i].ID == delete_ID) {
                        task = &tasks[i];
                        break;
                    }
                }

                if (task == NULL) {
                    fprintf(stderr, "\nTask not found.\n");
                    break;
                }

                int next_size = task_count - 1;
                Task *temp = NULL;
                if (next_size > 0) {
                    temp = malloc(next_size * sizeof (Task));
                    if (temp == NULL) {
                        fprintf(stderr, "Out of memory.\n");
                        exit(1);
                    }
                }

                ID = 1;
                for (size_t i = 0; i < task_count; i++) {
                    if (tasks[i].ID != delete_ID) {
                        Task task = { .ID = ID, .done = tasks[i].done };
                        strcpy(task.title, tasks[i].title);
                        temp[ID-1] = task;
                        ID++;
                    }
                }

                free(tasks);
                tasks = temp;
                task_count = next_size;
                break;
            }
        }

        printf("\n");
    }

    return 0;
}

