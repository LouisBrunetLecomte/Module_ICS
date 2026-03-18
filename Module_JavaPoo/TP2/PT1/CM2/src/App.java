public class App {
    public static void main(String[] args) throws Exception {
       
        Voiture v = new Voiture(); // vroum
        v.setImmatriculation("HA423BL");
        v.setModele("Macan");
        v.setMarque("Porsche");
        v.setConsoPourCentKm(18);
        v.setTailleReservoir(90);

        Voiture taPeugot = new Voiture("GE389AR", "5008", "Peugot", 7.5, 65);

        System.out.println("Voiture 1 :" + v.getImmatriculation());
        System.out.println("Voiture 1 : Couts Km " + v.calculerCoutKm());
        System.out.println("Voiture 1 : Couts plein " + v.calculerCoutPlein());
        System.out.println(" ");
        System.out.println("Voiture 2 :" + taPeugot.getImmatriculation());
        System.out.println("Voiture 2 : Couts Km " + taPeugot.calculerCoutKm());
        System.out.println("Voiture 2 : Couts plein " + taPeugot.calculerCoutPlein());
    
    }
    
}
