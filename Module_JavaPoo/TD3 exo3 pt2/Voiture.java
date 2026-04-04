public class Voiture extends Terrestre implements Rouler, Transporter {

    public Voiture(String nom) {
        super(nom);
    }

    @Override
    public void rouler() {
        System.out.println(this.getNom() + " roule.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des passagers.");
    }
}
