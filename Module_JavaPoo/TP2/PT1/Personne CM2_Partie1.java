import java.time.LocalDate;

public class Personne {
    
    private String nom; 
    private String prenom; 
    private LocalDate dateDeNaissance; 
    private int numero; //champ privé représentant le numéro de la Personne 
    private static int nbInstances; //champ statique privé représentant le compteur de Personnes
    
    public String getNom() 
    {
        return nom; 
    } 
    
    public void setNom(String n) 
    { 
        nom = n.toUpperCase(); 
    } 
    
    public String getPrenom() 
    {
        return prenom; 
    } 
    
    public void setPrenom(String p) 
    { 
        prenom = p.toLowerCase(); 
    }
    
    public LocalDate getDateDeNaissance() 
    {
        return dateDeNaissance; 
    } 
    
    public void setDateDeNaissance(LocalDate d) 
    { 
        dateDeNaissance=d;
    }

    // méthode d'instance permettant d'obtenir le numéro d'une Personne 
    public int getNumero() 
    { 
        return numero; 
    }
    
    // méthode statique permettant d'obtenir le nombre d'instances créées 
    public static int getNbInstances() 
    { 
        return nbInstances; 
    }
    
    //Constructeur
    public Personne() 
    { 
        // création d'une nouvelle Personne donc incrémentation du compteur 
        nbInstances++; 
        // affectation à la nouvelle Personne de son numéro 
        numero=nbInstances; 
    }

    public static void main(String[] args) throws Exception 
    {
        Personne p1 = new Personne();
        p1.setNom("COUTURIER");
        p1.setPrenom("Vincent");
        p1.dateDeNaissance= LocalDate.of(1974,1,29);
        System.out.println("N° de la personne : " + p1.numero);

        Personne p2 = new Personne();
        p2.setNom("DURAND");
        p2.setPrenom("Marc");
        p2.dateDeNaissance= LocalDate.of(1980,5,20);
        System.out.println("N° de la personne : " + p2.numero);

        System.out.println("Nb personnes créées : " + Personne.getNbInstances());
    }

}
