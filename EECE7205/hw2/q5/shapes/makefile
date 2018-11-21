CXX=g++
SRC=main.cc Rectangle.cc shape.cc Square.cc
OBJS=$(SRC:.cc=.o)
TARGET=main

start:$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) -o $@ -c $<

clean:
	rm -f $(OBJS) $(TARGET)
