import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Path;
import java.util.ArrayList;

public abstract class RaceImpl implements RunnerImpl
{
	Path dataPath = null;
	protected File inputFile = null;
	ArrayList<Runner> Runners = new ArrayList<>();
	
	public RaceImpl(String fileName) {		
		inputFile = new File(fileName);		
	}
	
	protected boolean checkFileExists() throws FileNotFoundException
    {
        if (inputFile.exists()) {
        	return true;
        } else {
        	return false;
        }
    }
}
