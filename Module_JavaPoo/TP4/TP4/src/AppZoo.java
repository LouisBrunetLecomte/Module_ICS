import java.util.ArrayList;
import java.util.Scanner;

public class AppZoo {
    public static void main(String[] args) {
        Elephant Djumbo = new Elephant(1988, "Djumbo", 6000, SexeAnimal.Masculin, 3.5, Continent.Afrique);  
        Elephant ASIII = new Elephant(2020, "ASIII", 1500, SexeAnimal.Feminin, 2, Continent.Asie); 
        Girafe Pascal = new Girafe(2000, "Pascal", 1900, SexeAnimal.Masculin, 5.5);
        Girafe Sophie = new Girafe(2024, "Sophie", 400, SexeAnimal.Feminin, 2.8);
        Serpent Sonny = new Serpent(2022, "Sonny", 1.1, SexeAnimal.Masculin, 1, EspeceSerpent.A_sonnette, true);
        Serpent Bois = new Serpent(2025, "Bois", 8.5, SexeAnimal.Feminin, 1.8, EspeceSerpent.Boa, false);
        Ours Teddy = new Ours(SexeAnimal.Masculin, "Teddy", 2016, 500, 3.0, OursEspece.Polaire);
        Ours Andromeda = new Ours(SexeAnimal.Feminin, "Andromeda", 2024, 80, 0.8, OursEspece.Brun);


        ArrayList <Animal> listAnimal = new ArrayList<>();
        listAnimal.add(Djumbo);
        listAnimal.add(ASIII);
        listAnimal.add(Pascal);
        listAnimal.add(Sophie);
        listAnimal.add(Sonny);
        listAnimal.add(Bois);
        listAnimal.add(Teddy);
        listAnimal.add(Andromeda); 

        Scanner sc = new Scanner(System.in);
        int choix = -1;

        while (choix != 0) {
            System.out.println("---------------------------------------");
            System.out.println("           MENU ZOO CPE                ");
            System.out.println("---------------------------------------");
            System.out.println("0. Quiter                              ");
            System.out.println("1. Afficher des animaux                ");
            System.out.println("2. Quiter                              ");
            System.out.println("3. Quiter                              ");
            System.out.println("4. Quiter                              ");
            System.out.println("5. Quiter                              ");
            System.out.println("6. Quiter                              ");
            System.out.println("---------------------------------------");

            

        }


    }
        



}
