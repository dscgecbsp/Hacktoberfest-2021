class InvalidPinException extends ArithmeticException
{
    public InvalidPinException(String s)
	{
		super(s);
	}
}
class InsufficientFundsException extends ArithmeticException
{
    public InsufficientFundsException(String s)
	{
		super(s);
	}
}
class BankTest
{
     public static void main(String[] args)
	 {
         if(args.length==2)
		 {
		 int pin=Integer.parseInt(args[0]);
		 int amt=Integer.parseInt(args[1]);

		 int validPin=2019;
		 int balance=25000;
		 if(validPin!=pin)
		 {
			 throw new InvalidPinException("Invalid pin");
		 }
		 else
		 {
			 if(balance<amt)
			 {
				 throw new InsufficientFundsException("Insufficient balance to withdraw");
			 }
			 else{
				 balance=balance-amt;
				 System.out.println("Transaction completed successfully , your current balance is "+ balance);
			 }
		 
		 }
		 }
		 else
		 {
			 System.out.println("Pass arguments whil;e run");
		 }
		
	 }
}
