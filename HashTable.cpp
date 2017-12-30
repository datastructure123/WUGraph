#include"HashTable.h"
#include<assert.h>
Hash::Hash()
{
	divisor = 0;
	TableSize = 0;
}
Verhash::Verhash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new VerNode*[sz];
	assert(ht != NULL);
}
Edghash::Edghash(int d, int sz)
{
	divisor = d;
	TableSize = sz;
	ht = new EdgNode*[sz];
	assert(ht != NULL);
}
int Hash::key(int num)
{

}