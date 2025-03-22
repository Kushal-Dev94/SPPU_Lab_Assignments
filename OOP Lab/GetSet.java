class GetSet {
	private String name;

	public String getName() { 	// Method 1 - Getter
        return name;
    }

	public void setName(String N) { // Method 2 - Setter
		this.name = N;
	}
}

class GFG {

	// Main driver method
	public static void main(String[] args) {
		GetSet obj = new GetSet();

		obj.setName("Geeks for Geeks"); 	// Setting the name by calling setter method
		System.out.println(obj.getName());	// Getting the name by calling getter method
	}
}
