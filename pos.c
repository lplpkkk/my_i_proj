/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


 
unsigned char t_tar[8]={0x07, 0xA0, 0x00, 0x00, 0x00, 0x04, 0x30, 0x60};
unsigned char t_tar2[8]={0x07, 0xA0, 0x00, 0x00, 0x00, 0x04, 0x99, 0x99};

unsigned char t_ter[17]={0x07, 0xA0, 0x00, 0x00, 0x00, 0x04, 0x10, 0x10, 0x07, 0xA0, 0x00, 0x00, 0x00, 0x04, 0x30, 0x61, 0x00
};
unsigned char t_ter2[35]={0x08, 0xA0, 0x00, 0x00, 0x00, 
0x03, 0x10, 0x10, 0x02, 0x08, 0xA0, 0x00, 0x00, 0x00, 
0x03, 0x10, 0x10, 0x01, 0x07, 0xA0, 0x00, 0x00, 0x00, 
0x04, 0x10, 0x10, 0x07, 0xA0, 0x00, 0x00, 0x00, 0x04, 0x30, 0x60, 0x00};
                                   
                                   
                                   
int build_candidate_list(unsigned char *candidate_list, unsigned char *card_aids, unsigned char *terminal_aids){
    
}
                                  
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                                
int is_aid_supported(unsigned char *target_aid, unsigned char *terminal_aids){
    
    if(terminal_aids==NULL){
        return 0;
    }
    
	// write your code here.
	int target_len=target_aid[0];//7
	
	int this_len=terminal_aids[0];//7
	unsigned char* p=terminal_aids;//addr of terminal_aids
	
	int find_diff=0;
	
	while(1){
	    if(this_len!=target_len){
	        goto chk_next;
	    }
	    
	    //compare if it match
	    for(int i=1;i<=target_len;i++){
	        if(target_aid[i]!=p[i]){
	            find_diff=1;
	        }
	    }
	    
	    if(!find_diff){
	        return 1;
	    }
	    
	    chk_next:
	    // if not, point to next "aid structure"
	    find_diff=0;
	    
	    p=p+this_len+1;
	    
	    if(p[1]==0){//7
	        break;
	    }else{
	        this_len=p[0];    
	    }
	}
	return 0;
	
}


int main()
{
    
    printf("ans=%d \n",is_aid_supported(t_tar2,t_ter2));
    
    return 0;
}
