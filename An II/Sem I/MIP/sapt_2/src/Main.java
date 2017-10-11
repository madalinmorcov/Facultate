import java.util.Scanner;
import java.io.*;
import java.lang.*;

public class Main {

	private int citire() throws Exception
	{
		Scanner sc=new Scanner(System.in);
		return sc.nextInt();
	}
	
	private int devide(int a, int b) throws ArithmeticException
	{
		return a/b;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 /**File myFile = new File("test.txt");
		 try{
		 Scanner sf=new Scanner(myFile);}
		 catch(FileNotFoundException e){
			 System.out.println(e);
		 }*/
		Main obj = new Main();
		
		/**try{
			while(true)
				System.out.println(obj.citire());
		}
		catch(java.util.InputMismatchException e){
			System.out.println("Wrong input!");
		}
		catch(Exception e){
			System.out.println(e);
		}*/
		try{
			System.out.println(obj.devide(2, 0));
		}
		catch(Exception e){
			System.out.println("Wrong!");
		}
		
	}
}
