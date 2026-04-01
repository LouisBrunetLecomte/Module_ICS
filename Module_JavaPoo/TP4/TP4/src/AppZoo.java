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
        Humain enfant = new Humain(2023, "Charlotte Ofèses", 20.0, SexeAnimal.Feminin, 0.90, Continent.Asie);
        Humain adulte = new Humain(1992, "Jean Bonbeurre", 80.0, SexeAnimal.Masculin, 1.85, Continent.Europe);


        ArrayList <Animal> listAnimal = new ArrayList<>();
        listAnimal.add(Djumbo);
        listAnimal.add(ASIII);
        listAnimal.add(Pascal);
        listAnimal.add(Sophie);
        listAnimal.add(Sonny);
        listAnimal.add(Bois);
        listAnimal.add(Teddy);
        listAnimal.add(Andromeda); 
        listAnimal.add(adulte);
        listAnimal.add(enfant);

        Scanner sc = new Scanner(System.in);
        int choix = -1;

        while (choix != 0) {
            System.out.println("-------------------------------------------");
            System.out.println("           MENU ZOO CPE                    ");
            System.out.println("-------------------------------------------");
            System.out.println("0. Quiter                                  ");
            System.out.println("1. Afficher des animaux                    ");
            System.out.println("2. Cri des animaux :                       ");
            System.out.println("3. Repas d'un animal                       ");
            System.out.println("4. Turie des carnivores                    ");
            System.out.println("5. Suppression d'un animal                 ");
            System.out.println("6. Trier les animaux par date naissance.   ");
            System.out.println("7. Trier les animaux par ordre alphabétique");
            System.out.println("8. Trier les animaux par poid.             ");
            System.out.println("-------------------------------------------");

            choix = sc.nextInt();
            sc.nextLine();

            System.out.println("-------------------------------------------");

            if (choix == 0) {
                System.out.println("Vous nous avez quitté... A bientôt");
            }

            else if (choix == 1) {
                System.out.println("Voici les animaux : " + Zoo.afficherAnimaux(listAnimal));
            }

            else if (choix == 2) {
                System.out.println("CRIS");
                System.out.println("-------------------------------------------");
                System.out.println(Zoo.faitCrierSesAnimaux(listAnimal));
            }

            else if (choix == 3) {
                System.out.println("REPAS");
                System.out.println("-------------------------------------------");
                System.out.print("Quel animal ? ");
                String nom = sc.nextLine();
                System.out.println( "Repas de " + Zoo.repasAnimal(listAnimal, nom));
            }

            else if (choix == 4) {
                System.out.println(Zoo.turieCarnivores(listAnimal));
            }

            else if (choix == 5) {
                System.out.println("SUPPRESSION");
                System.out.println("-------------------------------------------");
                System.out.print("Quel animal ? ");
                String nom = sc.nextLine();
                Zoo.supprimerAnimal(listAnimal, nom);
            }

            else if (choix == 6) {
                System.out.println("TRI DATE NAISSANCE");
                System.out.println("-------------------------------------------");
                Zoo.trierAnimauxParDateNaissance(listAnimal);
                System.out.println(Zoo.afficherAnimaux(listAnimal));
            }
            else if (choix == 7) {
                System.out.println("TRI PAR NOM (ALPHABÉTIQUE)");
                System.out.println("-------------------------------------------");
                Zoo.trierAnimauxParNom(listAnimal);
                System.out.println(Zoo.afficherAnimaux(listAnimal));
            }

            else if (choix == 8) {
                System.out.println("TRI PAR POIDS (DÉCROISSANT)");
                System.out.println("-------------------------------------------");
                Zoo.trierAnimauxParPoidsDecroissant(listAnimal);
                System.out.println(Zoo.afficherAnimaux(listAnimal));
            }
        }
    }
}
