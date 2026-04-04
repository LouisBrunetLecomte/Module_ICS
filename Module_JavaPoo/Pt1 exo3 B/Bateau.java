public class Bateau extends Vehicule implements Naviguer, Transporter {

    public Bateau(String nom) {
        super(nom);
    }

    @Override
    public void naviguer() {
        System.out.println(this.getNom() + " navigue sur l'eau.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des passagers.");
    }
}
