
# Before running make:
#     export name=<name_of_source_C_file>
#
# Compile:
#     make
#
# Test:
#     make test [optional parameters]
#
#     Optional parameters:
#         T: timeout value in seconds (default = 1)
#         M: print execution time for each test case (1: yes; 0: no; default = 0)
#         P: range of test cases to be considered (e.g., 3-5 or 7 or 2- or -6
#            or -; default = -)
#
#     Examples:
#         make test
#         make test P=4-7
#         make test T=3
#         make test T=2 M=1 P=6-

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall
LIBS = -lm

T = 1
M = 0
P = '-'

DIFF_TIMEOUT = 0.5

TIMEOUT_SIGNAL = 124
SHELL = /bin/bash
OK_STRING=\033[1;32mOK\033[0;38m
FAILED_STRING=\033[1;31mfailed\033[0;38m
TIMEOUT_STRING=\033[1;35mtimeout\033[0;38m

${name} : ${name}.c
	@echo "=== COMPILING: ==="
	${CC} ${CFLAGS} -o $@ $< ${LIBS}

test : ${name}
	@echo "=== TESTING: ==="; \
	singleTestFile=$$(ls -1 test*.out | head -1); \
	\
	testNumberLength=$$(( $${#singleTestFile} - 8 )); \
	cutParameter=$$((5 + testNumberLength - 1)); \
	nTests=$$(ls -1 test*.out | cut -c5-$$cutParameter | sort | tail -1); \
	firstTest=$$(echo $$P | cut -d'-' -f1); \
	lastTest=$$(echo $$P | cut -d'-' -f2); \
	if [[ -z $$firstTest ]]; then \
		firstTest=1; \
	fi; \
	if [[ -z $$lastTest ]]; then \
		lastTest=$$nTests; \
	fi; \
	\
	nPassedTests=0; \
	nConsideredTests=0; \
	\
	trap exit SIGINT; \
	\
	timeoutValue=${T}; \
	hardTimeoutValue=$$((timeoutValue + 2)); \
	\
	for i0 in $$(seq $$firstTest $$lastTest); do \
		i=$$(printf %0$${testNumberLength}d $$i0); \
		${CC} ${CFLAGS} -Dtest -o test$$i test$$i.c ${name}.c ${LIBS};\
		startTime=$$(date +%s.%N); \
		timeout -k $${hardTimeoutValue} $${timeoutValue} ./test$$i > test$$i.res 2> /dev/null; \
		result=$$?; \
		endTime=$$(date +%s.%N); \
		if [[ $$result == ${TIMEOUT_SIGNAL} ]]; then \
			if [[ ${M} = 1 ]]; then \
				echo -e "test$$i -- ${TIMEOUT_STRING}  [> $${timeoutValue} s]"; \
			else \
				echo -e "test$$i -- ${TIMEOUT_STRING}"; \
			fi; \
		else \
			timeDifference=$$(echo "scale=2; $${endTime} - $${startTime}" | bc | awk '{printf "%.2f\n", $$0}'); \
			measuredTimeString=""; \
			if [[ ${M} = 1 ]]; then \
				measuredTimeString=" [$$timeDifference s]"; \
			fi; \
			timeout -k ${DIFF_TIMEOUT} ${DIFF_TIMEOUT} diff --ignore-trailing-space test$$i.res test$$i.out > test$$i.diff; \
			result=$$?; \
			if [[ $$result == ${TIMEOUT_SIGNAL} ]]; then \
				cmp test$$i.res test$$i.out > test$$i.diff; \
				result=$$?; \
			fi; \
			if [[ $$result == 0 ]]; then \
				echo -e "test$$i -- ${OK_STRING} $${measuredTimeString}"; \
				nPassedTests=$$((nPassedTests + 1)); \
			else \
				echo -e "test$$i -- ${FAILED_STRING} $${measuredTimeString}"; \
			fi \
		fi; \
		nConsideredTests=$$((nConsideredTests + 1)); \
	done; \
	echo "Result: $$nPassedTests / $$nConsideredTests"

clean :
	rm -fr ${name} test?? test*.res test*.diff
