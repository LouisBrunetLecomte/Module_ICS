public class Article {
    private static int numero;
    private String reference;
    private String designation;
    private double prix;
    private int nbarticle;

    // Constructeur
    public Article(){

    }
    public Article(String reference){

    }
    public Article(String reference, String designation){

    }
    public Article(String reference, String designation, double prix){
        numero += 1;
        this.reference = reference;
        this.designation = designation;
        this.prix = prix;
    }

    public String toString(){
        return "Numéro de la bd : " + this.numero + " | référence : " + this.reference + " | Titre" + this.designation + " | Prix : " + this.prix + "€";
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
    public void setReference(String NewReference){
        this.reference = NewReference;
    }
    public void setDesignation(String NewDesignation){
        this.designation = NewDesignation;
    }
    public void setPrix(double NewPrix){
        this.prix = NewPrix;
    }
}
