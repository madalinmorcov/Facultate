import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.String;

public class Ex7{
	
	public static int getLength(String s){
		return s.length();
	}
	public static void main(String[] args){
		
		try{
			Scanner sc=new Scanner(new File("input7.txt"));
			String strbuf= new String();
			while(sc.hasNext())
			{	
				strbuf+=sc.nextLine();
			}
			System.out.println(getLength(strbuf));
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
	}

}