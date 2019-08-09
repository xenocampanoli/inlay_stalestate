# Custom Makefile for Preprocessor Generic Sort Algorithm Exercises.

DEBUG = -g
#DEBUG =
# I got the following gtest macros, and other make help from an 'osund' on OFTC IRC:
CXX = g++
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++17
CXXFLAGS += -isystem $(GTEST_DIR)/include

GTEST_DIR = ./googletest/googletest
GTEST_LIB = ./googletest/googlemock/gtest/libgtest.a
JSON_LIB = /usr/lib/x86_64-linux-gnu/libjsoncpp.a


#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# This presumes an Ubuntu or similar install of criterion and gtest where
# the header file installs are under /usr/include.

SOURCENAMES = batch bioseer glomsets subject subjectseer templates tools4json

HEADERS = $(patsubst %,%.hpp,$(SIMPLECLASSNAMES)) env.hpp

CLASSOFILES = $(patsubst %,%.o,$(SIMPLECLASSNAMES))

CLASSGTESTS = $(patsubst %,%GTests,$(CGTCLASSNAMES))

CLASSGTESTSOFILES = $(patsubst %,%.o,$(CLASSGTESTS))

$(CLASSOFILES): %.o: %.cpp $(HEADERS)
	$(CXX) $(DEBUG) -c $(CXXFLAGS) $< -o $@

$(CLASSGTESTOFILES): %.o: %.cpp $(HEADERS)
	$(CXX) $(DEBUG) -c $(CXXFLAGS) $< -o $@

batchGTests: batchGTests.o batch.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

bioseerGTests: bioseerGTests.o bioseer.o subjectseer.o tools4json.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

glomsetsGTests: glomsetsGTests.o glomsets.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

subjectGTests: subjectGTests.o subject.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

subjectseerGTests: subjectseerGTests.o bioseer.o subjectseer.o tools4json.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

templatesGTests: templatesGTests.o templates.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

tools4jsonGTests: tools4jsonGTests.o tools4json.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIB) $(JSON_LIB)

renderPE.o: renderPE.cpp $(HEADERS)
	$(CXX) $(DEBUG) -c $(CXXFLAGS) $< -o $@

renderPE: $(CLASSOFILES) renderPE.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(JSON_LIB)

alltests:  $(CLASSGTESTS)

#all:  renderBook renderPE renderTract alltests
all:  renderPE alltests

clean:
	-rm -f mess*
	-rm -f *.o
	-rm -f resinate $(CLASSGTESTS)
