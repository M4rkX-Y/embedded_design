OBJS = Comparator.o CompMain.o main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

%.o: %.cpp
	g++ -g -c $<
 
.PHONY: clean

clean:
	rm -f *.o main.exe