import java.util.ArrayList;

public class Race {
    public static ArrayList<Thread> threadlist = new ArrayList<Thread>();
    
	public static ArrayList<Thread> startRace(ArrayList<Runner> names)
	{
		if(names != null)
		{
			for (Runner r : names) {
				Thread t1 = new Thread(new RunnerThread(r.getRunnerName(),
						r.getRunnerSpeed(), r.getRunnerRest())); 
				t1.start();				
				threadlist.add(t1);
			}
		}
		return threadlist;
	}
}
