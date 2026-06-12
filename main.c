#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
    const char *menu = 
        "===== TASK MANAGER =====\n"
        "1. View Tasks\n"
        "2. Add Task\n"
        "3. Complete Task\n"
        "4. Edit Task\n"
        "5. Delete Task\n"
        "6. Save Tasks\n"
        "7. Exit\n";

    while(TRUE)
    {
        char mode;

        printf("%s\n", menu);
        printf("Choose an option: ");

        scanf(" %c", &mode);

        printf("the selected option: %c\n\n", mode);
    }

}

