CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c18 -O3 
LIBS=

INCLUDE_PATH=/usr/include
LIB_PATH=/usr/lib64


TARGET=liblog.a
OUTPUT=release

MODULES += log.o

TEST += test.o
TEST += log.o

all: env $(MODULES)
	ar -crs $(OUTPUT)/$(TARGET) $(MODULES)

%.o:
	$(CC) $(CFLAGS) -c $<


-include dep.list


exec: all
	$(OUTPUT)/$(TARGET)


test: env $(TEST)
	$(CC) $(CFLAGS) $(TEST) $(LIBS) -o $(OUTPUT)/test

	$(OUTPUT)/test


.PHONY: env dep clean install


dep:
	$(CC) -MM test/*.c src/*.c > dep.list


install:
	cp -v $(OUTPUT)/$(TARGET) $(LIB_PATH)/$(TARGET)
	cp -v src/log.h $(INCLUDE_PATH)/log.h


env:
	mkdir -pv $(OUTPUT)


clean: 
	rm -rvf $(OUTPUT)
	rm -vf ./*.o



