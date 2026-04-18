public class Doctorant extends EnseignantBase {
    private static final double TAUX_HORAIRE = 40;
    private static final int MAX_HEURES = 100;

    public Doctorant(String nom, String prenom, String specialite, int heures) {
        super(nom, prenom, specialite, heures);
    }

    @Override
    public double getSalaireBrut() {
        int heuresPayees = Math.min(heures, MAX_HEURES);
        return heuresPayees * TAUX_HORAIRE;
    }
}
