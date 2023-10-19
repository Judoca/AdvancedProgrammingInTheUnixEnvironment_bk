#include	"apue.h"
#include	<dirent.h>

/*
void err_doit(

void err_sys(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1)
}
*/

int main (int argc, char *argv[])
{
	DIR		*dp;
	struct dirent	*dirp;

	if (argc != 2)
		err_quit("Usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
