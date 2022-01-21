CXX = g++

CPPFLAGS = -I. -I../include
CXXFLAGS = -g
LDFLAGS = $(shell pkg-config --libs glew) -lglut

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main.exe

%.d: %.cpp
	$(CXX) -MM $(CPPFLAGS) $< > $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(TARGET) *.o *.d

debug:
	@echo $(LDFLAGS)

include $(SOURCES:.cpp=.d)
