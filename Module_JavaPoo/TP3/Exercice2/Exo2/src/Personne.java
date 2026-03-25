import java.time.LocalDate;

public class Personne{
    private String nom;
    private String prenom;
    private LocalDate dateDeNaissance;

    public String getNom() {
        return this.nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return this.prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public LocalDate getDateDeNaissance() {
        return this.dateDeNaissance;
    }

    public void setDateDeNaissance(LocalDate dateDeNaissance){
        this.dateDeNaissance = dateDeNaissance;
    }

    public Personne(){

    }
    public Personne(String nom, String prenom, LocalDate dateDeNaissance){
        this.setNom(nom);
        this.setPrenom(prenom);
        this.setDateDeNaissance(dateDeNaissance);
    }

    @Override
    public String toString(){
        return this.getNom() + this.getPrenom() + this.getDateDeNaissance();
    }

    

}
