CC = g++
CFLAGOPT = -O3 -Wall 
CFLAGS = -D_LARGEFILE_SOURCE
CFLAGS += -fno-exceptions
CFLAGS += -finline-functions
CFLAGS += -funroll-loops
CFLAGS += -fpermissive
CFLAGS += -pthread
CFLAGOFFSET = -D_FILE_OFFSET_BITS=64
LDFLAGS=-lz
MATHFLAG=-lm

# Source files
INDEX_SORT_CHUNKS=divsufsort.c Utils.cpp Alphabet.cpp DNAAlphabet.cpp InputReader.cpp DNAReader.cpp DNALineReader.cpp IndexConfig.cpp ChunkIndexer.cpp BitPrefix.cpp mainSortChunks.cpp
INDEX_FIND_ORDER=Utils.cpp Alphabet.cpp DNAAlphabet.cpp IndexConfig.cpp OrderCell.cpp MergeManager.cpp IndexManager.cpp 
INDEX_CREATE_SRC=divsufsort.c Utils.cpp Alphabet.cpp DNAAlphabet.cpp InputReader.cpp DNAReader.cpp DNALineReader.cpp IndexConfig.cpp ChunkIndexer.cpp buildSA.cpp OrderCell.cpp MergeManager.cpp IndexManager.cpp

# Binaries
all: sortchunks 

sortchunks: $(INDEX_SORT_CHUNKS)
	$(CC) $(CFLAGOPT) $(CFLAGOFFSET) $(CFLAGS) $^ -o $@ 
mergeorder: $(INDEX_FIND_ORDER)
	$(CC) $(CFLAGOPT) $(CFLAGOFFSET) $(CFLAGS) $^ -o $@ 
indexfull: $(INDEX_CREATE_SRC)
	$(CC) $(CFLAGOPT) $(CFLAGOFFSET) $(CFLAGS) $^ -o $@ 
clean:  
	rm sortchunks mergeorder indexfull 
