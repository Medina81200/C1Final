#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Source files
ifeq ($(PLATFORM),MSP432)
	SOURCES = main.c \
		 memory.c \
		 interrupts_msp432p401r_gcc.c \
		 startup_msp432p401r_gcc.c \
		 system_msp432p401r.c

# MSP432 include paths
	INCLUDES =-I../include/common \
		 -I../include/CMSIS  \
		 -I../include/msp432
else
	SOURCES = memory.c \
	 	  main.c
	INCLUDES =-I../include/common
endif 

