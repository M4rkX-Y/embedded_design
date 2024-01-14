OBJS = BarGraph.o GradeGraph.o PassFailGraph.o main.o

main: $(OBJS)
	g++ -o main $(OBJS)

%o: %.cpp %.h
	g++ -c $<

.PHONY: clean

clean:
	rm -f $(OBJS)
