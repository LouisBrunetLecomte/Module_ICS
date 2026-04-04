# Rendu code exercice 3.2B

fichier main.java : 
```java
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
````


fichier Vehicule.java : 
```java
public abstract class Vehicule {
    private String nom;

    public Vehicule(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return this.nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }
}
````

fichier Aquatique.java : 
```java
public abstract class Aquatique extends Vehicule {

    public Aquatique(String nom) {
        super(nom);
    }
}
````

fichier Terrestre.java : 
```java
public abstract class Terrestre extends Vehicule {

    public Terrestre(String nom) {
        super(nom);
    }
}
````

fichier Velo.java : 
```java
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
````

fichier voiture.java : 
```java
public class Voiture extends Terrestre implements Rouler, Transporter {

    public Voiture(String nom) {
        super(nom);
    }

    @Override
    public void rouler() {
        System.out.println(this.getNom() + " roule.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " transporte des passagers.");
    }
}
````

fichier SousMarin.java : 
```java
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
````

fichier Voilier.java : 
```java
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
````

fichier Rouler.java : 
```java
public interface Rouler {
    void rouler();
}
````

fichier Transporter.java : 
```java
public interface Transporter {
    void transporter();
}
````

fichier NaviguerProfondeurs.java : 
```java
public interface NaviguerProfondeurs {
    void naviguerProfondeurs();
}
````

fichier NaviguerSurface.java : 
```java
public interface NaviguerSurface {
    void naviguerSurface();
}
````