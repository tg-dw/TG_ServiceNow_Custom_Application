#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#define  NUMCHILD 20 // �ڽ� ���μ��� ���� = 20
main(argc, argv)
int argc;
char *argv[];
{
	int child1, child2, fork();
	int i, pid, chpid[NUMCHILD], status, wait();

	for (i = 0; i < NUMCHILD; i++) { // 20ȸ �ݺ�
		if ((pid = fork()) == 0) // �ڽ� ���μ��� ���� �� ( �ڽ����μ��� ���� �� 0�� ��ȯ, �̶� pid�� 0)
			execlp("ex7-5b", "ex7-5b", (char *)0); // �ڽ����μ����� execlp �Լ��� ȣ���Ͽ� ex7-5b ����
		chpid[i] = pid; // ���μ��� ID�� chpid �迭�� ����
	}
	printf("parent: wating for children\n");
	// �ڽ� ���μ����� �� ���α׷��� �����ϹǷ� �θ� ���μ����� �ڽ� ���μ����� ����Ǳ� ��ٷ��� �Ѵ�.
	while ((pid = wait(&status)) != -1) { // wait �Լ��� ȣ���Ͽ� �θ�  ���μ����� �ڽ� ���μ����� ����ϴ� ���� �ݺ�
		printf("child %d: terminated, status:%d\n", pid, status);
		if ((status >> 8) != 0) { // wait �Լ��� �ڽ� ���μ����� ������������ ������ ���� �ڵ带 ��ȯ�ϳ� ���
			for (i = 0; i < NUMCHILD; i++)
				kill(chpid[i], SIGTERM); // kill�Լ��� ���� ��� �ڽ� ���μ������� SIGTERM ��ȣ�� �۽��Ͽ� ���μ��� ���� 
		}
	}
	printf("parent: all children terminated\n"); // �ڽ� ���μ����� ��� ����Ǹ� wait ȣ����  �����Ͽ� pid�� -1�� �ǹǷ� while���� ���� ���� ���� ��� 
	return 0; //exit(0);
}
