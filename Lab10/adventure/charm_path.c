#include <stdio.h>
#include <stdlib.h>
#include "hero.h"
#include "location.h"
#include "array_list.h"
#include "semaphore.h"
#include "heap.h"
#include "threads.h"
#include "queue.h"
#include "pthread.h"
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen("heroes.lot", "r");
    ArrayList *heroes = alist_initialize(301, sizeof(hero), "hero");

    for (int i = 0; i < 300; i++) {
        char *name = malloc(sizeof(char) * 40);
        char *class = malloc(sizeof(char) * 30);
        double S, A, I, C;
        fflush(fp);
        fgets(name, 40, fp);
        name=strtok(name, "\r\n");
        fgets(class, 20, fp);
        class=strtok(class, "\r\n");
        fscanf(fp, "%lf, %lf, %lf, %lf\n", &S, &A, &I, &C);

        hero *h = hero_birth(name, class, S, A, I, C);
        alist_add(heroes, h);
    }

    fp = fopen("locations.lot", "r");
    Heap *locations = heap_initialize(sizeof(location), "location", location_charm_path, location_print);
    for (int i = 0; i < 200; i++) {
        char *location_name = malloc(sizeof(char) * 40);
        int location_level;
        double LS, LA, LI, LC;
        fgets(location_name, 40, fp);
        location_name=strtok(location_name, "\r\n");
        fscanf(fp, "%d, %lf, %lf, %lf, %lf\n", &location_level, &LS, &LA, &LI, &LC);

        location *l = location_generate(location_name, location_level, LS, LA, LI, LC);
        heap_insert(locations, l);
    }
    fclose(fp);


    Queue *operation = queue_initialize(sizeof(Operation), "Operation");
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 300; j++) {

            Operation *oper = malloc(sizeof(Operation));
            oper->h = alist_get(heroes, j);

            oper->l = heap_peek(locations);
            queue_enqueue(operation, oper);
        }
        heap_remove(locations);
    }


    int poolsize=1;
    if (argv[1] != NULL) {
        poolsize = atoi(argv[1]);
    }

    pthread_t threads[poolsize];
    for (int i = 0; i < poolsize; i++) {

        pthread_create(&threads[i], NULL, challenge, queue_dequeue(operation));
        pthread_join(threads[i], NULL);
        if (queue_size(operation) == 0) {
            break;
        }

        if (i >= poolsize - 1) {
            i = 0;
        }
    }
    FILE *dead = fopen("charm_dead", "w");
    FILE *alive = fopen("charm_alive", "w");
    for (int i = 0; i < 300; i++) {
        hero *result = alist_get(heroes, i);
        if (result->alive) {
            fprintf(alive, "%s %s %.2lf %.2lf %.2lf %.2lf\n", result->name, result->class, result->attribute[0],
                    result->attribute[1], result->attribute[2], result->attribute[3]);
        }
        else{
            fprintf(dead, "%s %s %.2lf %.2lf %.2lf %.2lf %d %s\n", result->name, result->class, result->attribute[0],
                    result->attribute[1], result->attribute[2], result->attribute[3],result->primary_attribute,result->died_location->name);
        }
    }
    fclose(alive);
    fclose(dead);
    return 0;
}
