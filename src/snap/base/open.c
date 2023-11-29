//open.c
#include "kvs.h"
#include "profile.h"

kvs_t* open_kvs()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));

	if(kvs) {
		kvs->items = 0;

		printf("do_recovery\n");
		//시간 측정
		gettimeofday(&start, NULL);
		do_recovery(kvs);
		gettimeofday(&end, NULL);
		
		double elapsed = (end.tv_sec - start.tv_sec) * 1000.0; // s to ms
		elapsed += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
		printf("Execution time: %.3f ms\n", elapsed);

		//메모리 사용량 측정
		getrusage(RUSAGE_SELF, &r_usage);
		printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
		printf("\n");
	}

	return kvs;
}