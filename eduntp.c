#include <stdio.h>

int main(int argc, char* argv[])
{
	//server, client, clearall
	system("sudo rm /etc/ntp.conf");
	FILE *fd = fopen("/etc/ntp.conf");
	if(strcmp(argv[1],"server"))
	{
		fprintf(fd,"%s %s\n",argv[1],argv[2]);
	}else
	if(strcmp(argv[1],"client"))
	{
		fprintf(fd,"%s %s\n","restrict",argv[2]);
	}else
	system("sudo rm /etc/ntp.conf");
	system("sudo systemctl restart ntp.service");
	fclose(fd);
	return 0;
}
