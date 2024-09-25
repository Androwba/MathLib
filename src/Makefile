CC                =      gcc
CFLAGS            =     -std=c11 -Wall -Wextra -Werror
LINUXFLAGS        =     -lsubunit -lrt -lpthread -lm -D_GNU_SOURCE
LIBS              =     -lcheck
GCFLAGS           =     -fprofile-arcs -ftest-coverage
FIND&CHECK        =      $(wildcard *.c *.h)
RM                =      rm -rf
LCOVTESTNAME      =    --test-name "test"
LCOVFILENAME      =    --output-file test.info
LCOVDIR           =    --capture --directory .
GENHTML-DIRECTORY =    --output-directory report test.info
UNITNAME          =      unit_test
ARCHIVER          =      ar
ARFLAGS           =      cr -s

OS = $(shell uname -s)
ifeq ($(OS), Darwin)
OPEN = open report/index.html
LEAKS = @CK_FORK=no leaks --atExit --
CHECK = cpp style leaks
else
OPEN = xdg-open report/index.html
LEAKS = CK_FORK=no valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s
CHECK = cpp style
endif

all: test

test: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) unit_test.c s21_math.a -o $(UNITNAME) $(LIBS)
else
	$(CC) $(CFLAGS) unit_test.c s21_math.a -o $(UNITNAME) $(LIBS) $(LINUXFLAGS)
endif
	./$(UNITNAME)

gcov_report: clean
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(GCFLAGS) unit_test.c s21_math.c -o $(UNITNAME) $(LIBS)
else
	$(CC) $(CFLAGS) $(GCFLAGS) unit_test.c s21_math.c -o $(UNITNAME) $(LIBS) $(LINUXFLAGS)
endif
	./$(UNITNAME)
	lcov $(LCOVTESTNAME) $(LCOVDIR) $(LCOVFILENAME)
	genhtml $(GENHTML-DIRECTORY)
	@$(OPEN)

s21_math.a: clean
	$(CC) -c s21_math.c
	$(ARCHIVER) $(ARFLAGS) s21_math.a s21_math.o

check: $(CHECK)

cpp:
	@echo "\033[92m◄----------------------- CPP ------------------------------►\033[0m"
	@cppcheck --enable=all --suppress=missingIncludeSystem $(FIND&CHECK)

style:	
	@echo "\033[96m◄----------------------- Style Test -----------------------►\033[0m"
	@cp ../materials/linters/CPPLINT.cfg .
	@python3 ../materials/linters/cpplint.py --extensions=c $(FIND&CHECK)
	
leaks:
	@echo "\033[92m◄----------------------- Leaks ----------------------------►\033[0m"
	$(LEAKS) ./$(UNITNAME)

.PHONY: clean
clean:
	$(RM) *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.txt
	$(RM) $(UNITNAME)
	$(RM) report
	@$(RM) a.out
	@$(RM) CPPLINT.cfg


.PHONY: rebuild 
rebuild:
	$(MAKE) clean
	$(MAKE) all 
 
