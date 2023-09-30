CC := gcc
CFLAGS := -ggdb -std=c++17 -Wall -Werror -Wextra -lstdc++ -g
TST_FLAGS := -lgtest -lgmock -pthread

all: rebuild

build:

rebuild: clean build

s21_vector.o: vector/s21_vector.cc vector
		@$(CC) -c vector/s21_vector.cc -o s21_vector.o $(C_LIBS) $(CFLAGS)

s21_queue.o: queue/s21_queue.cc queue
		@$(CC) -c queue/s21_queue.cc -o s21_queue.o $(C_LIBS) $(CFLAGS)

s21_list.o: list/s21_list.cc list
		@$(CC) -c list/s21_list.cc -o s21_list.o $(C_LIBS) $(CFLAGS)

s21_map.o: map/s21_map.cc map
		@$(CC) -c map/s21_map.cc -o s21_map.o $(C_LIBS) $(CFLAGS)

s21_test.o: s21_test.cc vector queue list map
		@$(CC) -c s21_test.cc -o s21_test.o $(CFLAGS)

test: s21_test
		@./s21_test

s21_test: clean s21_test.o s21_vector.o s21_queue.o s21_list.o s21_map.o
		@$(CC) s21_test.o -o s21_test $(CFLAGS) $(TST_FLAGS) -g

clean: clean_test
		@rm -rf ./*.o
		@rm -rf ./*.a
		@rm -rf ./s21_test

clean_test:
		@rm -rf *.gcda *.gcno *.info

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n list/* vector/* stack/* queue/* set/* map/*

leak:
	CK_FORK=no leaks -atExit -- ./s21_test