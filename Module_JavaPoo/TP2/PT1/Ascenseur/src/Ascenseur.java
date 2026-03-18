public class Ascenseur {
    private int etageMin;
    private int etageMax;
    private int etageCourant;

    //Accesseurs
    public int getetageMin(){
        return etageMin;
    }
    public void setetageMin(int etageMinimum){
        if (etageMin < -10) {
            etageMin = -10;
        }
        else etageMin = etageMinimum;
    }

    public int getetageMax(){
        return etageMax;
    }
    public void setetageMax(int etageMaximum){
        if (etageMax > 50) {
            etageMax = 50;
        } else etageMax = etageMaximum;
    }    

    public int getetageCourant(){
        return etageCourant;
    }
    public void setetageCourant(int etageC){
        if (etageCourant > etageMax) {
            etageCourant = 0;
        } 
        else if (etageCourant < etageMin) {
            etageCourant = 0;
        }
        else if (etageCourant == etageC) {
            etageCourant = etageC;
        }
    }  

    public static String avertisseur = "Ding";

    public void avertit(){
        System.out.println(avertisseur);
    }
    public boolean etageValide (int etage){
        return etage >= etageMin && etage <= etageMax;
    }

    public void va(int etageCible) {
        while (etageCible != etageCourant) {
            if (etageCible > etageCourant) {
                etageCourant = etageCourant + 1;
                System.out.println(etageCourant);
            }
            else if (etageCible < etageCourant) {
                etageCourant = etageCourant -1;
                System.out.println(etageCourant);
            }
            else {
                System.out.println("Vous êtes au bon étage! L'étage " + etageCourant);
            }
        }
    }


    //Constructeurs
    public Ascenseur() {}

    public Ascenseur(int etageMin, int etageMax){
        setetageMin(etageMin);
        setetageMax(etageMax);
    }

    //Methodes spécifiques
    public static String avertisseur(){
        return "Ding";
    }
    
}