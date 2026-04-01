public class Humain extends Animal implements IOmnivore {
    private static final int AGE_ADULTE = 18;
    private Continent continent;

    public Humain(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille, Continent continent) {
        super(anneeNaissance, nom, poids, sexe, taille);
        this.continent = continent;
    }

    @Override
    public String cri() {
        return "HOOOOOYAYAAIOOOYAAIOOOOOOO (Tarzan)";
    }

    @Override
    public boolean estAdulte() {
        if (getAge() >= AGE_ADULTE) {
            return true;
        } else {
            return false;
        }
    }


    @Override
    public String mangerAvec() {
        if (this.continent == Continent.Asie) {
            return "mange avec des baguettes";
        } else {
            return "mange avec des couverts";
        }
    }

    @Override
    public String PlantePreferee() {
        return "Soja";
    }

    @Override
    public double qttePlanteJour() {
        return 0.3; 
    }

    @Override
    public double qtteViandeSemaine() {
        return 1.5; 
    }

    @Override
    public String proiesPreferees() {
        return "Boeuf";
    }

    @Override
    public String tue() {
        return "L'humain ne tue pas à mains nues, il utilise des outils";
    }
    
    @Override
    public String toString() {
        return super.toString() + "\n" +
               "type: Humain\n" +
               "Origine: " + this.continent + "\n" +
               "Manière de manger: " + this.mangerAvec() + 
               " Cris : " + cri();
    }
}