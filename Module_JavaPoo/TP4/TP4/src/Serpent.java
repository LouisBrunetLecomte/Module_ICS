public class Serpent extends Animal {
    private EspeceSerpent especeSerpent;
    private boolean Venimeux;


    public Serpent(EspeceSerpent especeSerpent, boolean Venimeux) {
        this.especeSerpent = especeSerpent;
        this.Venimeux = Venimeux;
    }


    public Serpent(){
        super();
    }

    public Serpent(int anneeNaissance, String nom, double poids, SexeAnimal sexe, double taille, String especeSerpent, boolean Venimeux) {
        super(anneeNaissance, nom, poids, sexe, taille);
    }

    @Override
    public String cri() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'cri'");
    }

    @Override
    public boolean estAdulte() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'estAdulte'");
    }

    @Override
    public String toString(){
        return super.toString() + "\n" +
            "type: serpent";
    }

}

    
