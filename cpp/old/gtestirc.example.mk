PROGRAM_NAME = gtest_fizzbuzz

CXX = g++
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++17
CXXFLAGS += -isystem $(GTEST_DIR)/include

GTEST_DIR = ./googletest/googletest
GTEST_LIB = libgtest.a

OBJECTS = main.o \
	SystemMain.o \
	Message.o \
	MessageQueue.o \
	Controller.o \
	BaseCapsule.o \
	FizzBuzzCapsule.o \
	CapsuleTestSuite.o

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS) $(GTEST_LIB)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(GTEST_LIB) -o $(PROGRAM_NAME)

%.o: /%.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(GTEST_LIB):
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv $(GTEST_LIB) gtest-all.o

test:
	./$(PROGRAM_NAME)

clean:
	rm -rf *.o

zap: clean
	rm -rf $(PROGRAM_NAME) *.a
