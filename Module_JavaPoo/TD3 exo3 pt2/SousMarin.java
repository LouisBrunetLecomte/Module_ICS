public class SousMarin extends Aquatique implements NaviguerSurface, NaviguerProfondeurs, Transporter {

    public SousMarin(String nom) {
        super(nom);
    }

    @Override
    public void naviguerSurface() {
        System.out.println(this.getNom() + " navigue en surface.");
    }

    @Override
    public void naviguerProfondeurs() {
        System.out.println(this.getNom() + " navigue en profondeur.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des choses.");
    }
}
