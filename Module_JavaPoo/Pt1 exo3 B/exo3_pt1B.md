# Rendu code exercice 3.1B : 

Je voulais vous rendre mon travail sous forme de zip mais Moodle ne m'y authorisait pas. J'ai voullu vous le rendre un fichier par un fichier mais Moodle n'acceptait que un seul fichier. J'ai voullu vous le rendre en .md mais on n'avait pas le droit non plus. Je vous le rend donc dans le txt, j'espere que ça restera lisible pour vous. 
Louis

fichier main.java : 
```java
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

        Dragon dragon = new Dragon("MangesMoutons");
        dragon.voler();
        dragon.marcher();
        dragon.crier();
    }
}
```



fichier  Animal.java : 
```java
public abstract class Animal {
    private String nom;

    public Animal(String nom) {
        this.nom = nom;
    }

    public String getNom() {
        return this.nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }
}
```


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

```


fichier Avion.java : 
```java
public class Avion extends Vehicule implements Voler, Transporter {

    public Avion(String nom) {
        super(nom);
    }

    @Override
    public void voler() {
        System.out.println(this.getNom() + " peut voler.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " peut transporter des personnes ou chargements.");
    }
}
```

fichier Bateau.java : 
```java
public class Bateau extends Vehicule implements Naviguer, Transporter {

    public Bateau(String nom) {
        super(nom);
    }

    @Override
    public void naviguer() {
        System.out.println(this.getNom() + " peut naviguer sur l'eau ou rester a quai.");
    }

    @Override
    public void transporter() {
        System.out.println(this.getNom() + " peut transporter des personnes ou chargements.");
    }
}
```


fichier Cri.java : 
```java
public interface Cri {
    void crier();
}
```


fichier Dragon.java : 
```java
public class Dragon extends Animal implements Voler, Marcher, Cri {

    public Dragon(String nom) {
        super(nom);
    }

    @Override
    public void voler() {
        System.out.println(this.getNom() + " vole.");
    }

    @Override
    public void marcher() {
        System.out.println(this.getNom() + " marche.");
    }

    @Override
    public void crier() {
        System.out.println(this.getNom() + " rugit.");
    }
}

```


fichier Lion.java : 
```java
public class Lion extends Animal implements Marcher, Cri {

    public Lion(String nom) {
        super(nom);
    }

    @Override
    public void marcher() {
        System.out.println(this.getNom() + " marche.");
    }

    @Override
    public void crier() {
        System.out.println(this.getNom() + " rugit.");
    }
}

```


fichier Marcher : 
```java
public interface Marcher {
    void marcher();
}
```


fichier Naviguer.java : 
```java
public interface Naviguer {
    void naviguer();
}

```


fichier Transporter.java : 
```java
public interface Transporter {
    void transporter();
}
```


fichier Voler.java : 
```java
public interface Voler {
    void voler();
}
```
