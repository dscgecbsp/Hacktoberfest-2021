/*
Write a JAVA program to Perform string operations like accepting string from user,printing string as output
finding length of string, reverse, concatenation and substring using StringBuilder class.
*/

import java.util.Scanner;
public class Main
{
  public static void main (String[]args)
  {
    Scanner scn = new Scanner (System.in);
    
    System.out.println ("Enter your string:");
    String s1 = scn.nextLine ();
    
    StringBuilder str1 = new StringBuilder ();
    str1.append (s1);
    
    System.out.println ("Enter your string:");
    String s2 = scn.nextLine ();
    
    StringBuilder str2 = new StringBuilder ();
    str2.append (s2);
    
    //choosing an option 
      System.out.println ("Enter your choice:");
      System.out.println ("1-to find length");
      System.out.println ("2-to concnetate strings");
      System.out.println ("3-to find substring");
      System.out.println ("4-to compare strings");
      System.out.println ("5-to reverse strings");


    int n = scn.nextInt ();
    if (n == 1)
      {
	System.out.println ("the length of string 1 is:" + str1.length ());
	System.out.println ("the length of string 2 is:" + str2.length ());
      }
    else if (n == 2)
      {
	System.out.println ("your concanetated string is :" + str1 + " " +
			    str2);
      }
    else if (n == 3)
      {
	System.out.println ("Enter number to find substring from :");
	int x = scn.nextInt ();
	System.out.println ("the substring is:" + str1.substring (x));
      }
    else if (n == 4)
      {
	System.out.println
	  ("The result of whether your strings are equal or not is " +
	   str1.equals (str2));
      }
      else if(n==5){
          System.out.println ("the reversed string is:" + str1.reverse());
      }
  }
}
