import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.String;

public class Ex8{
	
	public static void main(String[] args){
		
		try{
			Scanner sc=new Scanner(new File("input8.txt"));
			String strbuf= new String();
			strbuf=sc.nextLine();
			
			System.out.println(strbuf);
			
			for(int it=0;it<strbuf.length();it++)
				System.out.println(strbuf.substring(0,it+1));
			
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
	}

}