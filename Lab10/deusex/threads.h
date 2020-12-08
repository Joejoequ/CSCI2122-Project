//
// Created by QuJunqiao on 2020/12/8.
//

#ifndef LAB10_THREADS_H
#define LAB10_THREADS_H
#include "hero.h"
#include "location.h"
typedef struct _Operation{
    hero * h;
    location * l;
}Operation;
void* challenge(void*);
#endif //LAB10_THREADS_H
