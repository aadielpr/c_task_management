#include <stdio.h>
#include <string.h>
#include "scan.h"

// TODO: handling input buffer overflow
int prompt_int(char *prompt, int len, int *out) {
    printf("%s", prompt);

    char line[len];

    if (!fgets(line, sizeof(line), stdin)) {
        return 0;
    }

    if (line[0] == ' ' || line[0] == '\n' || line[0] == '\t') {
        return 0;
    }

    if (!sscanf(line, "%d", out)) {
        return 0;
    }

    return 1;
}

int prompt_str(char *prompt, char *out, size_t out_size) {
    printf("%s", prompt);

    out[0] = '\0'; // clearing the output first.

    if (!fgets(out, out_size, stdin)) return 0;

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
