//
// Created by QuJunqiao on 2020/12/7.
//

#ifndef LAB10_HERO_H
#define LAB10_HERO_H

#include <stdbool.h>
#include "location.h"

typedef struct _hero {
    char *name;
    char *class;
    int primary_attribute;
    int level;
    double *attribute;              //1 strength,2 ability,3 intelligence,4 charisma
    bool alive;
    location *died_location;

} hero;

hero *hero_birth(char *, char *, double, double, double, double);

void hero_levelup(hero *);

void hero_print(hero *);

bool hero_challenge(hero *, location *);

int hero_find_primary(hero *);

#endif //LAB10_HERO_H
