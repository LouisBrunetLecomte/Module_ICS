public class Velo extends Terrestre implements Rouler, Transporter {

    private boolean aPanier;

    public Velo(String nom, boolean aPanier) {
        super(nom);
        this.aPanier = aPanier;
    }

    public boolean isAPanier() {
        return this.aPanier;
    }

    public void setAPanier(boolean aPanier) {
        this.aPanier = aPanier;
    }

    @Override
    public void rouler() {
        System.out.println(this.getNom() + " roule.");
    }

    @Override
    public void transporter() {
        if (this.aPanier) {
            System.out.println(this.getNom() + " transporte des affaires grâce à son panier.");
        } else {
            System.out.println(this.getNom() + " n'a pas de panier, il ne peut pas transporter.");
        }
    }
}
