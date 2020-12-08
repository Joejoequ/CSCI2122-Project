//
// Created by QuJunqiao on 2020/12/7.
//

#ifndef LAB10_LOCATION_H
#define LAB10_LOCATION_H

#include "array_list.h"
#include "stdbool.h"
typedef struct _Location {
    char *name;
    int level;
    double *attribute;
    ArrayList *diedhero;
    bool available;
} location;

location *location_generate(char *, int, double, double, double, double);

void location_print(void *);

int location_level_path(void *, void *);

int location_power_path(void *, void *);

int location_subtlety_path(void *, void *);

int location_strategy_path(void *, void *);

int location_charm_path(void *, void *);

#endif //LAB10_LOCATION_H
