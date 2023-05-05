CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
GCOV_FLAG = -fprofile-arcs -ftest-coverage -fPIC -O0
GCOV_FLAG_TEST = --coverage
TEST_FLAG = -lgtest
# LINUX_FLAG = -lm -lsubunit -lrt -lpthread
OPEN = open

# ifeq ($(shell uname), Linux)
# 	TEST_FLAG += $(LINUX_FLAG)
# endif

ifeq ($(shell uname), Linux)
	OPEN = xdg-open
endif

SOURCES_1 = s21_matrix_oop.cc
OBJECTS_1 = s21_matrix_oop.o
SOURCES_2 = test/test.cc
OBJECTS_2 = test.o

.PHONY: all
all: clean

s21_matrix_oop.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES_1)
	ar rc s21_matrix_oop.a $(OBJECTS_1)
	ranlib s21_matrix_oop.a
	-rm -rf *.o

test_s21_matrix_oop.a: clean
	$(CC) $(CFLAGS) $(GCOV_FLAG) -c $(SOURCES_1)
	ar rc s21_matrix_oop.a $(OBJECTS_1)
	ranlib s21_matrix_oop.a
	-rm -rf *.o

.PHONY: test
test: clean test_s21_matrix_oop.a
	$(CC) $(CFLAGS) -c $(SOURCES_2)
	$(CC) $(CFLAGS) $(GCOV_FLAG_TEST) -o tests $(OBJECTS_2) s21_matrix_oop.a $(TEST_FLAG)
	-rm -rf *.o
	./tests

.PHONY: gcov_report
gcov_report: clean test
	gcovr -r . --html-details -o report_calc.html
	$(OPEN) report_calc.html
	
.PHONY: clean
clean:
	-rm -rf *.o *.a *.out *.gcda *.gcno *.css *.html
	-rm -rf tests
	
.PHONY: style
style:
	clang-format -n -style=Google *.cc *.h test/*.cc

.PHONY: valgrind
valgrind:
	valgrind --leak-check=full -q  -s --track-origins=yes ./tests