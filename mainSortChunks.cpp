#include "IndexConfig.h"
#include "DNALineReader.h"
#include "ChunkIndexer.h"

int main(int argc, char *argv[])
{
	//loads configuration values
	IndexConfig cfg  (argv[1]);
    cfg.load();
    
    DNALineReader reader;
    ChunkIndexer chunkIndexer;

    if(!chunkIndexer.init(&cfg, &reader))
		return false;

	if(!chunkIndexer.indexChunks())
		return false;
	
	int longestLine = (int) chunkIndexer.getLongestInputLine();
	printf("Longest input line is of size %d\n",longestLine);

    int totalChunks = (int) chunkIndexer.getTotalChunks();
    printf("Total %d chunks\n",totalChunks);
	
	
	return 0;
}
