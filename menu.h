#ifndef MENU_H
#define MENU_H

typedef struct {
    short number;
    char* title;
} Menu;

void print_menu(Menu menu[], int len);
int select_menu();

#endif
