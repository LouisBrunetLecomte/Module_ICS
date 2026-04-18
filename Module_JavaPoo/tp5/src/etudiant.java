public class etudiant {
    private static final double TAUX_HORAIRE = 20;
    private static final int MAX_HEURES = 50;

    private String nom;
    private String prenom;
    private formation formation;
    private int heures;

    public etudiant(String nom, String prenom, formation formation, int heures) {
        if (nom == null || nom.isBlank()) throw new IllegalArgumentException("Nom invalide");
        if (prenom == null || prenom.isBlank()) throw new IllegalArgumentException("Prénom invalide");
        if (formation == null) throw new IllegalArgumentException("Formation invalide");
        if (heures < 0) throw new IllegalArgumentException("Les heures ne peuvent pas être négatives");
        this.nom = nom;
        this.prenom = prenom;
        this.formation = formation;
        this.heures = heures;
    }

    public String getNom() { return nom; }
    public String getPrenom() { return prenom; }
    public formation getFormation() { return formation; }
    public int getHeures() { return heures; }

    public double getSalaireBrut() {
        return Math.min(heures, MAX_HEURES) * TAUX_HORAIRE;
    }

    public double getCoutCPE() {
        return getSalaireBrut();
    }

    @Override
    public String toString() {
        return prenom + " " + nom + " (" + formation + ")";
    }
}