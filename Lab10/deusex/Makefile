#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18



deusex: deusex_path.o threads.o array_list.o heap.o hero.o location.o array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o deusex_path.o linked_list.o queue.o threads.o hero.o location.o heap.o -o deusex -lpthread



deusex_path.o: deusex_path.c
	$(COMPILER) $(CSTD) -c deusex_path.c


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