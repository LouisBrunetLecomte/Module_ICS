public class Girafe extends Animal implements Herbivore{
    private Continent continent;
    private static final int AGE_ADULTE =4;
    private static final int AGE_LAIT = 2;


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


    public Girafe(){
        super();
    }

    public Girafe(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille) {
        super(anneeNaissance, nom, poids, sexe, taille);
        this.setContinent(continent);
    }

    @Override
    public String cri() {
        if (estAdulte() == false) {
            return "MUUUUUUUU";
        }
        else{
            return "muuuuuuu";
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
        return "\n" + super.toString() + "\n" +
                "type: Girafe" + "\n";
    }

    @Override
    public String PlantePreferee() {
        String PlantePreferee;
        if (this.getAge() <= AGE_LAIT) {
            PlantePreferee = "Lait";
        } else {
            PlantePreferee = "feuillages et arbustes";
        }
        return PlantePreferee;
    }

    @Override
    public double qttePlanteJour() {
        double qttePlanteJour = this.getPoids() * 0.25;
        return qttePlanteJour;
    }
}
