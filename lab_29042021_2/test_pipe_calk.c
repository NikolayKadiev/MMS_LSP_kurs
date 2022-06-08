#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main(){
	int p_parent[2], p_child[2];
	float a=0.0, b=0.0;
	pipe(p_parent);
	pipe(p_child);
	pid_t pid = fork();
	if(!pid){
			dup2(p_parent[0], STDIN_FILENO);
			dup2(p_child[1], STDOUT_FILENO);
			execlp("bc", "bc", (char *) NULL);
	}
	else{
			char send_buf[100];
			char receive[100];
			printf("insert a = ");
			scanf("%f",&a);
			printf("insert b = ");
			scanf("%f",&b);
			sprintf(send_buf, "%.3f+%.3f\n", a,b);
			write(p_parent[1], send_buf, strlen(send_buf));
			read(p_child[0],receive, 20);
			printf("%.3f + %.3f= %s", a, b, receive);
	}
	
}
