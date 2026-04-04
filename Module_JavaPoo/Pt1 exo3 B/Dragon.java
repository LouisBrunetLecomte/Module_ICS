public class Dragon extends Animal implements Voler, Marcher, Cri {

    public Dragon(String nom) {
        super(nom);
    }

    @Override
    public void voler() {
        System.out.println(this.getNom() + " vole.");
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
