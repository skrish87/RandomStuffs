
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import org.w3c.dom.DOMException;

public class MainInterface 
{
	static ArrayList<Thread> threadRunners;
	static boolean raceFinished = false;

	public static void main(String[] args) throws NumberFormatException, FileNotFoundException, DOMException  
	{
		boolean raceFinished = false;
		Thread ct = Thread.currentThread();
		Scanner sc = new Scanner(System.in);
		Validation validation = new Validation();
		int isContinue = 0;
		int fileChoice = 0;
		String ch = "";
			
		while (ch.equals("") && isContinue == 0) {
			displaySourceMenu();

			System.out.println("Enter your Option from [1-5]: ");
			fileChoice = validation.getIntWithinRange(sc, 1, 5); 

			switch (fileChoice) 
			{
				//From Derby Database
				case 1:

				//Reading input file from XML
				case 2: 
					String fileName = "/Users/zulfikar/Documents/workspace/JavaFinal/InputDataXML.xml";
					InputFromXML inputFromXML = new InputFromXML(fileName);
					ArrayList<Runner> runnersFromXML = new ArrayList<>();
					runnersFromXML = inputFromXML.getRunners();
					System.out.println("Race started!!!");
					threadRunners = Race.startRace(runnersFromXML);
					afterThreadWins();
					break;

				// Reading input from plain text data
				case 3: 
					fileName = "/Users/zulfikar/Documents/workspace/JavaFinal/InputDataText.txt";
					InputFromText inputFromText = new InputFromText(fileName);
					ArrayList<Runner> runnersFromText = inputFromText.getRunners();
					System.out.println("Race started!!!");
					threadRunners = Race.startRace(runnersFromText);
					afterThreadWins();
					break;

				// Just for two runners
				case 4: 
					ArrayList<Runner> twoRunners = new ArrayList<>();
					Runner r1 = new Runner("Dog", 10, 0);
					Runner r2 = new Runner("Hare", 100, 10);
					twoRunners.add(r1);
					twoRunners.add(r2);
					threadRunners = Race.startRace(twoRunners);
					afterThreadWins();
					break;

				case 5:
					fileChoice = 5;
					isContinue = 1;
					break;
			}
		}
	}

	public static void displaySourceMenu()
	{
		System.out.println("Welcome to the Marathon Race!!!");
		System.out.println();
		System.out.println("Select your data sources");
		System.out.println("1. Derby Database");
		System.out.println("2. XML file");
		System.out.println("3. Text file");
		System.out.println("4. Default two runners");
		System.out.println("5. Exit this application\n");
	}
		
	public static void afterThreadWins( )
	{
		while (raceFinished == false)
		{
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException e) {
				System.out.println("Exception by Interrupt!!");
			}
		}
		System.out.println("\nPress Enter key to continue...");
	}
		
	public static synchronized void finished(Thread winner, String name)
	{
		System.out.println();

		System.out.println("WinnerName : " + name);
		System.out.println("The race is over, " + name.toUpperCase() +" wins");

		for (Thread thread : threadRunners) {
			if (thread != winner) 
				thread.interrupt();			    
		}
		raceFinished = true;
	}
}

 
