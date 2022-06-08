#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    unsigned char *f_map;
    int size;
    struct stat mm_status;
    char * result = NULL;
    
    const char * file_name = argv[1];
    int fp = open (argv[1], O_RDONLY);
    int status = fstat (fp, & mm_status);
    size = mm_status.st_size;
    
    f_map = (char *) mmap (NULL, size, PROT_READ, MAP_PRIVATE, fp, 0);
    result = strstr(f_map, argv[2]);
    
    if(result == NULL){
    	printf("Word \"%s\" is not in dictionary!\n",argv[2]);
    	}	
    else{
    	printf("Word \"%s\" is in dictionary!\n",argv[2]);
    	}
    	
    close(fp);
    return 0;
}
