
public class ThreadRunner implements Runnable{

	private String runnerName;
	private int runnerSpeed;
	private int runnerRest;
	int distance=0;
	public static String winner;

	public ThreadRunner(String runnerName, int runnerSpeed, int runnerRest) {
		super();
		this.runnerName = runnerName;
		this.runnerSpeed = runnerSpeed;
		this.runnerRest = runnerRest;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		int random=0;
        try{
        	while(distance<1000 && (!Thread.currentThread().isInterrupted()))
        	{
	    		  random=(int)(Math.random()*100);
	    		  if(runnerRest<=random)
	    		  {
	    		      System.out.println("Running " +  runnerName  + "random number" + random);

	    			  distance+=runnerSpeed;
	    			  System.out.println("thread"+runnerName+"distance"+distance);
	    			  boolean isRaceWon = this.isRaceWon(distance);
	    				if(isRaceWon){
	    					break;
	    				}
	    		  }

        	}
        	
        } catch (Exception e) {
	         System.out.println("Thread " +  runnerName + " interrupted.");
	         return;
	     }
        
	}
	private boolean isRaceWon(int totalDistanceCovered){
		boolean isRaceWon =  false;
		if((ThreadRunner.winner==null )&&(totalDistanceCovered==1000)){
				String winnerName = Thread.currentThread().getName();
				ThreadRunner.winner = winnerName; //setting the winner name
				System.out.println("Winner is :"+ThreadRunner.winner);
				isRaceWon = true;
			}else if(ThreadRunner.winner==null){
			isRaceWon = false;
			}else if(ThreadRunner.winner!=null){
				isRaceWon = true;
			}
		return isRaceWon;
		}
}
