# Generic Makes Files for Compiling Simple Projects
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects
#
#This is Jason! Just stopping by and saying HI!

.PHONY = all run clean
CC = g++
CCFLAG = -Wall -Werror -std=c++11
ODIR = Build
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: ${OBJS}
	@echo "Compiling..."
	${CC} ${CCFLAG} ${wildcard ${ODIR}/*.o} -o ${ODIR}/bin

%.o: %.cpp
	@echo "Creating objects..."
	${CC} -c $< -o "${ODIR}/$@"

run:
	@echo "Running Executable..."
	./${ODIR}/bin

clean:
	@echo "Cleaning up..."
	rm -r ${wildcard ${ODIR}/*.o} ./${ODIR}/bin
