OBJS = DE1SoCfpga.o SevenSegment.o LEDControl.o main.o

main: $(OBJS)
	g++ -o main $(OBJS)

%o: %.cpp %.h
	g++ -c $<

.PHONY: clean

clean:
	rm -f *.o
