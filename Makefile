CC=gcc
CFLAGS=-Wall -Wextra -Werror -c -std=c11
LDFLAGS=-lm
GDBFLAGS=#-g
SANFLAGS=-fsanitize=address -fno-omit-frame-pointer -fsanitize=leak
GCFLAGS=-fprofile-arcs -ftest-coverage
GLFLAGS=-lgcov --coverage
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
SLSOURCES=s21_insert.c s21_strerror.c s21_strrchr.c s21_trim.c s21_memchr.c s21_strcat.c s21_strlen.c s21_strspn.c s21_memcmp.c s21_strchr.c s21_strncat.c s21_strstr.c s21_memcpy.c s21_strcmp.c s21_strncmp.c s21_strtok.c s21_memmove.c s21_strcpy.c s21_strncpy.c s21_to_lower.c s21_memset.c s21_strcspn.c s21_strpbrk.c s21_to_upper.c s21_sprintf.c s21_sscanf.c
SLOBJECTS=$(SLSOURCES:.c=.o)
SLIBRARY=s21_string.a
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

#TESTSRC=SLSOURCES
#TESTOBJ=$(TESTSRC:.c=.o)

all: test

s21_string.a: clean $(SLOBJECTS)
	ar rc $(SLIBRARY) $(SLOBJECTS)
	ranlib $(SLIBRARY)
	
test: clean
	$(CC) $(CFLAGS) $(GCFLAGS) $(SLSOURCES) $(SOURCES) $(LDFLAGS)
	$(CC) $(OBJECTS) $(SLOBJECTS) $(CHECKFLAGS) -o test $(GLFLAGS) $(SANFLAGS)

$(OBJECTS):
	$(CC) $(CFLAGS) $(SOURCES) $(SANFLAGS) $(GDBFLAGS)

$(SLOBJECTS):
	$(CC) $(CFLAGS) $(SLSOURCES) $(SANFLAGS) $(GDBFLAGS)

gcov_report:
	gcov $(SOURCES) $(SLSOURCES)
	lcov --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory ./gcov_report

clean:
	rm -rf $(EXECUTABLE) *.a *.o *.gcov *.gcda *.gcno *.info ./gcov_report

rebuild: clean all

testlib: clean $(OBJECTS) $(SLIBRARY)
	mv $(SLIBRARY) libs21_string.a
	$(CC) $(OBJECTS) $(CHECKFLAGS) -L./ -ls21_string -o test $(SANFLAGS)
	mv libs21_string.a $(SLIBRARY)

sample: testlib
	mv $(SLIBRARY) libs21_string.a
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) $(SANFLAGS)
	$(CC) *.o $(CHECKFLAGS) -L./ -ls21_string -o $(EXECUTABLE) $(SANFLAGS)
	mv libs21_string.a $(SLIBRARY)
	./$(EXECUTABLE)

lintc:
	python3 ../materials/linters/cpplint.py --extensions=c *.c

linth: 
	python3 ../materials/linters/cpplint.py --extensions=c *.h

leaks:
	leaks -atExit -- ./$(EXECUTABLE)
	
valgrind:
	valgrind --leak-check=full --leak-resolution=high --undef-value-errors=yes -s ./$(EXECUTABLE)
