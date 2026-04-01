public class AppExo2 {
    public static void main(String[] args) {
        Humain enfant = new Humain(2023, "Charlotte Ofèses", 20.0, SexeAnimal.Feminin, 0.90, Continent.Asie);
        
        Humain adulte = new Humain(1992, "Jean Bonbeurre", 80.0, SexeAnimal.Masculin, 1.85, Continent.Europe);

        System.out.println("--- TEST ENFANT ---");
        System.out.println(enfant.toString());
        System.out.println("Adulte ? " + enfant.estAdulte());
        System.out.println("Ustensile : " + enfant.mangerAvec());

        System.out.println("\n--- TEST ADULTE ---");
        System.out.println(adulte.toString());
        System.out.println("Adulte ? " + adulte.estAdulte());
        System.out.println("Ustensile : " + adulte.mangerAvec());
    }
}

