public class Produit {

    private String nom;
    private String categorie;
    private double prixHT;
    private static final String CAT_ELECTRONIQUE = "ELECTRONIQUE";
    private static final String CAT_ALIMENTAIRE = "ALIMENTAIRE";
    private static final String CAT_VESTIMENTAIRE = "VESTIMENTAIRE";
    private static final String CAT_AUTRE = "AUTRE";

    
    public void setNom(String nom){
        this.nom = nom;
    }

    public String getNom() {
        return nom;
    }


    public void setCategorie(String categorie){
        String categorie2 = categorie.toUpperCase();
        if (categorie2.equals(CAT_ALIMENTAIRE) || 
        categorie2.equals(CAT_ELECTRONIQUE) || 
        categorie2.equals(CAT_VESTIMENTAIRE) || 
        categorie2.equals(CAT_AUTRE)){
            this.categorie = categorie2;
        }else{
            this.categorie = CAT_AUTRE;
        }
    }

    public String getCategorie() {
        return categorie;
    }


    public void setPrixHT(double prixHT){
        if (prixHT < 0){
            this.prixHT = prixHT;
        }else{
            this.prixHT = 0;
        }
    }

    public double getPrixHT() {
        return prixHT;
    }



    public Produit(){

    }

    public Produit(String nom) {
        this(); // Pour appeler le constructeur sans paramètre
        this.nom = nom;
    }

    public Produit (String nom, String categorie, double prixHT) {
        this(nom);
        this.categorie = categorie;
        this.prixHT = prixHT;
    }
    /**
    * categorie : valeurs attendues ("ALIMENTAIRE", "ELECTRONIQUE", "VESTIMENTAIRE",
    "AUTRE")
    * chaîne vide "" si catégorie inconnue
    */

    




    /**
    * prixHT : valeur positive, 0.0 si inconnu
    */




    @Override
    public String toString() {
        return
        " nom='" + this.nom + "' / " +
        "taille='" + this.categorie + "' / " +
        "secteur='" + this.prixHT + "'";
    }

    @Override
    public boolean equals(Object obj) {
        Produit p;
        // vérification si obj est null ou référence une instance d'une autre classe
        if (obj == null || obj.getClass() != this.getClass()) 
        {
            return false;
        } 
        else 
        {
            p = (Produit) obj;
            // vérification des critères d'égalité sur le nom et la catégorie 
            // Utilisation de .equals() car String est un type référence (objet)
            if (p.getNom().equals(this.getNom()) && p.getCategorie().equals(this.getCategorie())) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        }
    }


    public int calculerFraisDePort(int poids) {
        if (poids < 1) 
        {
            return 5;
        } 
        else 
        {
            return 10;
        }
    }
    
}



