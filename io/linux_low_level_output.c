#include <unistd.h>
#include <fcntl.h>

int main()
{
	//~ Рядок, який необхідно вивести
	char str[14] = "Hello, World\n";
	
	int fd = open("tmp.dat", O_CREAT | O_WRONLY);

	write(fd, str, 14);

	write(0, str, 14);
}
