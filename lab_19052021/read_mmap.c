#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>

int main(int argc, char const *argv[])
{
    unsigned char *f_map;
    int size;
    struct stat mm_status;
    const char * file_name = argv[1];
    int fd = open (argv[1], O_RDONLY);

    int status = fstat (fd, & mm_status);
    size = mm_status.st_size;
    
    f_map = (char *) mmap (NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    for (int i = 0; i < size; i++) {
        putchar(f_map[i]);
    }
    return 0;
}
