//Hello every one!! I am Pratyush and below is a code to find the equivalent roman numeral of an inputted decimal number(up-to 10000(excluded)) using recursion.

/*For finding roman numeral equivalent of a decimal number using recursion, we will first set a limit up-to which we will convert. Then we will initialize a string having the codes used in Roman numerals. Then with concatenation, recursion and alternatively dividing the number by 2 and 5, we will obtain our result*/


#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int y=5000;            // for converting number up-to 10000 into roman numerals, the largest symbol we use is V for 5000
int z=0;               // variable used for alternate divisions by 2 and 5(to get series of 5000 -> 1000 -> 500 -> 100 -> 50 -> 10 -> 5 -> 1
void convert(int n,int a,char *ch)
{
	char c[]="VMDCLXVI";           // roman symbols in decreasing order(from 5000 to 1 in series of division by 5 and 2 alternatively)
	int i=0;
	for(i=n/a;i>0;i--)

		{
			strncat(ch, &c[z], 1);      // concatenation of equivalent symbol in our dynamically allocated string variable ch
		}
	n=n%a;
	z++;
	if(n>0)
		{
			if(z%2==1)                    // for alternate division by 5 and 2
			{
				a=a/5;
				convert(n,a,ch);    // recursive calls
			}
			else
			{
				a=a/2;
				convert(n,a,ch);     // recursive calls
			}
		}
	else                                  // printing of converted numbers
	{
		for(int k=0;k<2*sizeof(ch)+4;k++)
		{
			printf("%c",ch[k]);
		}
	}
}

void main()
{
	int n;
	char *ch;
	ch=malloc(100*sizeof(char));
	printf("enter the number which is to be converted to roman numeral(number should be less than 10000)\n");
	scanf("%d",&n);

	convert(n,y,ch);
	printf("\n");

}
