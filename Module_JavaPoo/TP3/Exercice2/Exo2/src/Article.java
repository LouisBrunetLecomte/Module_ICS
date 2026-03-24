public class Article {
    int numero;
    String reference;
    String designation;
    double prix;
    int nbarticle;

    // Constructeur
    public Article(){

    }
    public Article(String reference){

    }
    public Article(String reference, String designation){

    }
    public Article(String reference, String designation, double prix){
        this.numero = numero;
        this.reference = reference;
        this.designation = designation;
    }

    public String toString(){
        return "test";
    }

}