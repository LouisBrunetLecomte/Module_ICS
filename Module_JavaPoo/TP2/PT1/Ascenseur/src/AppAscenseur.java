public class AppAscenseur {
    public static void main(String[] args) throws Exception {
        Ascenseur MonAscenseur = new Ascenseur();
        MonAscenseur.setetageMin(-2);
        MonAscenseur.setetageMax(10);
        MonAscenseur.setetageCourant(7);
        MonAscenseur.va(5);

        System.out.println("Etage Minimum : " + MonAscenseur.getetageMin());
        System.out.println("Etage Maximum : " + MonAscenseur.getetageMax());
        System.out.println("Etage Courant : " + MonAscenseur.getetageCourant() + " " + MonAscenseur.avertisseur());
        System.out.println(MonAscenseur.etageValide(50));

        // Saut de ligne
        System.out.println(" ");
        //

        Ascenseur MonSecondAscenseur = new Ascenseur();
        MonSecondAscenseur.setetageMin(-15);
        MonSecondAscenseur.setetageMax(100);
        MonSecondAscenseur.setetageCourant(100);
        MonSecondAscenseur.va(5);

        System.out.println("Etage Minimum : " + MonSecondAscenseur.getetageMin());
        System.out.println("Etage Maximum : " + MonSecondAscenseur.getetageMax());
        System.out.println("Etage Courant : " + MonSecondAscenseur.getetageCourant() + " " + MonSecondAscenseur.avertisseur());
        System.out.println(MonSecondAscenseur.etageValide(2));
    }
}
