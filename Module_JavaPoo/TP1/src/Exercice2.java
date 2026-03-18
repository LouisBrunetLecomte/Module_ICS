import java.util.Random;

public class Exercice2{
    public static void main(String[] args) {
        int nbTentatives=0;
        int nb1;
        int nb2;
        int nb3;

        Random rd= new Random();

        do {
            
            nb1 = rd.nextInt(1000);
            nb2 = rd.nextInt(1000);
            nb3 = rd.nextInt(1000);
            nbTentatives ++;

        } while (nb1%2==1 || nb2%2==1 || nb3%2==0);        
        System.out.println(nb1);
        System.out.println(nb2);
        System.out.println(nb3);
        System.out.println("Voici le nombre de tentatives :" + nbTentatives);
    }
}



