#include <stdio.h>
#include <unistd.h>

int main() {
	char buffer[100];
	int bytesRead;
	write(1, "Enter some text: ", 17);
	bytesRead = read(0, buffer, sizeof(buffer));
	write(1, "You entered: ", 13);
	write(1, buffer, bytesRead);
	return 0;
}
