CXX = g++
LDFLAGS = $(shell pkg-config --libs glew) -lglut
TARGET = main.exe

$(TARGET): main.cpp
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	rm -rf $(TARGET)

debug:
	@echo $(LDFLAGS)

