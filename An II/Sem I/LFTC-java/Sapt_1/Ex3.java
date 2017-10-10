import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Ex3{

	public static void main(String[] args){
		String V;
		String x;
		try{
			File myFile = new File("input3.txt");
			Scanner sc = new Scanner(myFile);
			
			V=sc.nextLine();
			x=sc.nextLine();
			
			if(x.matches("[" + V + "]+$"))
				System.out.println(x);
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
