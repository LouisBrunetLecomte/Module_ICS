
import java.util.Scanner; 

public class App {
    public static void main (String args[]) {
        int rep;
        Scanner sc=new Scanner(System.in);
		do
		{
		    System.out.println("0.Quitter");
			System.out.println("1.Afficher infos");
			System.out.println("2.Afficher solde");
			System.out.println("3.Crediter");
			System.out.println("4.Debiter");
			rep = sc.nextInt();
			switch (rep)
			{
				case 0 : System.out.println("bye"); break;
				case 1 : 
						break;
				case 2 :
						break;
				case 3 :
						break;
				case 4 :
						break;
				default : System.out.println("erreur");
			}
		} 
		while (rep!=0);
        sc.close();
    }
}

