CC = gcc
FLAGS = -Wextra -Werror -Wall -std=c11 -pedantic
TEST_LIBS = -lcheck -lm

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
add_flag:
	$(eval TEST_LIBS += -lsubunit)
endif
ifeq ($(UNAME_S),Darwin)
add_flag:
	$(eval TEST_LIBS += -lpthread)
endif


all: s21_matrix.a test

build: all


s21_matrix.a: $(OBJECTS)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a
	
test: fix s21_matrix.a add_flag 
	$(CC) $(FLAGS) -g test/*.c *.c  s21_matrix.a $(TEST_LIBS) -o s21_test
	./s21_test

gcov_flag:
	$(eval FLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p report
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcno *.gcda *.gcov
	open report/index.html

fix:
	@clang-format -i *[ch]
	@clang-format -i test/*.c test/*.h

rebuild: clean build
	
clean:
	@rm -rf s21_test *.o *.a *.gcno *.gcda *.gcov *.info report *.dSYM *.a s21_matrix




#  valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 
