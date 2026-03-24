import java.util.ArrayList;
import java.util.List;

public class Exercice1ArrayList {
    

    public static void main(String[] args) { 

        // Liste de mails.
        List<mails> liste1;
        liste1 = new ArrayList<mails>(); 

        mails p1 = new mails("sansDoute@youpi.tralala"); 
        mails p2 = new mails("non@cpe.fr");
        mails p3 = new mails("bakar@cpe.fr");
        mails p4 = new mails("jeNeCroisPas@cpe.fr");
        mails p5 = new mails("jAvoue@gmail.com");
        mails p6 = new mails("sansDoute@youpi.tralala");
        mails p7 = new mails("sansDoute@youpi.tralala");
        mails p8 = new mails("sansDoute@youpi.tralala");
        mails p9 = new mails("sansDoute@youpi.tralala");

        liste1.add(p1); 
        liste1.add(p2);
        liste1.add(p3);
        liste1.add(p4);
        liste1.add(p5);
        liste1.add(p6);
        liste1.add(p7);
        liste1.add(p8);
        liste1.add(p9);

        System.out.println("il y a " + liste1.size() + " mails dans la liste"); // faire une boucle pour lister tout les membres de la liste.




        // Liste des fournisseurs 





        // Liste des fournisseurs distincts




    }


}
/* 
    // Initialisation
        int position;
        int i = 0;
        String recherche = "@";

    // Tableau initiale, tableau brute
        String[] TabAdress = {"sansDoute@youpi.tralala", "non@cpe.fr", "bakar@cpe.fr", "jeNeCroisPas@cpe.fr", "jAvoue@gmail.com", "quansi@gmail.com", "maman@gmail.com", "abou@cpe.fr"};
        System.out.println("Liste brute des adresses mails");
        System.out.println(Arrays.toString(TabAdress));

    // Nouveau tableau permetant de l'avoir sur une ligne et ainsi de trier son contenu
        String[] StockTabAdress = new String[8];

        for (String s : TabAdress) { 
            position = s.indexOf(recherche);
            s.substring(position);
            StockTabAdress[i++] = s.substring(position + 1); // Ajout des caractères suivant "@" dans StockTabAdress
        }  

        System.out.println("Liste brute des fournisseurs :");
        System.out.println(Arrays.toString(StockTabAdress)); 

    // 
        String[] StockTabTri = StockTabAdress;
        System.out.println("Liste triée des fournisseurs");
        Arrays.sort(StockTabTri);
        System.out.println(Arrays.toString(StockTabTri));



    // Nouveau Tableau qui supprimera les doublons
            String[] StockTabUnique = new String[StockTabTri.length];
            int index =0;
            StockTabUnique[index]=StockTabTri[0];
            
            for (int j = 1; j < StockTabTri.length; j++) {
                if (!StockTabUnique[index].equals(StockTabTri[j])) {
                    index++;
                    StockTabUnique[index] = StockTabTri[j];
                }
            }
            System.out.println("Liste des fournisseurs distincts");
            //System.out.println(index);
            StockTabUnique=Arrays.copyOfRange(StockTabUnique, 0, index + 1);
            System.out.println(Arrays.toString(StockTabUnique));
        }
 */



