public class Main {
    public static void main(String[] args) {
        double tauxCharges = 30;

        EnseignantBase[] enseignants = {
            new Permanent("Prof1", "1", "Informatique", 300),
            new Vacataire("Prof2", "2", "Electronique", 80, "Siemens"),
            new Doctorant("Prof3", "3", "Chimie", 120)
        };

        System.out.println("Enseignants (charges : " + tauxCharges + "%)\n");
        for (EnseignantBase e : enseignants) {
            System.out.println(e);
            System.out.printf("  Salaire brut : %.2f €%n", e.getSalaireBrut());
            System.out.printf("  Coût CPE     : %.2f €%n%n", e.getCoutCPE(tauxCharges));
        }

        etudiant[] etudiants = {
            new etudiant("Etud1", "1", formation.ICS, 30),
            new etudiant("Etud2", "2", formation.GPI, 60),
            new etudiant("Etud3", "3", formation.ETI, 50)
        };

        System.out.println("Étudiants tuteurs (pas de charges)\n");
        for (etudiant et : etudiants) {
            System.out.println(et);
            System.out.printf("  Salaire brut : %.2f €%n", et.getSalaireBrut());
            System.out.printf("  Coût CPE     : %.2f €%n%n", et.getCoutCPE());
        }

        try {
            new Permanent("", "Alice", "Info", 100);
        } catch (IllegalArgumentException ex) {
            System.out.println("Exception attendue : " + ex.getMessage());
        }
        try {
            new etudiant("Test", "Test", null, 10);
        } catch (IllegalArgumentException ex) {
            System.out.println("Exception attendue : " + ex.getMessage());
        }
    }
}