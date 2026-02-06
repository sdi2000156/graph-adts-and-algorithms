CC = gcc

OBJS = main.o SL.o 
PROGRAM = main

$(PROGRAM) : $(OBJS)
	$(CC)  $(OBJS) -o $(PROGRAM)

run:$(PROGRAM)
	./$(PROGRAM) 

clean:
	rm -f $(OBJS) $(PROGRAM)