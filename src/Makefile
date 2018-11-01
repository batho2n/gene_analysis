.SUFFIXES: .c.cpp.o

GCC				= gcc
GXX				= g++
AR				= ar
MKDIR			= mkdir -p
CD				= cd
CP				= cp -R
RM				= rm -rf
LN				= ln -f -s


CFLAGS			= -std=c++11 -Wall -I. -DTTS_DEBUG -DRAW_FEATURE -DUNIX -DLINUX -D_REENTRAN
#-----------------------------------------------------
# 빌드 아키텍춰를 지정한다
#-----------------------------------------------------
ARCH	:= $(shell uname -m)
ifeq ($(ARCH), x86_64)
	CFLAGS	+= -m64 -DUSE_INT64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
else
	CFLAGS	+= -m32 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
endif


#--------------------------------------------------------------
# 빌드환경이 리눅스인 경우 shared library를 빌드할 수 있도록
# -fPIC 옵션을 추가한다
#--------------------------------------------------------------
OS := $(shell uname -s)
ifeq ($(OS), Linux)
	CFLAGS		+= -fPIC -DTTS_LINUX
	LIBS		+= -lrt
	SAURUS_LIB	+= -lrt -ldl
endif

#-------------------------------------------------
# 디버그 옵션을 설정할 수 있도록 한다
#-------------------------------------------------
debug			= 0
ifeq ($(debug), 1)
	CFLAGS  += -g -O0 -Wall -DTTS_DEBUG
else ifeq ($(profile), 1)
	CFLAGS	+= -O3 -DTTS_TIME_CHECK
else
	CFLAGS	+= -O3 -DNDEBUG
endif


FUNC_OBJS           = common.o

GENE_TESTER_OBJS	= gene_tester.o
GENE_TESTER			= gene_tester.exe

OBJS                = $(GENE_TESTER_OBJS) $(FUNC_OBJS)
TESTERS			    = $(GENE_TESTER)

SUPPORT64		= -DUSE_INT64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
LIBS			= -lpthread -ldl -lm

install: $(TESTERS)

$(GENE_TESTER):$(OBJS)
	$(GXX) -o $(GENE_TESTER) $(OBJS) $(LIBS)

.c.o:
	$(GCC) $(INCS) $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(GXX) $(INCS) $(CFLAGS) -o $@ -c $<

	
clean:
	$(RM) $(OBJS)
	$(RM) $(TESTERS)
	$(RM) *.wav



.PHONY: all clean test; 

