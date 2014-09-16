 
class RunnerThread implements Runnable {

	//Declare local variables
	private String name;
	private int rest;
	private int speed;
	private int distance;
	boolean interrupted = false;
	public static String lock = new String("sadsa");

	// Constructor
	public RunnerThread(String name, int speed, int restper)
	{
		this.name = name;
		this.rest = restper;
		this.speed = speed;
		
		// System.out.println("Thread State of : name " + name + " speed "+ speed+ " rest  "+chance);
	}
	public String getName() {
		return this.name;
	}
	//@Override run() method
	public void run() 
	{
		int randomNo;
		boolean value = true;

		while (!Thread.currentThread().isInterrupted() && value == true) 
		{
			try 
			{
				Thread.sleep(100);

				randomNo = (int) (Math.random() * 100);
				distance += speed;
				if (rest < randomNo) {									
					System.out.println(name + " : " + distance + " m");
					if (distance >= 1000) {
						synchronized (lock) {	
							System.out.println(name + " : I finished " + distance + "\n");
							MainInterface.finished(Thread.currentThread(), name);
							return;
						}
					}				
				} else {
					Thread.sleep(100);
				}

			} catch (InterruptedException e) {
				value = false;
				System.out.println(name.toUpperCase() + ": You beat me fare and square!");
				return;

			}
		}

		if (value == true) // race condition to end the thread aka race here..
		{
			System.out.println(Thread.currentThread().getName()
					+ ": You beat me fair and square."); 
		}
	}


}
