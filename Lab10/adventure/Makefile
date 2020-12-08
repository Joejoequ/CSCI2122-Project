#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

all:level power strategy subtlety charm

charm: charm_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o charm_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o charm -lpthread

subtlety: subtlety_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o subtlety_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o subtlety -lpthread

strategy: strategy_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o strategy_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o strategy -lpthread

power: power_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o power_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o power -lpthread

level: level_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o level_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o level -lpthread



level_path.o: level_path.c
	$(COMPILER) $(CSTD) -c level_path.c

power_path.o: power_path.c
	$(COMPILER) $(CSTD) -c power_path.c

strategy_path.o: strategy_path.c
	$(COMPILER) $(CSTD) -c strategy_path.c

subtlety_path.o: subtlety_path.c
	$(COMPILER) $(CSTD) -c subtlety_path.c

charm_path: charm_path.c
	$(COMPILER) $(CSTD) -c charm_path.c



array_list.o: array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c 

queue.o: queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c

linked_list.o: linked_list.c linked_list.h
	$(COMPILER) $(CSTD) -c linked_list.c

threads.o: threads.c threads.h
	$(COMPILER) $(CSTD) -c threads.c

heap.o: heap.c heap.h
	$(COMPILER) $(CSTD) -c heap.c

hero.o: hero.c hero.h
	$(COMPILER) $(CSTD) -c hero.c

location.o: location.c location.h
	$(COMPILER) $(CSTD) -c location.c

# Clean  rule.
clean:
	rm -f *.o charm level power strategy subtlety level_dead level_alive power_alive power_dead strategy_alive strategy_dead subtlety_alive subtlety_dead charm_alive charm_dead