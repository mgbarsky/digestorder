#ifndef MERGEMANAGER_H
#define MERGEMANAGER_H

#include "ChunkIndexer.h"


class MergeManager
{
public:    
	MergeManager() 
	{
		this->lfTable=NULL;
		this->totalChunks=0;
		this->totalBins=0;
	}
	MergeManager(MergeManager& a) {}
	~ MergeManager()
	{
		
	}

	bool init(IndexConfig *cfg, InputReader *reader, short totalChunks);
	bool mergeChunks();

private:
	InputReader *reader;
	
	std::string dataDir;
	std::string tempDir;
	short totalChunks;   
		
	uint64 *lfTable;
	
};

#endif
