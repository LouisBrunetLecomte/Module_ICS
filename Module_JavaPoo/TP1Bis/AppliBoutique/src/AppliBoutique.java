public class AppliBoutique {
    public static void main(String[] args) throws Exception {
        Produit produit = new Produit("Clavier Mécanique", 
        "ELECTRONIQUE", 
        59.99);
        System.out.println(produit.toString());

        Produit produit2 = new Produit("Pommes", 
        "ALIMENTAIRE", 
        1.50);
        System.out.println("Voici le prix des frais de ports pour les pommes, pour 2Kg cela vas vous couter : " + produit2.calculerFraisDePort(2) + "€");
    }
}
