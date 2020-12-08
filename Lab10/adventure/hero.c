//
// Created by QuJunqiao on 2020/12/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "hero.h"

hero *hero_birth(char *name, char *class, double strength, double ability, double intelligence, double charisma) {
    hero *h = malloc(sizeof(hero));
    h->name = name;
    h->class = class;
    h->level = 1;
    h->attribute = malloc(sizeof(double ) * 4);
    h->attribute[0] = strength;
    h->attribute[1] = ability;
    h->attribute[2] = intelligence;
    h->attribute[3] = charisma;
    h->alive = true;
    h->primary_attribute = hero_find_primary(h);
    h->died_location = malloc(sizeof(location));
    return h;
}

void hero_levelup(hero *h) {
    h->level += 1;
    for (int i = 0; i < 4; i++) {
        if (i == h->primary_attribute) {
            h->attribute[i] += 0.35;
        } else {
            h->attribute[i] += 0.25;
        }
    }
}

void hero_print(hero *h) {
    if (h->alive) {
        printf("%s", h->name);
        printf("%s", h->class);
        printf("%d\n", h->level);
        printf("attribute:%lf\n", h->attribute[0]);
        printf("%lf\n", h->attribute[1]);
        printf("%lf\n", h->attribute[2]);
        printf("%lf\n", h->attribute[3]);
        printf("%d\n", h->primary_attribute);
    } else {
        printf("hero died");
        printf("died in: %s",h->died_location->name);
    }
}

int hero_find_primary(hero *h) {
    int max = 0;
    for (int i = 1; i < 4; i++) {
        if (h->attribute[i] > h->attribute[max]) {
            max = i;
        }
    }
    return max;
}

bool hero_challenge(hero *h, location *l) {
    if (h->alive) {
        bool success = false;
        for (int i = 0; i < 4; i++) {
            if (h->attribute[i] > l->attribute[i]) {
                success = true;
            }
        }
        if (success) {
            hero_levelup(h);
        } else {
            h->alive = false;
            h->died_location = l;
            alist_add(l->diedhero,h);
        }
        return success;
    }
}
