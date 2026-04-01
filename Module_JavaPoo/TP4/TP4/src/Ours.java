public class Ours extends Animal implements ICarnivore, Herbivore{
    private OursEspece oursEspece;
    private static final int AGE_ADULTE = 3;
    private static final int AGE_ADULTE_BRUN = 4;


    private OursEspece getOursEspece() {
        return this.oursEspece;
    }

    private int getAGE_ADULTE() {
        return AGE_ADULTE;
    }

    private int getAGE_ADULTE_BRUN() {
        return AGE_ADULTE_BRUN;
    }


    public void setEspece(OursEspece newEspece) {
        this.oursEspece = newEspece;
    }



    public Ours() {
        super();
    }

    public Ours(SexeAnimal sexe, String nom, int anneeNaissance, double poids, double taille, OursEspece espece) {
        super(anneeNaissance, nom, poids, sexe, taille);
        this.oursEspece = espece;
    }


    
    public boolean estAdulte() {
        if (AGE_ADULTE <= getAge()) {
            return true;
        }
        else if(AGE_ADULTE >= getAge()){
            return false;
        }

        else if (AGE_ADULTE_BRUN <= getAge()) {
            return true;
        }
        else{
            return false;
        }
    }


    @Override
    public String PlantePreferee() {
        return "Fruits et racines";
    }


    @Override
    public double qttePlanteJour() {
        return (getPoids() * 0.07) / 2;
    }


    @Override
    public double qtteViandeSemaine() {
        return ((getPoids() * 0.07) / 2) * 7;
    }


    @Override
    public String proiesPreferees() {
        if (oursEspece == OursEspece.Polaire || oursEspece == OursEspece.Noir) {
            return " Insectes, oiseaux, petits mammifères, phoques et saumons";
        } else {
            return " Insectes, oiseaux, petits mammifères ";
        }
    }


    @Override
    public String tue() {
        return "L'ours " + oursEspece + " mord pour tuer";
    }

    
    @Override
    public String cri() {
        if (this.oursEspece == OursEspece.Polaire) {
            return "RRRROOOOOOOAAAAAAAAAGH";
        }
        else {
            return "roagh";
        }
    }

    @Override
    public String toString(){
        return "\n" + super.toString() + "\n" +
            "type: Ours" + "\n" +
            "espece : " + this.getOursEspece() + "\n";
    }


}