
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

SHELL = /bin/bash

TIMEOUT_SIGNAL = 124
TIMEOUT_STRING = \033[1;35mtimeout\033[0;38m

POINTS_A = \033[1;32m1.0\033[0;38m
POINTS_B = \033[1;36m0.2\033[0;38m
POINTS_0 = \033[1;31m0.0\033[0;38m

${name} : ${name}.c
	@echo "=== COMPILING: ==="
	${CC} ${CFLAGS} -o $@ $< ${LIBS}

test : ${name}
	@echo "=== TESTING: ==="; \
	singleTestFile=$$(ls -1 test*.in | head -1); \
	\
	testNumberLength=$$(( $${#singleTestFile} - 7 )); \
	cutParameter=$$((5 + testNumberLength - 1)); \
	nTests=$$(ls -1 test*.in | cut -c5-$$cutParameter | sort | tail -1); \
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
	nPoints=0.0; \
	for i0 in $$(seq $$firstTest $$lastTest); do \
		i=$$(printf %0$${testNumberLength}d $$i0); \
		startTime=$$(date +%s.%N); \
		timeout -k $${hardTimeoutValue} $${timeoutValue} ./${name} < test$$i.in > test$$i.res 2> /dev/null; \
		result=$$?; \
		endTime=$$(date +%s.%N); \
		if [[ $$result == ${TIMEOUT_SIGNAL} ]]; then \
			if [[ ${M} == 1 ]]; then \
				echo -e "test$$i -- ${TIMEOUT_STRING}  [> $${timeoutValue} s]"; \
			else \
				echo -e "test$$i -- ${TIMEOUT_STRING}"; \
			fi; \
		else \
			timeDifference=$$(echo "scale=2; ($${endTime} - $${startTime}) / 1.00" | bc); \
			measuredTimeString=""; \
			if [[ ${M} == 1 ]]; then \
				measuredTimeString=" [$$timeDifference s]"; \
			fi; \
			cmp test$$i.res test$$i.out > /dev/null 2> /dev/null; \
			r=$$?; \
			if [[ $$r == 0 ]]; then \
				echo -e "test$$i -- ${POINTS_A} $${measuredTimeString}"; \
				nPoints=$$(echo $$nPoints + 1.0 | bc); \
			else \
				head -1 test$$i.res > __tmp_1__.txt; \
				head -1 test$$i.out > __tmp_2__.txt; \
				cmp __tmp_1__.txt __tmp_2__.txt > /dev/null 2> /dev/null; \
				r=$$?; \
				if [[ $$r == 0 ]]; then \
					echo -e "test$$i -- ${POINTS_B} $${measuredTimeString}"; \
					nPoints=$$(echo $$nPoints + 0.2 | bc); \
				else \
					echo -e "test$$i -- ${POINTS_0} $${measuredTimeString}"; \
				fi; \
				rm __tmp_1__.txt __tmp_2__.txt; \
			fi; \
		fi; \
		nConsideredTests=$$((nConsideredTests + 1)); \
	done; \
	echo "Result: $$nPoints / $$nConsideredTests"

clean :
	rm -fr ${name} test*.res test*.diff
