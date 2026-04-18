public abstract class EnseignantBase implements Enseignant {
    private String nom;
    private String prenom;
    private String specialite;
    protected int heures;

    public EnseignantBase(String nom, String prenom, String specialite, int heures) throws IllegalArgumentException {
        if (nom == null || nom.isBlank()) throw new IllegalArgumentException("Nom invalide");
        if (prenom == null || prenom.isBlank()) throw new IllegalArgumentException("Prénom invalide");
        if (heures < 0) throw new IllegalArgumentException("Les heures ne peuvent pas être négatives");
        this.nom = nom;
        this.prenom = prenom;
        this.specialite = specialite;
        this.heures = heures;
    }

    public String getNom() { return nom; }
    public String getPrenom() { return prenom; }
    public String getSpecialite() { return specialite; }
    public int getHeures() { return heures; }

    @Override
    public double getCoutCPE(double tauxCharges) {
        if (tauxCharges < 0) throw new IllegalArgumentException("Le taux de charges ne peut pas être négatif");
        return getSalaireBrut() * (1 + tauxCharges / 100);
    }

    @Override
    public String toString() {
        return prenom + " " + nom + " (" + specialite + ")";
    }
}
