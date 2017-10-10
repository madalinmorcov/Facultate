import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Ex2{

	public static void main(String[] args){
		try{
			File myFile = new File("input2.txt");
			Scanner sc = new Scanner(myFile);
		
			String myNumberAsString=sc.nextLine();
			
			//check real numbers
			if(myNumberAsString.matches("^[-][0-9]+[.][0-9]+|[0-9]+[.][0-9]+$")){
				System.out.println(myNumberAsString + " real");
			}
			
			//check integer numbers
			else if(myNumberAsString.matches("^[-][0-9]+$")){
				System.out.println(myNumberAsString + " integer");
			}
			
			//check natural numbers
			else if(myNumberAsString.matches("^[0-9]+$")){
				System.out.println(myNumberAsString + " natural");
			}	
			
			else {
				System.out.println("invalid number");
			}
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}