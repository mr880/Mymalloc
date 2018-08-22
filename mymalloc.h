#ifndef mymalloc_h
#define mymalloc_h
#define malloc(x) mymalloc(x, __FILE__, __LINE__ )
#define free(x) myfree(x, __FILE__, __LINE__ )
void* mymalloc(size_t size, char* file, size_t line);
void myfree(void* ptr, char* file, size_t line);
// void printblock();
//void gettimeofday(struct timeval * tv, struct timezone * tz);
#endif

