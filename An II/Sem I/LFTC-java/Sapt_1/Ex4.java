import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Ex4{

	public static void main(String[] args){
		String x;
		try{
			File myFile = new File("input4.txt");
			Scanner sc = new Scanner(myFile);
		
			x=sc.nextLine();
			x=new StringBuilder(x).reverse().toString();
			System.out.println(x);
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
