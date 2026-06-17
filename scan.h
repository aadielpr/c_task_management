#ifndef SCAN_H
#define SCAN_H
#include <stddef.h>

int prompt_int(char *prompt, int *out);
int prompt_str(char *prompt, char *out, size_t out_size);

#endif
