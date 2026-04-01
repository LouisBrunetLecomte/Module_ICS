public class Serpent extends Animal implements ICarnicore{
    private EspeceSerpent especeSerpent;
    private boolean Venimeux;
    private static int AGE_ADULTE = 2;

    public EspeceSerpent getEspeceSerpent(){
        return this.especeSerpent;
    }

    public void setContinent(EspeceSerpent especeSerpent){
        this.especeSerpent = especeSerpent;
    }

    public Serpent(){
        super();
    }

    public Serpent(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille, EspeceSerpent especeSerpent, boolean Venimeux) {
        super(anneeNaissance, nom, poids, sexe, taille);
        this.especeSerpent = especeSerpent;
        this.Venimeux = Venimeux;
    }

    @Override
    public String cri() {
        if (this.especeSerpent != EspeceSerpent.A_sonnette && 
            this.especeSerpent != EspeceSerpent.Crotale && 
            this.especeSerpent != EspeceSerpent.Cornu) {
            return "sssssssssss";
        }
        else if (this.especeSerpent == EspeceSerpent.A_sonnette || 
                 this.especeSerpent == EspeceSerpent.Crotale) {
            return "dingdingding";
        }
        else {
            return "phicphicphic";
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
    
    public boolean Venimeux(){
        if (especeSerpent == EspeceSerpent.Boa || especeSerpent == EspeceSerpent.Couleuvre) {
            this.Venimeux = false;
        }
        else {
            this.Venimeux = true;
        }
        return Venimeux;
    }

    @Override
    public String toString(){
        return super.toString() + "\n" +
            "type: serpent" + "\n" +
            "Le serpent est venimeux ? : " + this.Venimeux() + "\n" +
            "espece : " + this.getEspeceSerpent() + "\n" +
            "Et le serpent " + this.getEspeceSerpent() + " tue avec cette méthode : " + this.tue();
    }

    @Override
    public double qtteViandeSemaine() {
        double qtteViandeSemaine = 0;
        if (this.getAge() < 1) {
            qtteViandeSemaine = 0.050;
        }
        else if(this.getAge() >= 1) {
            qtteViandeSemaine = 0.200;
        }
        if (this.getAge() >= 2) {
            qtteViandeSemaine = 1;
        }
        return qtteViandeSemaine;
    }

    @Override
    public String proiesPreferees() {
        String proiesPreferees = "";
        if (this.getAge() < 1) {
            proiesPreferees += "2 souriceaux ou équivalent";
        }
        else if(this.getAge() >= 1) {
            proiesPreferees += "deux souriceaux ou équivalent";
        }
        if (this.getAge() >= 2) {
            proiesPreferees += "Un cochon d'inde ou équivalent";
        }
        return proiesPreferees;
    }

    @Override
    public String tue() {
        String Tue = "";
        if (this.Venimeux == true) {
            Tue += "Morsure";
        }
        else if(this.Venimeux == false){
            if (this.especeSerpent == EspeceSerpent.Couleuvre) {
                Tue += "Avale la proie vivante";
            }
            else {
                Tue += "étouffe sa proie";
            }
        }
        return Tue;
    }

}

    
