import java.util.Scanner;

public class Validation 
{
	public int getIntWithinRange(Scanner sc, int min, int max)
	{
		boolean isValid = false;
		int returnInt = 0;
		
		while(isValid == false)
		{
			returnInt = sc.nextInt();
			if(returnInt >= min && returnInt <=max)
				isValid = true;
			else
				System.out.println("Invalid input. please enter number between " + min + " & " + max);
			sc.nextLine();
		}
		
		return returnInt;
	}
	
	//this function accepts user input till enter is pressed. 
	public static String getString(Scanner sc)
	{
		String returnString = null;
		returnString = sc.nextLine();
		return returnString;
		
	}
	
}

