public abstract class Animal {
    private int anneeNaissance;
    private String nom;
    private double poids;
    private SexeAnimal sexe;
    private double taille;
    private static final String UM_AGE = "an(s)";
    private static final String UM_POIDS = "kg";
    private static final String UM_TAILLE = "m";

    public Animal() {

    }

    public Animal(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille) {
        this.setAnneeNaissance(anneeNaissance);
        this.setNom(nom);
        this.setPoids(poids);
        this.setSexe(sexe);
        this.setTaille(taille);
    }


    // GET & SET
    public int getAge(){
        int age = 2026 - getAnneeNaissance();
        return age;
    }

    public int getAnneeNaissance() {
        return this.anneeNaissance;
    }
    public String getNom() {
        return this.nom;
    }
    public double getPoids() {
        return this.poids;
    }
    public SexeAnimal getSexe() {
        return this.sexe;
    }
    public double getTaille() {
        return this.taille;
    }
    public static String getUM_AGE() {
        return UM_AGE;
    }
    public static String getUM_POIDS() {
        return UM_POIDS;
    }
    public static String getUM_TAILLE() {
        return UM_TAILLE;
    }
    
    public void setAnneeNaissance(int anneeNaissance) {
        if (anneeNaissance > 2026) {
            System.out.println("Entrez une année de naissance valide");
        } else {
            this.anneeNaissance = anneeNaissance;
        }
    }

    public void setNom(String nom) {
        if (nom == null || nom.isEmpty()) {
            System.out.println("Il faut un nom");
        } else {
            this.nom = nom;
        }
    }

    public void setPoids(double poids) {
        if (poids < 0) {
            System.out.println("Il faut que le poid soit renseigné");
        } else{
            this.poids = poids;
        }
    }
    public void setSexe(SexeAnimal sexe) {
        this.sexe = sexe;
    }
    public void setTaille(double taille) {
        if (taille < 0) {
            System.out.println("Il faut que la taille soit renseigné");
        } else{
            this.taille = taille;
        }
    }

    
    // Override
    @Override
    public String toString(){
        return "\n" + "Nom : " + this.getNom() + "\n" +
        "Année de naissance : " + getAnneeNaissance() + "\n" +
        "Age : " + this.getAge() + UM_AGE + "\n" +
        "Poids : " + this.getPoids() + UM_POIDS + "\n" +
        "Sexe : " + this.getSexe() + "\n" + 
        "Taille : " + this.getTaille() + UM_TAILLE;
    }

    @Override
    public boolean equals (Object obj){
        if (obj == this){
            return true;
        }
        else{
            return false;
        }
    }

    // Abstraites
    public abstract String cri();
    public abstract boolean estAdulte();

}

