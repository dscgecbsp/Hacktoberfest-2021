#include <stdio.h>
#include <math.h>

int main()
{   float a,b,c,d,r1,r2;
    printf("For a Quadratic Equation i.e ax^2 + bx + c = 0");
	
    //Entering Values

    printf("\nEnter the value of a :");
    scanf("%f", &a);

    printf("Enter the value of b :");
    scanf("%f", &b);

    printf("Enter the value of c :");
    scanf("%f", &c);

    d = b*b-4*a*c;
    printf("\nDiscriminant(D) = %.2f", d);
    getch();
    if (d > 0)
        {   r1 = -b + sqrt(d)/ 2*a;
            r2 = -b + sqrt(d)/ 2*a;
            printf("\n\nEquation have real root i.e :");
            printf("%.2f, %.2f\n\n", r1,r2);}
    else if (d == 0)
        {   r1 = -b/ 2*a;
            printf("\n\nEquation have Equal and real root i.e : ");
            printf("%.2f\n\n", r1);}
            //%.2f denotes the decimal accuracy which can be changed as per need
    
    else if (d < 0)
        printf("\n\nThe equation have imaginary root\n\n");
    else
        printf("\n\nNot a correct input\n\n");
    return 0;
}
