#include "kvs.h"

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
	
	if(!query_fp) {
		printf("파일 열기 실패\n");
		return -1;
	}

	char type[4];
	char key[100];
	char value[100];

	while(!feop(query_fp)) {
		fscanf(query_fp, "%s,%s,%s\n",&type,&key,&value);
		
		if (type=="set")
			set(kvs, key, value);
		else if (type=="get")
			fprintf(answer_fp, "%s\n", get(kvs, key));
	}

	close(kvs);
	
	return 0;
}
