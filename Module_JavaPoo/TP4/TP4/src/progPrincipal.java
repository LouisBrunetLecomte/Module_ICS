import java.util.ArrayList;

public class progPrincipal {
    public static void main(String[] args) {
        Elephant Djumbo = new Elephant(1988, "Djumbo", 6000, SexeAnimal.Masculin, 3.5, Continent.Afrique);  
        Elephant ASIII = new Elephant(2020, "ASIII", 1500, SexeAnimal.Feminin, 2, Continent.Asie); 
        Girafe Pascal = new Girafe(2000, "Pascal", 1900, SexeAnimal.Masculin, 5.5);
        Girafe Sophie = new Girafe(2024, "Sophie", 400, SexeAnimal.Feminin, 2.8);

        ArrayList <Elephant> listElephants = new ArrayList<>();
        listElephants.add(Djumbo);
        listElephants.add(ASIII);

        ArrayList <Girafe> listGirafe = new ArrayList<>();
        listGirafe.add(Pascal);
        listGirafe.add(Sophie);

        for (Elephant e : listElephants){
            System.out.println(e.toString());
            System.out.println("Est adulte : " + e.estAdulte());
            System.out.println("Cri : " + e.cri());
            System.out.println(e.getNom() + " a pour nourriture préférée " + e.PlantePreferee() + " et en manges " + e.qttePlanteJour() + "kg par jours");
            System.out.println("\n");
        }

        System.out.println("\n");

        for (Girafe g : listGirafe){
            System.out.println(g.toString());
            System.out.println("Est adulte : " + g.estAdulte());
            System.out.println("Cri : " + g.cri());
            System.out.println(g.getNom() + " a pour nourriture préférée " + g.PlantePreferee() + " et en manges " + g.qttePlanteJour() + "kg par jours");
            System.out.println("\n");
        }
        
    }
}
