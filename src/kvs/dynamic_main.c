//dynamic_main.c
#include "kvs.h"
#include <dlfcn.h>

int main() {
	void* handle;
	char* error;
	
	handle = dlopen("./libkvs.so", RTLD_LAZY);
    if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    kvs_t* (*open)();
    void (*close)(kvs_t*);
    void (*set)(kvs_t*, const char*, const char*);
    const char* (*get)(kvs_t*, const char*);

    open = (kvs_t* (*)()) dlsym(handle, "open");
    close = (void (*)(kvs_t*)) dlsym(handle, "close");
    set = (void (*)(kvs_t*, const char*, const char*)) dlsym(handle, "set");
    get = (const char* (*)(kvs_t*, const char*)) dlsym(handle, "get");

	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

    kvs_t* kvs = open();



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
