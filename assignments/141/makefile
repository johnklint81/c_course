CC 			 = gcc
CFLAGS   = -Wall
LDFLAGS  = 
OBJFILES = convert.o main.o
TARGET   = convert

all : $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
