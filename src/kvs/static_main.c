//static_main.c
#include "kvs.h"

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	FILE* query_fp = fopen("query.dat", "r");
	FILE* answer_fp = fopen("answer.dat", "w");
	
    if (!query_fp || !answer_fp) {
        printf("파일 열기 실패\n");
        return -1;
    }

	char type[4];
	char key[100];
	char value[100];

	if(!feof(query_fp)) ////%s\n으로 저장 시 엔터가 마지막 줄에 들어가서 첫 줄은 %s로 다음줄부터 \n%s로 저장하는 방식으로 변경
	{
		fscanf(query_fp, "%3[^,],%99[^,],%99[^\n]\n", type, key, value);
		
		if (strcmp(type, "set") == 0) //type이 set이면 set을 호출
			set(kvs, key, value);
		else if (strcmp(type, "get") == 0) //type이 get이면 get을 호출
			fprintf(answer_fp, "%s", get(kvs, key));
	}

	while(!feof(query_fp)) {
		fscanf(query_fp, "%3[^,],%99[^,],%99[^\n]\n", type, key, value);
		
		if (strcmp(type, "set") == 0)
			set(kvs, key, value);
		else if (strcmp(type, "get") == 0)
			fprintf(answer_fp, "\n%s", get(kvs, key));
	}

	fclose(query_fp);
    fclose(answer_fp);
	close(kvs);
	
	return 0;
}