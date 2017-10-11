import java.util.Scanner;

public class TestException {
	public static void citire() throws MyException{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		if(s.contains(" "))
			throw new MyException("Spatiii !!");
	}
	
	public static void main(String[] args){
		try{
			citire();
		}
		catch(MyException myExcept)
		{
			System.out.println(myExcept);
		}
	}
}
