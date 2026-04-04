public class Main {
    public static void main(String[] args) {

        Bateau bateau = new Bateau("CouleAPic");
        bateau.naviguer();
        bateau.transporter();

        Avion avion = new Avion("Boeing 747");
        avion.voler();
        avion.transporter();

        Lion lion = new Lion("Depay"); // Ex joueur de l'ol qui a, comme vous le savez, un Lyon tatoué dans le dos
        lion.marcher();
        lion.crier();

        Dragon dragon = new Dragon("Rhaegal");
        dragon.voler();
        dragon.marcher();
        dragon.crier();
    }
}
