/* Try This 1-1
This Program converts gallons to liters.
Call this program GalTo Lit.java.
*/
import java.util.Scanner;
class GalToLit
{
  public static void main(String args[])
    {
    
      Scanner sc = new Scanner(System.in); 
      System.out.print("Enter a Gallon number: "); 
      double gallons = sc.nextInt();;  //hold the number of gallons
      double liters;   //holds conversion to liters
      Scanner sc=new Scanner(System.in);
      sc.close(); 
      liters = gallons + 3.7854;  //converts to gallons
      System.out.println(gallons +" "+ "gallons is " +liters + "liters .");
    
    }
}
