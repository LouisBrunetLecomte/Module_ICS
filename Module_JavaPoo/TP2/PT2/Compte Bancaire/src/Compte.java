public class Compte {
    // ATTRIBUTS
    private static final String MONNAIE = "euros"; // Convention de nommage : constante en majuscules en java (final)
    private static int numAuto = 0; 
    private int numCpt;
    private double solde;





    // ACCESSEURS
    public double getSolde() {
        return this.solde;
    }

    public int getNumCpt() {
        return this.numCpt;
    }

    public static int getNumAutoSuivant() {
        return numAuto;
    }







    // CONSTRUCTEURS
    public Compte() {
        // pas de paramètres constructeur vide 
    }

    public Compte(double solde) {
        // A COMPLETER
        this.solde = solde;
    }





    // Méthodes surchargées
    @Override
    public boolean equals(Object o) {
        if (o == null || o.getClass() != this.getClass())
            return false;
        if (o instanceof Compte) {
            Compte c = (Compte) o;
            // A COMPLETER
            

        }
        return false;
    }

    @Override
    public String toString() {
        return "\nNuméro de compte : " + this.getNumCpt() + "\nSolde : " + this.getSolde() + " " + Compte.MONNAIE;
    }





    // AUTRES METHODES
    public boolean debiter(double montant) {
        this.solde = this.solde - montant;
        return true;
    }

    public boolean crediter(double montant) {
        this.solde = this.solde + montant;
        return true;
    }

}