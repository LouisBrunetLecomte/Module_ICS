public class Elephant extends Animal implements Herbivore{
    private Continent continent;
    private static final int AGE_ADULTE =13;
    private static final int AGE_LAIT =5;


    //getter et setters pour continent

    public Continent getContinent(){
        return this.continent;
    }

    public int getAGE_ADULTE(){
        return AGE_ADULTE;
    }

    public int AGE_LAIT(){
        return AGE_LAIT;
    }

    public void setContinent(Continent continent){
        this.continent = continent;
    }


    public Elephant() {
        super();
    }

    public Elephant(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille, Continent continent) {
        super(anneeNaissance, nom, poids, sexe, taille);
        this.setContinent(continent);
    }

    @Override
    public String cri() {
        if (estAdulte() == true) {
            return "HHHHHUUUUUUUUUUUUMMMMMMMM";
        }
        else{
            return "hhhuuuummm";
        }
        
    }

    @Override
    public boolean estAdulte() {
        if (AGE_ADULTE < getAge()) {
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public String toString(){
        String chaine = "";
        if (this.getContinent() == Continent.Afrique) {
            chaine += "Il/Elle a de très grandes oreilles et des défenses.";
        }
        else{
            chaine +=  "Il/Elle a de petites oreilles. ";
            if (this.getSexe() == SexeAnimal.Feminin) {
                chaine += "Elle n'as pas de défenses.";
                
            } else {
                chaine += "Il a des défenses.";
            } 
        }

        return super.toString() + "\n" +
                    "type: elephant" + "\n" + 
                    "origine : " + this.getContinent() + "\n" +
                    "info sup : " + chaine + "\n";
    }

    @Override
    public String PlantePreferee() {
        String PlantePreferee;
        if (continent == Continent.Afrique) {
            if (this.getAge() <= AGE_LAIT) {
                PlantePreferee = "le Lait";
            } else {
            PlantePreferee = "les feuillages et arbustes";
            }
        } 
        else {
            if (this.getAge() <= AGE_LAIT) {
                PlantePreferee = "le Lait";
            } else {
            PlantePreferee = "les Herbes";
            }
        }
        return PlantePreferee;
    }


    @Override
    public double qttePlanteJour() {
        double qttePlanteJour = this.getPoids() * 0.25;
        return qttePlanteJour;
    }
}
