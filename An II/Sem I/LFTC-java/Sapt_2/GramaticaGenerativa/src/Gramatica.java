import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Gramatica {

	private String VN=new String();
	private String VT=new String();
	private String S=new String();
	private List<String> P=new ArrayList<>();
	
	public String getVN() {
		return VN;
	}
	
	public String getVT() {
		return VT;
	}
	
	public String getS() {
		return S;
	}
	
	public List<String> getP() {
		return P;
	}

	public void readGramatica(Scanner sc) throws Exception {
		readVN(sc);
		readVT(sc);
		readS(sc);
		readP(sc);
	}
	
	private void readVN(Scanner sc) {
		VN=sc.nextLine();
	}
	
	private void readVT(Scanner sc) {
		VT=sc.nextLine();
	}
	
	private void readS(Scanner sc) {
		S=sc.nextLine();
	}
	
	private void readP(Scanner sc) throws Exception {
		String prod=new String();
		boolean hasStart=false;
		while(sc.hasNextLine()) {
			prod=sc.nextLine();
			if(verifyProd(prod)) {
				if(S.contains(prod.substring(0,1)) && !hasStart)
					hasStart=true;
				P.add(prod);
			}
		}
		if(!hasStart)
			throw(new Exception("Nu exista productie de start!"));
	}
	
	private boolean verifyProd(String prod) throws Exception {
		
		String p=new String();
		p=prod.substring(3);
		
		boolean foundNeterminal=false; // pentru gramatica regulata
		
		if(VT.contains(prod.substring(0,1)))
			throw(new Exception("Terminal folosit ca neterminal!"));
		
		for(int i=0;i<p.length();i++) {
			String symbol=p.substring(i,i+1);				
			if(!VN.contains(symbol) && !VT.contains(symbol))
				throw(new Exception("Simbol inexistent!"));
			else {
				if(VN.contains(symbol) && !foundNeterminal) 
					foundNeterminal=true;
				if(foundNeterminal && VT.contains(p.substring(i,i+1))) {
					throw(new Exception("Nu este gramatica regulata!"));
				}
			}
		}
		return true;
	}
	
	private boolean isWord(String word) {
		for(int i=0;i<word.length();i++)
			if(VN.contains(word.substring(i, i+1)))
				return false;
		return true;
	}
	
	private List<String> getPossibleProd(String symbol) {
		List<String> possibleProd = new ArrayList<>();
		for(String p : P) {
			if(p.substring(0, 1).equals(symbol)) { //productiile posibile cu symbol
				possibleProd.add(p);
			}
		}
		return possibleProd;
	}
	
	private boolean hasTerminalProd(String symbol) {
		List<String> possibleProd = new ArrayList<>();
		
		possibleProd = getPossibleProd(symbol);
		
		for(int i=0;i<possibleProd.size();i++)
			if(isTerminalProd(possibleProd.get(i)))
				return true;
		return false;
	}
	
	private boolean isTerminalProd(String prod) {
		
		for(int i=3;i<prod.length();i++)
			if(VN.contains(prod.substring(i,i+1)))
				if(!prod.substring(0,1).equals(prod.substring(i,i+1)))
					return hasTerminalProd(prod.substring(i,i+1));
				else
					return false;
		return true;
	}
	
	public String generateWord() throws Exception{
		Random r = new Random();
		String word = new String();
		
		List<String> possibleProd = new ArrayList<>();
		
		for(String p : P) {
			if(S.contains(p.substring(0, 1))) { //productiile de start posibile
				possibleProd.add(p);
			}
		}
		
		int prod = Math.abs(r.nextInt()) % possibleProd.size();
		word=possibleProd.get(prod).substring(3);
	
		while(!isWord(word)) {
			for(int i=0;i<word.length();i++) {
				String symbol=word.substring(i, i+1);
				if(VN.contains(symbol)) { // caut primul neterminal
					possibleProd = getPossibleProd(symbol); // update productiile posibile
					
					if(possibleProd.size()==0)
						throw(new Exception(symbol + " nu are productie!"));
					if(!hasTerminalProd(symbol))
						throw(new Exception(symbol + " nu are productie terminala!"));
					
					prod = Math.abs(r.nextInt()) % possibleProd.size();
					word = word.substring(0,i)+possibleProd.get(prod).substring(3)+word.substring(i+1);
					i--;
				}
			}
		}
		return word;
	}
	
}
