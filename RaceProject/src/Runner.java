public class Runner {
	private String name;
	private int speed;
	private int rest;
	public String getRunnerName() {
		return name;
	}
	public void setRunnerName(String name) {
		this.name = name;
	}
	public int getRunnerSpeed() {
		return speed;
	}
	public void setRunnerSpeed(int speed) {
		this.speed = speed;
	}
	public int getRunnerRest() {
		return rest;
	}
	public void setRunnerRest(int rest) {
		this.rest = rest;
	}
	
	public Runner(String name, int speed, int rest) {
		super();
		this.name = name;
		this.speed = speed;
		this.rest = rest;
	}
	
}
