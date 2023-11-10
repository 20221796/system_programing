#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

//#define MAX_NUM 100000000
//#define MAX_NUM 10000
#define MAX_NUM 10000000
//#define MAX_NUM 1000000000
//#define MAX_NUM INT_MAX
//#define MAX_NUM 100000

struct vec {
	int len;
	int *data;
};
typedef struct vec vec_t;

// int get_vec_element(vec_t* v, int idx, int *val)
// {
// 	// assert(v); 조건이 아닌 값이 들어감, 불필요한 함수 제거

// 	// if(idx >= v->len)
// 	// 	return 0;
// 	//이미 반복문에서 인덱스가 길이보다 작게 설정 함

// 	*val = v->data[idx];
// 	return 1;
// }

int* get_vec_start(vec_t* v) {
	return v->data;
} //벡터의 시작 메모리를 반환하고 사용자가 element에 접근하도록 변경

int vec_length(vec_t* v)
{
	// assert(v);
	return v->len;
}

void combine(vec_t* v, int *dest)
{
	// assert(dest);
	
	// for(int i = 0; i < vec_length(v); i++){
	//지속적인 함수 호출대신 값으로 받아놓기
	int v_len = vec_length(v);

	int *data = get_vec_start(v); //벡터의 시작 메모리를 반환하고 사용자가 element에 접근하도록 변경

	// *dest = 0; 포인터 연산 제거
	int temp = 0;

	for(int i = 0; i < v_len; i+=2){
		// get_vec_element(v, i, &val);

		// *dest = *dest + val; 포인터 연산 제거
		// temp = temp + data[i]; //지역 변수 활용 연산으로 포인터 연산 대체
		temp = temp + (data[i]+data[i+1]); //+루프 언롤링까지
	}
	*dest = temp;
}

void init(vec_t* v)
{
	// assert(v);
	v->len = MAX_NUM;
	v->data = (int*) malloc(sizeof(int) * MAX_NUM);

	// init 
	for(int i = 0; i < MAX_NUM; i++)
		v->data[i] = i;
}

//assert: 에러 검출용 조건 확인 함수

int main()
{
	printf("This is the naive version .. \n");

	vec_t info; 
	int result; 
	// init 
	init(&info);

	// combine 
	combine(&info, &result);
	//printf("combined val = %d\n", result);

	return 0;
}