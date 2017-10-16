import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.String;

public class Ex9{
	
	public static void main(String[] args){
		
		try{
			Scanner sc=new Scanner(new File("input9.txt"));
			String cuv1= new String();
			String cuv2 = new String();
				
			cuv1=sc.next();
			cuv2=sc.next();
			
			if(cuv1.substring(cuv1.length()-2,cuv1.length()).equals(cuv2.substring(cuv2.length()-2,cuv2.length())))
				System.out.println(true);			
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
	}

}