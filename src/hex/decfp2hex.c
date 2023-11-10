#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char* pointer;

bool is64bit() {
    return sizeof(void*) == 8; //void 포인터 크기가 64비트인지 32비트인지 판별
}

bool isBigEndian() {
    int a = 0x01234567;
    if (*((char*)&a) == 0x01) //0x01234567의 메모리 첫 번째 값이 01이면 be 67이면 le
        return true; //big endian
    else
        return false; //little endian
}

void be_show_bytes(double a) {
    pointer ptr = (pointer)&a; //a의 메모리 주소를 char 포인터로 변환
    for (int i = 0; i < sizeof(double); i++) { //be이므로 낮은 자리부터 읽어옴
        unsigned char byte = ptr[i];
        //char 포인터이므로 1바이트씩 접근할 수 있음
        printf("%c%c", "0123456789ABCDEF"[byte / 16], "0123456789ABCDEF"[byte % 16]);
        //1바이트씩 2자리 16진수로 변환
    }
    printf("\n");
}

void le_show_bytes(double a) {
    pointer ptr = (pointer)&a; //le_show_bytes와 동일
    for (int i = sizeof(double) - 1; i >= 0; i--) { //le이므로 큰 자리부터 읽어옴
        unsigned char byte = ptr[i];
        printf("%c%c", "0123456789ABCDEF"[byte / 16], "0123456789ABCDEF"[byte % 16]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out number\n");
        exit(0);
    }

    double a = atof(argv[1]);

    printf("ARCH=%d\n", is64bit() ? 64 : 32);
    printf("ORDERING=%s\n", isBigEndian() ? "BIG_ENDIAN" : "LITTLE_ENDIAN");

    printf("MYANS: DEC=%g HEX=", a);
    isBigEndian() ? be_show_bytes(a) : le_show_bytes(a);
    return 0;
}