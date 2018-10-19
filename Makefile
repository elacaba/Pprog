PROGRAM_HOME=..

#
# Change this to wherever you want to install the program.
#
INSTALL_DIR=$(PROGRAM_HOME)/install


SOURCE_DIR=$(PROGRAM_HOME)/development/src
MINIGAME_DIR=$(SOURCE_DIR)/minigames

LIBS=

#
# These are some things about the compiler
#
CC=gcc -c -std=c99
LN=gcc

CFLAGS= -I$(SOURCE_DIR)  -I$(MINIGAME_DIR) 

OBJFILES=tests1.o mini.o

LFLAGS=

#
# Object files
#
mini.o:	$(MINIGAME_DIR)/mini.c $(MINIGAME_DIR)/mini.h 
	$(CC) $(CFLAGS) $(MINIGAME_DIR)/mini.c


tests1.o:	$(SOURCE_DIR)/tests1.c 
	$(CC) $(CFLAGS) $(SOURCE_DIR)/tests1.c

#
# Executables
#
tests1: $(OBJFILES)
	$(LN) -o ./tests1 $(LFLAGS) $(OBJFILES) $(LIBS)
