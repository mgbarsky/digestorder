#include "Alphabet.h"

Alphabet::Alphabet()
{
	for(int i=0;i<256;i++)
	{
		this->unifiedAlphabet[i]=0;
		this->alphabetToBinID[i]=-1; //no such bin
	}
}
