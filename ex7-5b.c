#include<stdlib.h>
#include<unistd.h>
main(argc, argv)
int argc;
char *argv[];
{
	int     rand();
	void    srand();

	srand((unsigned)getpid()); // ó�� ������ �߻��� ���μ����� ����

	sleep((rand() * 197 % 100) + 1); // ������ �߻����� �� �ð� ��ŭ ���
	return 1; //exit(1); // ���� ���¸� 1�� �Ͽ� ������ ���� ���� ��ȯ
}
