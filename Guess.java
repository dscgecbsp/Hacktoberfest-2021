// Guess the letter game.
class Guess{
 public static void main(String args[])
throws java.io.IOException {
 char ch , answer ='K';
  System.out.println("I'm thinking of a letter between A to Z");
  System.out.print("Can you guess it : ");
ch = (char) System.in.read();   //read a char from the keyboard
 if(ch == answer) System.out.println("**Right **");   
 }
}