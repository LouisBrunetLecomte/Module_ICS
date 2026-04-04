public class Avion extends Vehicule implements Voler, Transporter {

    public Avion(String nom) {
        super(nom);
    }

    @Override
    public void voler() {
        System.out.println(this.getNom() + " vole dans le ciel.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des passagers.");
    }
}
