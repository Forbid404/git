#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
	long mtype;
	char mtext[80];
};

int main(void)
{
	int msgid;
	msgid = msgget(ftok(".",1),IPC_CREAT|0666);

	struct message msg;
	bzero(&msg,sizeof(msg));

	msg.mtype = 1;
	fgets(msg.mtext,80,stdin);

	msgsnd(msgid,&msg,strlen(msg.mtext),0);
}
