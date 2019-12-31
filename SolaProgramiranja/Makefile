#################################################################
## This Makefile Exported by MinGW Developer Studio
## Copyright (c) 2002-2004 by Parinya Thipchart
#################################################################

ifneq (,$(findstring Release, $(CFG)))
  override CFG = Release
else
  override CFG = Debug
endif

PROJECT = SolaProgramiranja
CC = "C:\Program Files (x86)\MinGWStudio\MinGW\bin\g++.exe"

ifeq ($(CFG),Debug)
  OBJ_DIR = Debug
  OUTPUT_DIR = Debug
  TARGET = SolaProgramiranja.exe
  C_INCLUDE_DIRS = 
  C_PREPROC = 
  CFLAGS = -pipe  -Wall -g2 -O0 -frtti -fexceptions 
  RC_INCLUDE_DIRS = 
  RC_PREPROC = 
  RCFLAGS = 
  LIB_DIRS = 
  LIBS = -lws2_32 
  LDFLAGS = -pipe 
endif

ifeq ($(CFG),Release)
  OBJ_DIR = Release
  OUTPUT_DIR = Release
  TARGET = SolaProgramiranja.exe
  C_INCLUDE_DIRS = 
  C_PREPROC = 
  CFLAGS = -pipe  -Wall -g0 -O2 -frtti -fexceptions 
  RC_INCLUDE_DIRS = 
  RC_PREPROC = 
  RCFLAGS = 
  LIB_DIRS = 
  LIBS = 
  LDFLAGS = -pipe -s 
endif

ifeq ($(OS),Windows_NT)
  NULL =
else
  NULL = nul
endif

SRC_OBJS = \
  $(OBJ_DIR)/Program.o	\
  $(OBJ_DIR)/ClientSocket.o

define build_target
@echo Linking...
@$(CC) -o "$(OUTPUT_DIR)\$(TARGET)" $(SRC_OBJS) $(LIB_DIRS) $(LIBS) $(LDFLAGS)
endef

define compile_source
@echo Compiling $<
@$(CC) $(CFLAGS) $(C_PREPROC) $(C_INCLUDE_DIRS) -c "$<" -o "$@"
endef

.PHONY: print_header directories

$(TARGET): print_header directories $(SRC_OBJS)
	$(build_target)

.PHONY: clean cleanall

cleanall:
	@echo Deleting intermediate files for 'SolaProgramiranja - $(CFG)'
	-@del $(OBJ_DIR)\*.o
	-@del "$(OUTPUT_DIR)\$(TARGET)"
	-@rmdir "$(OUTPUT_DIR)"

clean:
	@echo Deleting intermediate files for 'SolaProgramiranja - $(CFG)'
	-@del $(OBJ_DIR)\*.o

print_header:
	@echo ----------Configuration: SolaProgramiranja - $(CFG)----------

directories:
	-@if not exist "$(OUTPUT_DIR)\$(NULL)" mkdir "$(OUTPUT_DIR)"
	-@if not exist "$(OBJ_DIR)\$(NULL)" mkdir "$(OBJ_DIR)"

$(OBJ_DIR)/Program.o: Program.c

	$(compile_source)

$(OBJ_DIR)/ClientSocket.o: ClientSocket.cpp

	$(compile_source)

