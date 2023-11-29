//static_main.c
#include "kvs.h"
#include "profile.h"

int main()
{
	kvs_t* kvs = open_kvs();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	FILE* trace_fp = fopen("cluster004.trc", "r");

    if (!trace_fp) {
        printf("파일 열기 실패\n");
        return -1;
    }

	char type[4];
	char key[100];
	char value[10000];

	int recovery_cnt = kvs->items;

	for (int i=0; i<recovery_cnt; i++) {
	if(!feof(trace_fp))
		fscanf(trace_fp, "%[^,],%[^,],%[^\n]\n", type, key, value);
	else
		return 0; //전체에 대해 recovery가 진행된 경우 바로 종료
	}


	if(!feof(trace_fp)) ////%s\n으로 저장 시 엔터가 마지막 줄에 들어가서 첫 줄은 %s로 다음줄부터 \n%s로 저장하는 방식으로 변경
	{
		fscanf(trace_fp, "%[^,],%[^,],%[^\n]\n", type, key, value);
	
		if (set(kvs, key, value) == -1) 
			return -1;
	}

	while(!feof(trace_fp)) {
		fscanf(trace_fp, "%[^,],%[^,],%[^\n]\n", type, key, value);
		
		if (set(kvs, key, value) == -1) 
			return -1;
	}

	printf("do_sanpshot\n");
	//시간 측정
	gettimeofday(&start, NULL);
	do_snapshot(kvs);
	gettimeofday(&end, NULL);
	
	double elapsed = (end.tv_sec - start.tv_sec) * 1000.0; // s to ms
	elapsed += (end.tv_usec - start.tv_usec) / 1000.0; // us to ms
	printf("Execution time: %.3f ms\n", elapsed);

	//메모리 사용량 측정
	getrusage(RUSAGE_SELF, &r_usage);
	printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
	printf("\n");
	
	fclose(trace_fp);
	close_kvs(kvs);
	
	return 0;
}