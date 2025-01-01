#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 50

int main(void) {
  // Because we use O_CREAT flag, we need to specify the mode we will create the file in, which in this case is 644 (check chmod / learn about linux permissions)
  int fd = open("Document.txt", O_WRONLY | O_CREAT, 0644);

  // On error, -1 is returned and errno is set to indicate the error
  if (fd == -1) {
    printf("Failed to open file\n");
    return 1;
  }

  const char* txt = "Hello World";

  ssize_t w_code = write(fd, txt, strlen(txt));

  if (w_code == -1) {
    printf("Failed to write file\n");
    return 1;
  }

  printf("Number of bytes written: %d\n", w_code);

  close(fd);
  return 0;
  
}
