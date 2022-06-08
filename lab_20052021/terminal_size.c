#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

int main (void)
{
    struct winsize term;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term);

    printf ("Terminal size is: %d x %d\n", term.ws_col, term.ws_row);
    
    return 0; 
}
