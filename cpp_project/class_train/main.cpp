char* buf;
# include <unistd.h>
int fd[2];
// fd[0] is the read end of the pipeline; fd[1] is the write end of the pipeline. If not needed, you can close the descriptor of the corresponding end.
int pipe (int fd [2]);
// Return value: Successfully returns 0, error returns -1
// The parameter fd is the pipeline descriptor, which is the same as the file descriptor. You can use the file I/O functions (close, read, write) to operate it.
int close(int fd);//Close the file specified by the file descriptor fd
size_t read(fd, (void *)buf, size_t count);
size_t write(fd, (void *)buf, size_t count);