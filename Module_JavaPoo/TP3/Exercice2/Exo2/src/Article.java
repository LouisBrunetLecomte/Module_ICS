public class Article {
    private int numero;
    private String reference;
    private String designation;
    private double prix;
    private static int nbarticles;

    // Constructeur
    public Article(){
        nbarticles++; 
        this.numero=nbarticles;

    }
    public Article(String reference){
        this();
        this.setReference(reference);
    }
    public Article(String reference, String designation){
        this(reference);
        this.setDesignation(designation);

    }
    public Article(String reference, String designation, double prix){
        this(reference,designation);
        this.setPrix(prix);
    }

    public String toString(){
        return "Numéro : " + this.numero + " | référence : " + this.reference + " | Titre" + this.designation + " | Prix : " + this.prix + "€";
    }

    // Getter
    public String getReferance(){
        return this.reference;
    }
    public String getDesignation(){
        return this.designation;
    }
    public double getPrix(){
        return this.prix;
    }

    // setter
    public void setReference(String reference){
        this.reference = reference;
    }
    public void setDesignation(String designation){
        this.designation = designation;
    }
    public void setPrix(double prix){
        this.prix = prix;
    }
}
