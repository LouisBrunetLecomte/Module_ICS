import java.util.ArrayList;

public class progPrincipal {
    public static void main(String[] args) {
        Elephant Djumbo = new Elephant(1988, "Djumbo", 6000, SexeAnimal.Masculin, 3.5, Continent.Afrique);  
        Elephant ASIII = new Elephant(2020, "ASIII", 1500, SexeAnimal.Feminin, 2, Continent.Asie); 
        Girafe Pascal = new Girafe(2000, "Pascal", 1900, SexeAnimal.Masculin, 5.5);
        Girafe Sophie = new Girafe(2024, "Sophie", 400, SexeAnimal.Feminin, 2.8);
        Serpent Sonny = new Serpent(2022, "Sonny", 1.1, SexeAnimal.Masculin, 1, EspeceSerpent.A_sonnette, true);
        Serpent Bois = new Serpent(2025, "Bois", 8.5, SexeAnimal.Feminin, 1.8, EspeceSerpent.Boa, false);
        Ours Teddy = new Ours(SexeAnimal.Masculin, "Teddy", 2016, 500, 3.0, OursEspece.Polaire);
        Ours Andromeda = new Ours(SexeAnimal.Feminin, "Andromeda", 2024, 80, 0.8, OursEspece.Brun);


        ArrayList <Elephant> listElephants = new ArrayList<>();
        listElephants.add(Djumbo);
        listElephants.add(ASIII);

        ArrayList <Girafe> listGirafe = new ArrayList<>();
        listGirafe.add(Pascal);
        listGirafe.add(Sophie);

        ArrayList <Serpent> listSerpents = new ArrayList<>();
        listSerpents.add(Sonny);
        listSerpents.add(Bois);
        
        ArrayList <Ours> listOurs = new ArrayList<>();
        listOurs.add(Teddy);
        listOurs.add(Andromeda);

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
        
        for (Serpent s : listSerpents){
            System.out.println(s.toString());
            System.out.println("Est adulte : " + s.estAdulte());
            System.out.println("Cri : " + s.cri());
            System.out.println(s.getNom() + " a pour nourriture préférée " + s.proiesPreferees() + " et en manges " + s.qtteViandeSemaine() + "kg par semaine" + ". Et le serpent " + s.getEspeceSerpent() + " tue avec cette méthode : " + s.tue());
            System.out.println("\n");
        }

        for (Ours o : listOurs){
            System.out.println(o.toString());
            System.out.println("Est adulte : " + o.estAdulte());
            System.out.println("Cri : " + o.cri());
            System.out.println(o.getNom() + " a pour nourriture préférée " + o.PlantePreferee() + " ainsi que " +  o.proiesPreferees() + " et en manges " + o.qtteViandeSemaine() / 7 + "kg par jours" + ". Il tue avec cette méthode " + o.tue());
            System.out.println("\n");
        }
    }
}
