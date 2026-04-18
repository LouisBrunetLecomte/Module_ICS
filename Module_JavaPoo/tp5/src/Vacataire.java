public class Vacataire extends EnseignantBase {
    private static final double TAUX_HORAIRE = 60;
    private String organisme;

    public Vacataire(String nom, String prenom, String specialite, int heures, String organisme) {
        super(nom, prenom, specialite, heures);
        if (organisme == null || organisme.isBlank()) throw new IllegalArgumentException("Organisme invalide");
        this.organisme = organisme;
    }

    public String getOrganisme() { return organisme; }

    @Override
    public double getSalaireBrut() {
        return heures * TAUX_HORAIRE;
    }
}
