import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.String;

public class Ex5{
	
	public static void main(String[] args){
		
		try{
			Scanner sc=new Scanner(new File("input5.txt"));
			String strbuf= new String();
			while(sc.hasNext())
			{	
				strbuf+=sc.nextLine();
			}
			strbuf=strbuf.replaceAll("[,.!?]+","");
			System.out.println(strbuf);
			String[] words = strbuf.trim().split("\\s+");
			System.out.println(words.length);
			for(int it=0;it<words.length;it++)
				System.out.println(words[it]);
			
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
	}

}