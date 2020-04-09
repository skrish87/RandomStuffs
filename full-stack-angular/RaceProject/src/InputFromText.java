import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

//
public class InputFromText extends RaceImpl {
	private final String DELIMITOR = ":";
	Runner r = null;
	ArrayList<Runner> Runners = new ArrayList<>();

	public InputFromText(String fileName)
	{
		super(fileName); 
	}

	public Runner getRunner(String r) {
		// TODO Auto-generated method stub
		return null;
	}
	
	public ArrayList<Runner> getRunners() throws NumberFormatException, FileNotFoundException 
	{
       Runners = new ArrayList<>();        
       if (checkFileExists())  { 
        	try (BufferedReader in = new BufferedReader(new FileReader(inputFile)))
            {                
                String line = in.readLine();
                System.out.println("Input --> " + line);
                while(line != null)
                {
                	String[] columns = line.split(DELIMITOR);
                    String rName = columns[0];
                    String rSpeed = columns[1];
                    String rRestPercent = columns[2];
                    System.out.println("rName " + rName);
                    r = new Runner(rName, Integer.parseInt(rSpeed), Integer.parseInt(rRestPercent));
                    Runners.add(r);
                    line = in.readLine();                    
                }
            }
            catch(IOException e)
            {
                return null;
            }
       }
       return Runners;
	 }
}

