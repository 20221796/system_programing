//static_main.c
#include "kvs.h"


node_t* last_node = NULL;

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// workload execution  
	
	// 1) 	file read 
	// 2) 	if set, insert (key, value) into kvs.
	// 		if get, seach the key in kvs and return the value. 
	//		Return -1 if the key is not found  

	FILE* query_fp = fopen("query.dat", "r");
	FILE* answer_fp = fopen("answer.dat", "w");
	
    if (!query_fp || !answer_fp) {
        printf("파일 열기 실패\n");
        return -1;
    }

	char type[4];
	char key[100];
	char value[100];

	if(!feof(query_fp)) //for first time
	{
		fscanf(query_fp, "%3[^,],%99[^,],%99[^\n]\n", type, key, value);
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
