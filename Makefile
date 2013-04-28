CXX := $(CROSS)gcc
CCFLAGS = -Wall -g
MAIN_O = log.o main.o
Main:$(MAIN_O)
  $(CXX) $(CCFLAGS) -o main $(MAIN_O)
main.o:main.c 
	$(CXX) $(CCFLAGS) -c main.c 
log.o:log.c 
	$(CXX) $(CCFLAGS) -c log.c 
clean:
	rm -rf $(MAIN_O) main
test:
	valgrind  --leak-check=full --show-reachable=yes ./main


