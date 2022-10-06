#include <stdio.h>

int main() {
    
    int T;
    scanf("%d",&T);
    
    while(T--){
        char id;
        scanf("%c\n",&id);
        if(id=='B' || id=='b'){
           printf("BattleShip \n");
        }
        else if(id=='C' || id=='c'){
           printf("Cruiser  \n");
        }
        else if(id=='D' || id=='d'){
           printf("Destroyer  \n");
        }
        else if(id== 'F' || id=='f'){
           printf("Frigate \n");
        }
    }
	// your code goes here
	return 0;
}


