#include "memory.h"

LocalFileSystem local("local");
FILE *fp;

void Memory_Init()
{
    *fp=fopen("local/temp.txt","w");
}

void Memory_FinishWriting()
{
    fclose(fp);
}