# The compiler
CXX = /usr/bin/g++
CXXFALGS = -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra \
    -Wconversion -Wold-style-cast \
    -Wctor-dtor-privacy -Woverloaded-virtual \
    -Wsign-promo

# Commented out
#-Wstrict-null-sentinel -Wnoexcept -Wzero-as-null-pointer-constant

# Commented out (not supported by gcc<5):
# Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

# The executable sources and target
#
INCLUDES = -I./Include
SRCS = Src/KingMaker.cpp \
    Src/Schedule.cpp \
    Src/Liege.cpp \
    Test/KingMakerTest.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = KingMaker

.PHONY: depend clean

all: $(MAIN)
	@echo KingMaker binary has been compiled

$(MAIN): $(OBJS)
	$(CXX) $(CXXFALGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CXXFALGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) Src/*.o Test/*.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
