#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 50

int main(void) {
  int fd = open("Document1.txt", O_RDONLY, 0);

  // On error, -1 is returned and errno is set to indicate the error
  if (fd == -1) {
    printf("Failed to open file\n");
    return 1;
  }

  char buf[BUFFER_SIZE + 1]; // +1 buf null terminator

  ssize_t bytes_read;

  while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0) {
    buf[bytes_read] = '\0';
    printf("%s",buf);
    
  }  
  printf("\n");

  close(fd);
  return 0;
}
