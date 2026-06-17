#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scan.h"

// TODO: handling input buffer overflow
int prompt_int(char *prompt, int *out) {
    char buf[64];
    char *end;

    printf("%s", prompt);
    if (!fgets(buf, sizeof buf, stdin)) {
        return 0;
    }

    if (buf[0] == ' ' || buf[0] == '\n' || buf[0] == '\t') {
        return 0;
    }

    int i = strtol(buf, &end, 10); // returning 0 if its not a number

    if (i < INT_MIN || i > INT_MAX) {
        fprintf(stderr, "Number out of range.\n");
        exit(1);
    }

    *out = (int)i;

    return 1;
}

int prompt_str(char *prompt, char *out, size_t out_size) {
    printf("%s", prompt);

    out[0] = '\0'; // clearing the output first.

    if (!fgets(out, out_size, stdin)) {
        return 0;
    }

    for (int i = 0; out[i] != '\0'; i++) {
        if (out[i] == '\n') {
            out[i] = '\0';
            return 1;
        }
    }

    int ch;
    while((ch = getchar()) != '\n' && ch != EOF)
        ;

    return 1;
}
