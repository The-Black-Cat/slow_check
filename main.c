#include "slow_check.h"


int main(int argc, char *argv[])
{
	if (argc < 3) {
    fprintf(stderr,"Usage : slow_check [host] [port]\n");
    printf("Coded by 'The Black Cat'\n");
    exit(0);
    }
    
    
	pthread_t t1,t2;
	struct arg_struct t1_args,t2_args;
	int res;

	
	t1_args.host = argv[1];
	t1_args.port = argv[2];
	t1_args.mode = 0;
	
	t2_args.host = argv[1];
	t2_args.port = argv[2];
	t2_args.mode = 1;
	
	if(pthread_create(&t1,NULL,&slow_check,(void *)&t1_args) != 0)
	{
		printf("Error : Can't create thread '1'\n");
		return -1;
	}
	if(pthread_create(&t2,NULL,&slow_check,(void *)&t2_args) != 0)
	{
		printf("Error : Can't create thread '2'\n");
		return -1;
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	res = (int) (t2_args.time_spent - t1_args.time_spent);
	
	if(res < 9)
    	{
        	printf("[-] Not Vulnerable!\n");
    	}else if(res == 9)
    	{
        	printf("[?] Possibly Vulnerable!\n");
    	}else if(res > 9)
    	{
        	printf("[+] Vulnerable!\n");
	}



    return 0;
}
