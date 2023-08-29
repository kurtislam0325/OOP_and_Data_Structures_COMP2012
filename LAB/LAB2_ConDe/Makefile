CPPFLAGS = -std=c++11
SRCS = main.cpp Point.cpp PointSet.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: lab2

lab2: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:; /bin/rm *.exe *.o *.d