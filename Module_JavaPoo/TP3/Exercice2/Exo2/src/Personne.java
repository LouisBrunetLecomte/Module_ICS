import java.time.LocalDate;
import java.util.ArrayList; // AJOUT 2.4
import java.util.List;      // AJOUT 2.4

public class Personne{
    private String nom;
    private String prenom;
    private LocalDate dateDeNaissance;
    private List<Article> oeuvres = new ArrayList<>(); // AJOUT 2.4

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

    // AJOUT 2.4 : Accesseurs pour la liste
    public List<Article> getOeuvres() {
        return this.oeuvres;
    }

    public void ajouterOeuvre(Article a) {
        if (!this.oeuvres.contains(a)) {
            this.oeuvres.add(a);
        }
    }

    public void retirerOeuvre(Article a) {
        this.oeuvres.remove(a);
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
        return this.getNom() + " " + this.getPrenom() + " " + this.getDateDeNaissance();
    }
}