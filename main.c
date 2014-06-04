#include "slow_check.h"


int main(int argc, char *argv[])
{

    int time_spent,time_spentb,fin;
    int sa,sb;

    if (argc < 3) {
    fprintf(stderr,"Usage : slow_check [host] [port]\n");
    printf("Coded by 'The Black Cat'\n");
    exit(0);
    }

    sa =  create_socket(argv[1]);
    connect_socket(sa,argv[2]);
    create_rdata(argv[1]);
    time(&start);
    send_socket(sa,0);
    wait_socket(sa);
    time(&stop);
    time_spent = (int)(stop - start);
    printf("[!] Server waited for : %d secs\n", time_spent);

    sb =  create_socket(argv[1]);
    connect_socket(sb,argv[2]);
    create_rdata(argv[1]);
    time(&startb);
    send_socket(sb,1);
    wait_socket(sb);
    time(&stopb);
    time_spentb = (int)(stopb - startb);
    printf("[!] Server waited for : %d secs\n", time_spentb);

    fin = time_spentb - time_spent;

    if(fin < 9)
    {
        printf("[-] Not Vulnerable!\n");
    }else if(fin == 0)
    {
        printf("[?] Possibly Vulnerable!\n");
    }else if(fin > 9)
    {
        printf("[+] Vulnerable!\n");
    }



    return 0;
}
