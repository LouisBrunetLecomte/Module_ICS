public class livre extends Article{
    private String isbn;
    private int nbPages;
    private Personne auteur;
 
    public String getIsbn() {
        return this.isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public int getNbPages() {
        return this.nbPages;
    }
    public void setNbPages(int nbPages) {
        // this.nbPages = 0 ;
        // if (nbPages >=1 && nbPages <=3)
        this.nbPages = nbPages;
    }

    public Personne getAuteur() {
        return this.auteur;
    }

    public void setAuteur(Personne auteur) {
        this.auteur = auteur;
    }


    public livre(){

    }

    public livre(String reference, String designation, double prix, String isbn, int nbPages, Personne auteur){
        super(reference, designation, prix);
        this.setIsbn(isbn);
        this.setAuteur(auteur);
        this.setNbPages(nbPages);
    }

    @Override
    public String toString(){
        return super.toString() + " | " +
        "Isbn : " + this.getIsbn() + " | " + 
        "Auteur : " + this.getAuteur() + " | " +
        "Nombre de pages : " + this.getNbPages();
    }
    

}
