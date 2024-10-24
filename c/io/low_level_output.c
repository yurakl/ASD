#include <fcntl.h>

int main()
{
	//~ Рядок, який необхідно вивести
	char str[14] = "Hello, World\n";
	//~ Відкриваємо файл та отримуємо його номер - fd
	int fd = open("tmp.dat", O_CREAT | O_WRONLY);
	//~ Записуємо у файл під номером fd 12 байтів з адреси ptr
	write(fd, str, 14);
	//~ Записуємо у стандартний потік виведення (fd = 0, консоль) 12 байтів з адреси ptr
	write(1, str, 14);
}
