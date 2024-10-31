#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    unsigned int n1;
    unsigned int n2;
    char *p;
    int ip1,ip2,ip3,ip4;
    
    while(scanf("%s",str)!=EOF)
    //while(gets(str))
    {
        n2 =0;
        p = strtok(str,".");
        n1 = strtod(p,NULL);
        n2 = n2*256+n1;
        while((p=strtok(NULL,"."))!=NULL)
        {
            n1 = strtod(p,NULL);
            n2 = n2*256+n1;
        }
        printf("%u\n",n2);
        
        scanf("%d",&n2);
        ip4 = n2%256;
        n2 = n2/256;
        ip3 = n2%256;
        n2 = n2/256;
        ip2 = n2%256;
        n2 = n2/256;
        ip1 = n2;
        printf("%d.%d.%d.%d\n",ip1,ip2,ip3,ip4);
        
    }
}