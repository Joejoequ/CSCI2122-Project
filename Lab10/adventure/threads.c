//
// Created by Qu Junqiao on 2020/12/8.
//
#include <pthread.h>
#include "threads.h"
#include "semaphore.h"

void* challenge(void* args){
    sem_t wait_here;
    sem_init(&wait_here,0,1);
Operation * arg=args;
if (arg->l->available){
    sem_wait(&wait_here);
    arg->l->available=false;
}
    if (arg->h->alive) {
        bool success = false;
        for (int i = 0; i < 4; i++) {
            if (arg->h->attribute[i] > arg->l->attribute[i]) {
                success = true;
            }
        }
        if (success) {
            hero_levelup(arg->h);
        } else {
            arg->h->alive = false;
            arg->h->died_location = arg->l;
            alist_add(arg->l->diedhero,arg->h);
        }
    }
    sem_post(&wait_here);
    arg->l->available=true;
}