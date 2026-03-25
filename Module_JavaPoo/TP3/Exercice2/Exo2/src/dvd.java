public class dvd extends Article{
    private int duree;
    private Personne realisateur;


    //////
    /// GET | SET
    //////

    public int getDuree() {
        return this.duree;
    }
    public void setDuree(int duree) {
        this.duree = 0 ;
        if (duree >=1 && duree <=3)
        this.duree = duree;
    }


    public Personne getRealisateur() {
        return this.realisateur;
    }

    public void setRealisateur(Personne realisateur) {
        this.realisateur = realisateur;
    }



    public dvd(){

    }

    public dvd(String reference, String designation, double prix, int duree, Personne realisateur){
        super(reference, designation, prix);
        this.setDuree(duree);
        this.setRealisateur(realisateur);
    }

    @Override
    public String toString(){
        return super.toString() +
        "Durée (min): " + this.getDuree() + " | " + 
        "Realisateur : " + this.getRealisateur();
    }

}
