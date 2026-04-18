public class Permanent extends EnseignantBase {
    private static final double SALAIRE_MENSUEL = 3000;
    private static final double TAUX_HEURE_COMP = 80;
    private static final int SEUIL_HEURES_COMP = 200;

    public Permanent(String nom, String prenom, String specialite, int heures) {
        super(nom, prenom, specialite, heures);
    }

    @Override
    public double getSalaireBrut() {
        double salaire = SALAIRE_MENSUEL * 12;
        if (heures > SEUIL_HEURES_COMP) {
            salaire += (heures - SEUIL_HEURES_COMP) * TAUX_HEURE_COMP;
        }
        return salaire;
    }
}
