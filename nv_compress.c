/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* s){
	
	int len=strlen(s);
	char* ans=malloc(len);
	int idx=0;
	int last=s[0];
	int dup_times=1;

	for(int i=0;i<len;i++){
		dup_times=1;
		last=s[i];
		while((s[i+1]==last) &&((i+1)<len)){
			i++;
			dup_times++;;
		}
		ans[idx++]=last;
		if(dup_times>1){
			char buf[12];
			snprintf(buf,sizeof(buf),"%d",dup_times);
			for(int j=0;buf[j];j++){
			    ans[idx++]=buf[j];
			}
		}
	}
	ans[idx]='\0';

	return ans;
}

int main()
{
    printf("%s\n",compress("abaabbbc"));

    return 0;
}
