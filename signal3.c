#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <strings.h>

// 信号接收者程序receiver2.c
void func(int sig, siginfo_t *info, void *arg)
{
    // sig 是触发本函数的信号值
    printf("nihao\n");
}
int main()
{
    struct sigaction act;
//  bzero(&act,sizeof(act));
	sigemptyset(&act.sa_mask);

    // 指定函数响应函数
    act.sa_sigaction = func;
    act.sa_flags |= SA_SIGINFO;

    sigaction(SIGINT, &act, NULL);
    pause();
}

