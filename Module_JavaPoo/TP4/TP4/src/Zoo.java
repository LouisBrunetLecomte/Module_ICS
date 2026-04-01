import java.util.ArrayList;

public class Zoo {


    public static String afficherAnimaux(ArrayList<Animal> animaux){
        String resultat = "Afficher les animaux : ";
        for (Animal animal : animaux) {
            resultat += animal.toString();
        }
        return resultat;
    }


    private static int rechercherAnimaux(ArrayList<Animal> animaux, String nom){
        for (int i = 0; i < animaux.size(); i++) {
            if (animaux.get(i).getNom().equalsIgnoreCase(nom)) {
                return i;
            }
        }
        return -1;
    }


    public static String repasAnimal(ArrayList<Animal> animaux, String nom){
        int index = rechercherAnimaux(animaux, nom);
        if (index >= 0) {
            Animal a = animaux.get(index);
            String repas = "";
            if (a instanceof Herbivore) {
                Herbivore h = (Herbivore) a;
                repas += h.PlantePreferee();
            }
            if (a instanceof ICarnivore) {
                ICarnivore c = (ICarnivore) a;
                if (repas == ""){ repas += " / ";
                repas += c.proiesPreferees();
                }
            }
            return "Le repas de " + a.getNom() + " : " + repas;
        }
        return "";
    }


    public static String faitCrierSesAnimaux(ArrayList<Animal> animaux){
        String result = "CRI" + "\n" + "---------------------------------------" + "\n";
        for (Animal a : animaux) {
            result += a.cri() + "\n";
        }
        return result;
    }

    public static boolean supprimerAnimal(ArrayList<Animal> animaux, String nom){
        int index = rechercherAnimaux(animaux, nom);
        if (index >= 0) {
            animaux.remove(index);
            return true;
        }
        return false;
    }

    public static String turieCarnivores(ArrayList<Animal> animaux){
        String result = "";
        for (Animal a : animaux) {
            if (a instanceof ICarnivore) {
                ICarnivore c = (ICarnivore) a;
                result += c.proiesPreferees();
            }
        }
        return result;
    }

    public static void trierAnimauxParDateNaissance(ArrayList<Animal> animaux) {
        for (int i = 0; i < animaux.size() - 1; i++) {
            for (int j = 0; j < animaux.size() - 1 - i; j++) {
                if (animaux.get(j).getAnneeNaissance() < animaux.get(j + 1).getAnneeNaissance()) {
                    Animal temp = animaux.get(j);
                    animaux.set(j, animaux.get(j + 1));
                    animaux.set(j + 1, temp);
                }
            }
        }
    }

    public static void trierAnimauxParNom(ArrayList<Animal> animaux) {
        for (int i = 0; i < animaux.size() - 1; i++) {
            for (int j = 0; j < animaux.size() - 1 - i; j++) {
                if (animaux.get(j).getNom().compareToIgnoreCase(animaux.get(j + 1).getNom()) > 0) {
                    Animal temp = animaux.get(j);
                    animaux.set(j, animaux.get(j + 1));
                    animaux.set(j + 1, temp);
                }
            }
        }
    }

    public static void trierAnimauxParPoidsDecroissant(ArrayList<Animal> animaux) {
        for (int i = 0; i < animaux.size() - 1; i++) {
            for (int j = 0; j < animaux.size() - 1 - i; j++) {
                if (animaux.get(j).getPoids() < animaux.get(j + 1).getPoids()) {
                    Animal temp = animaux.get(j);
                    animaux.set(j, animaux.get(j + 1));
                    animaux.set(j + 1, temp);
                }
            }
        }
    }

}
