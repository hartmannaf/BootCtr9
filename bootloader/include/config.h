#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ini.h"

typedef struct {
    char* section;
    char path[64];
    unsigned long long delay;
    unsigned long payload;
    unsigned long offset;
} configuration;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
int handler(void *user, const char *section, const char *name, const char *value);