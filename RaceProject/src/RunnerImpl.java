import java.io.FileNotFoundException;
import java.util.ArrayList;

public interface RunnerImpl {	
		Runner getRunner(String runnerName);
		ArrayList<Runner> getRunners() throws NumberFormatException, FileNotFoundException; 
}
