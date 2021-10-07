#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
int random_no , guess_no , no_of_guess ;
time_t t;
printf("Its a guessing game...\n \n");
printf(" Guess the no. between 0 to 20.\n Lets see your guessing power!!!\n\n");
//initializing random no.
srand((unsigned) time(&t));
//generating random no.
random_no=rand()%21;

for(no_of_guess=5;no_of_guess >0;no_of_guess --)
{
    printf(" you have  %d tr%s left.\n\n",no_of_guess ,(no_of_guess ==1)?"y":"ies");
    printf("enter the guess: \n\n");
    scanf("%d",&guess_no);
    if(random_no ==guess_no)
   {
   printf("Congratutions , you guessed it.\n\n");
   break;
   }
    else if(guess_no  <0||guess_no>20)
    printf("i said the no. is between 0 to 20.\n\n");
    else if(guess_no>random_no )
    printf("Sry %d is wrong.My no. is less than that.\n\n",guess_no );
    else if(guess_no <random_no)
    printf("Sry %d is wrong.My no. is greater than that.\n\n",guess_no );
}
printf("Your tries are completed .The no. is %d.\n\n",random_no );
    return 0;
}
