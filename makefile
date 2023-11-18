
CXX = g++

CXXFLAGS = -std=c++11 -Wall

TARGET = main.exe

SOURCES = Perceptron.cpp main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
