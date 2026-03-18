import java.util.Arrays;

public class Exercice4 {
    
    public static void main(String[] args) {

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
}