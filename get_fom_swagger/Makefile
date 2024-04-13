CC = g++
LFLAGS = -lcurl
TARGET = get_api
SRCS = get_api.cpp
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(LFLAGS) -o $(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)