#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#define  NUMCHILD 20 // 자식 프로세스 개수 = 20
main(argc, argv)
int argc;
char *argv[];
{
	int child1, child2, fork();
	int i, pid, chpid[NUMCHILD], status, wait();
	//dddddddfdfdfdfdfdfdf

	for (i = 0; i < NUMCHILD; i++) { // 20회 반복
		if ((pid = fork()) == 0) // 자식 프로세스 생성 시 ( 자식프로세스 생성 시 0을 반환, 이때 pid는 0)
			execlp("ex7-5b", "ex7-5b", (char *)0); // 자식프로세스가 execlp 함수를 호출하여 ex7-5b 실행
		chpid[i] = pid; // 프로세스 ID를 chpid 배열에 저장
	}
	printf("parent: wating for children\n");
	// 자식 프로세스가 새 프로그램을 실행하므로 부모 프로세스는 자식 프로세스가 종료되길 기다려야 한다.
	while ((pid = wait(&status)) != -1) { // wait 함수를 호출하여 부모  프로세스가 자식 프로세스를 대기하는 동안 반복
		printf("child %d: terminated, status:%d\n", pid, status);
		if ((status >> 8) != 0) { // wait 함수가 자식 프로세스가 비정상적으로 종료한 상태 코드를 반환하나 경우
			for (i = 0; i < NUMCHILD; i++)
				kill(chpid[i], SIGTERM); // kill함수를 통해 모든 자식 프로세스에게 SIGTERM 신호를 송신하여 프로세스 종료 
		}
	}
	printf("parent: all children terminated\n"); // 자식 프로세스가 모두 종료되면 wait 호출을  실패하여 pid는 -1이 되므로 while문을 빠져 나와 최종 출력 
	return 0; //exit(0);
}
