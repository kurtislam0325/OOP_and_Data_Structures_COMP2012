CPPFLAGS = -std=c++11
SRCS = main.cpp risk_WTH.cpp risk_BMI.cpp risk_BFP.cpp
OBJS = main.o
DEPS = $(SRCS:.cpp=.d)
TARG = HealthCheck_BFP HealthCheck_BMI HealthCheck_WTH

all: $(TARG)

# HealthCheck_WTH: $(OBJS) risk_WTH.o
# 	g++ -o $@ $(CPPFLAGS) $^

# HealthCheck_BMI: $(OBJS) risk_BMI.o
# 	g++ -o $@ $(CPPFLAGS) $^

# HealthCheck_BFP: $(OBJS) risk_BFP.o
# 	g++ -o $@ $(CPPFLAGS) $^

HealthCheck_%: $(OBJS) risk_%.o
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	rm -f *.o *.d $(TARG)

.PRECIOUS: $(OBJS) risk_WTH.o risk_BMI.o risk_BFP.o