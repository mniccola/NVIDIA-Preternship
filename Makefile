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





