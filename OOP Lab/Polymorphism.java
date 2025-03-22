// Static or Compile time Polymorphism
class Polymorphism {


	static int Multiply(int a, int b)
	{
		return a * b;
	}


	static int Multiply(int a, int b, int c) // Function Overloading
	{
		return a * b * c;
	}
}

class CFG {
	public static void main(String[] args)
	{
		System.out.println(Polymorphism.Multiply(2, 4));
		System.out.println(Polymorphism.Multiply(2, 7, 3));
	}
}
