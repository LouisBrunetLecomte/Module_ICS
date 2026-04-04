public class Lion extends Animal implements Marcher, Cri {

    public Lion(String nom) {
        super(nom);
    }

    @Override
    public void marcher() {
        System.out.println(this.getNom() + " marche.");
    }

    @Override
    public void crier() {
        System.out.println(this.getNom() + " rugit.");
    }
}
