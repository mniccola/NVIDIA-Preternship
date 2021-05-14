# G++ is for the GCC compiler for C++
PP := g++

FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj


#make initialize
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)
# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*


# Command make job_test
$(OBJ)/job_test.o: $(SRC)/job_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/job_test.cpp -o $@

$(OBJ)/Job.o: $(SRC)/Job.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Job.cpp -o $@

job_testObjs := $(OBJ)/job_test.o $(OBJ)/Job.o

job_test: $(job_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/job_test $(job_testObjs)


# Comp objects
$(OBJ)/Comp.o: $(SRC)/Comp.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Comp.cpp -o $@

# Command make stats_test
$(OBJ)/analysis.o: $(SRC)/analysis.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/analysis.cpp -o $@

$(OBJ)/stats_test.o: $(SRC)/stats_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/stats_test.cpp -o $@

stats_testObjs := $(OBJ)/stats_test.o $(OBJ)/analysis.o $(OBJ)/Job.o

stats_test: $(stats_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/stats_test $(stats_testObjs)

# Command make main
$(OBJ)/main.o: $(SRC)/main.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/mainFunc.o: $(SRC)/mainFunc.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/mainFunc.cpp -o $@

mainObjs := $(OBJ)/main.o $(OBJ)/Job.o $(OBJ)/mainFunc.o $(OBJ)/Comp.o $(OBJ)/analysis.o

main: $(mainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/main $(mainObjs)
