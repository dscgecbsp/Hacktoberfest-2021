package condition;
import java.util.*;

public class strongno {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i,temp,r,fact,sum=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the numbers");
		int n=sc.nextInt();
		temp=n;
		while(n>0) {
			r=n%10;
			fact=1;
			for(i=r;i>=1;i--) {
				fact=fact*i;
			}
			sum=sum+fact;
			n=n/10;
		}
		if(temp==sum) {
			System.out.println("strong numbers");
		}
		else {
			System.out.println("not a strong numbers");
		}

	}

}
