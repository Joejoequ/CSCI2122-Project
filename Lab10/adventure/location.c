//
// Created by QuJunqiao on 2020/12/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "location.h"
#include "hero.h"

location *location_generate(char *name, int level, double power, double subtlety, double strategy, double charm) {
    location *l = malloc(sizeof(location));
    l->name = name;
    l->level = level;
    l->attribute = malloc(4 * sizeof(double ));
    l->attribute[0] = power;
    l->attribute[1] = subtlety;
    l->attribute[2] = strategy;
    l->attribute[3] = charm;
    l->diedhero = alist_initialize(10, sizeof(hero), "hero");
     l->available=true;
    return l;
}

void location_print(void *ll) {
    location* l=(location*)ll;
    printf("%s", l->name);
    printf("%d\n", l->level);
    printf("location_attribute:%lf\n", l->attribute[0]);
    printf("%lf\n", l->attribute[1]);
    printf("%lf\n", l->attribute[2]);
    printf("%lf\n", l->attribute[3]);
}


int location_level_path(void *a, void*b) {
    location *loca = (location *) a;
    location *locb = (location *) b;

    return locb->level-loca->level;
}

int location_power_path(void* a, void* b) {
    location *loca = (location *) a;
    location *locb = (location *) b;
    double diff = locb->attribute[0] - loca->attribute[0];

    if (diff > 0) {
        return 1;
    } else if (diff == 0) {
        return 0;
    } else {
        return -1;
    }
}

int location_subtlety_path(void *a, void *b) {
    location *loca = (location *) a;
    location *locb = (location *) b;
    double diff = locb->attribute[1] - loca->attribute[1];

    if (diff > 0) {
        return 1;
    } else if (diff == 0) {
        return 0;
    } else {
        return -1;
    }
}

int location_strategy_path(void*a, void *b) {
    location *loca = (location *) a;
    location *locb = (location *) b;
    double diff = locb->attribute[2] - loca->attribute[2];

    if (diff > 0) {
        return 1;
    } else if (diff == 0) {
        return 0;
    } else {
        return -1;
    }
}

int location_charm_path(void *a, void *b) {
    location *loca = (location *) a;
    location *locb = (location *) b;
    double diff = locb->attribute[3] - loca->attribute[3];

    if (diff > 0) {
        return 1;
    } else if (diff == 0) {
        return 0;
    } else {
        return -1;
    }
}