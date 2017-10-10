import java.util.Scanner;

public class Ex1{

	public static void main(String[] args){
	
	String s;
	String c;

	int number=0;

	Scanner sc=new Scanner(System.in);
	c=sc.nextLine();
	s=sc.nextLine();

	if(s.contains(c)){
		System.out.println("Contains.");
		for(int it = 0; it < s.length(); it++)
			if( c.toCharArray()[0] == s.charAt(it) )
				number++;
		System.out.println(number);	

	}
	else
		System.out.println("Does not contain.");
	
	}


}