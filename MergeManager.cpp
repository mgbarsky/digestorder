#include "MergeManager.h"

using namespace std;

//reads input parameters, allocates buffers
bool MergeManager::init(IndexConfig *cfg, InputReader *reader, short totalChunks)
{
	this->reader = reader;
	this->reader->setSentinel();
	
    this->totalChunks=totalChunks;
	
	
	//at this point we have all buffers allocated - memory did not fail 	
	return true;
}


bool MergeManager::mergeChunks()
{	
	return true;
}



