# ####################################################
# TLM memory with TLM interface (ArchC 2x compliant)
# ####################################################

TARGET=tlm_memory
INC_DIR := -I. -I$(ARCHC_PATH)/include/archc -I$(SYSTEMC)/include -I$(TLM_PATH) 

SRCS := tlm_memory.cpp
OBJS := $(SRCS:.cpp=.o)

CFLAGS := $(WAIT_TRANSPORT_FLAG) $(MEM_SIZE_DEFAULT)
#------------------------------------------------------
.SILENT:
#------------------------------------------------------
.SUFFIXES: .cc .cpp .o
#------------------------------------------------------
lib: all
	ar r lib$(TARGET).a $(OBJS)
#------------------------------------------------------
all: $(OBJS)
#------------------------------------------------------
clean:
	rm -f $(OBJS) *~ *.o *.a
#------------------------------------------------------
distclean: clean
#------------------------------------------------------
.cpp.o:
	$(CC) $(CFLAGS) $(INC_DIR) -c -g $<
#------------------------------------------------------
.cc.o:
	$(CC) $(CFLAGS) $(INC_DIR) -c -g $<
