import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;

public class Ex6{
	
	public static int wordCount;
	public static String[] words;
	
	public static void read(int n,Scanner sc){
		if(n>wordCount)
			return;
		String word=sc.nextLine();
		words[n]=word;
		read(n+1,sc);
		System.out.println(word);
	
	}
	
	public static void main(String[] args){
		
		try{
			File myFile=new File("input6.txt");
			Scanner sc=new Scanner(myFile);
			wordCount=sc.nextInt();
			words=new String[wordCount+1];
			read(0,sc);
			Arrays.sort(words);
			for(int i=0;i<=wordCount;i++){
				System.out.println(words[i]);
			}
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
		
	}
}
public static void read(int n,Scanner sc){
		if(n<=0)
			return;
		String word=sc.nextLine();
		read(n-1,sc);
		System.out.println(word);
}

public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	read(n,sc);
}