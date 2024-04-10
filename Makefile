# Makefile for GTK GUI Application

# Compiler
CC = g++

# Flags
CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LIBS = $(shell pkg-config --libs gtk+-3.0)

# Target executable
TARGET = gui_app

# Source file
SRCS = gui_app.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)