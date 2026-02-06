CC = gcc

OBJS = main.o GraphImplementation.o List.o PQImplementation.o
PROGRAM = main

$(PROGRAM) : $(OBJS)
	$(CC)  $(OBJS) -o $(PROGRAM)

run:$(PROGRAM)
	./$(PROGRAM) 

clean:
	rm -f $(OBJS) $(PROGRAM)