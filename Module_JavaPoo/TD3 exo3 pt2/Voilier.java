public class Voilier extends Aquatique implements NaviguerSurface, Transporter {

    public Voilier(String nom) {
        super(nom);
    }

    @Override
    public void naviguerSurface() {
        System.out.println(this.getNom() + " navigue en surface.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des passagers.");
    }
}
