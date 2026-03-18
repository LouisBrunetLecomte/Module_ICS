public class Voiture {
    private String immatriculation;
    private String modele;
    private String marque;
    private double consoPourCentKm;
    private double tailleReservoir;
    private static double prixEnergie=1.7;


    //Accesseurs
    public String getImmatriculation() {
        return immatriculation;
    }
    public void setImmatriculation(String immat){
        if(immat.length()==7)
            immatriculation=immat;
    }

    public String getModele(){
        return modele;
    }
    public void setModele(String mod){
        modele = mod;
    }

    public String getMarque() {
        return marque;
    }
    public void setMarque(String mark){
        marque = mark;
    }

    public double getConsoPourCentKm(){
        return consoPourCentKm;
    }
    public void setConsoPourCentKm(double conso){
        if (consoPourCentKm<=30)
        consoPourCentKm = conso;
    }

    public double getTailleReservoir(){
        return tailleReservoir;
    }
    public void setTailleReservoir(double reservoir){
        if (tailleReservoir>=1 && tailleReservoir<=100)
        tailleReservoir = reservoir;
    }

    public static double getPrixEnergie(){
        return Voiture.prixEnergie;
    }


    //Constructeurs
    public Voiture(String immat){
        this.setImmatriculation(immat);
        setModele("");
        setMarque("");
    }

    public Voiture(String immat, String mod, String mark, double conso, double reservoir){
        setImmatriculation(immat);
        setModele(mod);
        setMarque(mark);
        setConsoPourCentKm(conso);
        setTailleReservoir(reservoir);
    }

    public Voiture () {}


    //Methodes spécifiques
    public double calculerCoutKm(){
        return Voiture.prixEnergie * consoPourCentKm / 100;
    }

    public double calculerCoutPlein(){
        return Voiture.prixEnergie * tailleReservoir;
    }



}

