#include<stdlib.h>
#include<unistd.h>
main(argc, argv)
int argc;
char *argv[];
{
	int     rand();
	void    srand();
//test testㄲㄲㄲㄲ
	srand((unsigned)getpid()); // 처음 난수를 발생할 프로세스를 지정

	sleep((rand() * 197 % 100) + 1); // 난수를 발생시켜 그 시간 만큼 대기
	return 1; //exit(1); // 종료 상태를 1로 하여 비정상 종료 값을 반환
}
