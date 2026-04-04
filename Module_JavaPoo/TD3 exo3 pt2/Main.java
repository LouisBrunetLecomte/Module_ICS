public class Main {
    public static void main(String[] args) {

        Velo velo = new Velo("RockRyder", false);
        Voiture voiture = new Voiture("Aston Martin V12");
        SousMarin sousMarin = new SousMarin("SurMarin");
        Voilier voilier = new Voilier("MaRoueEstVoilier");

        System.out.println("=== " + velo.getNom() + " ===");
        System.out.println(velo.getNom() + " est un véhicule terrestre.");
        System.out.println(velo.getNom() + " est un vélo.");
        velo.rouler();
        velo.transporter();

        System.out.println();

        System.out.println("=== " + voiture.getNom() + " ===");
        System.out.println(voiture.getNom() + " est un véhicule terrestre.");
        System.out.println(voiture.getNom() + " est une voiture.");
        voiture.rouler();
        voiture.transporter();

        System.out.println();

        System.out.println("=== " + sousMarin.getNom() + " ===");
        System.out.println(sousMarin.getNom() + " est un véhicule aquatique.");
        System.out.println(sousMarin.getNom() + " est un sous-marin.");
        sousMarin.naviguerSurface();
        sousMarin.naviguerProfondeurs();
        sousMarin.transporter();

        System.out.println();

        System.out.println("=== " + voilier.getNom() + " ===");
        System.out.println(voilier.getNom() + " est un véhicule aquatique.");
        System.out.println(voilier.getNom() + " est un voilier.");
        voilier.naviguerSurface();
        voilier.transporter();
    }
}
