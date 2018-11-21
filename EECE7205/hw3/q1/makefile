CXX=g++
SRC=main.cc Deque.cc Integer.cc
OBJS=$(SRC:.cc=.o)
TARGET=main

start:$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) -o $@ -c $<

clean:
	rm -f $(OBJS) $(TARGET)
