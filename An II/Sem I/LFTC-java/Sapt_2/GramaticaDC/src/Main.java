import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			File fis=new File("src/data.txt");
			Scanner sc = new Scanner(fis);
			//
			try {
				//
			}
			catch(Exception e) {
				e.printStackTrace();
				return;
			}
			int n;
			Scanner input=new Scanner(System.in);
			n=input.nextInt();
			for(int i=0;i<n;i++)
				try {
				//
				}
				catch(Exception e) {
					e.printStackTrace();
				}
		}
		catch(FileNotFoundException e){
			
		}
	}

}
