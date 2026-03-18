import java.time.Duration;
import java.time.OffsetDateTime;
import java.time.OffsetTime;
import java.util.Random;
import java.util.Scanner;

public class Exercice5 {
    public static void main(String[] args) {
        OffsetTime now = OffsetTime.now();
        Scanner sc; 
        sc=new Scanner(System.in);
        int nb1;
        int nb2;
        Random rd= new Random();
        nb1 = rd.nextInt(1000);
        // System.out.println(nb1);
        do {
            System.out.println("Rentrez le bon nombre :");
            nb2=sc.nextInt();
            if (nb1 < nb2) {
                System.out.println("X est plus petit");
            };
            if (nb1>nb2) {
                System.out.println("X est plus grand");
            };

        } while (nb1!=nb2);
        System.out.println("C'étais le bon nombre !");
        sc.close();
        OffsetTime end = OffsetTime.now();
        Duration temps_écoulé = Duration.between(now, end);
        long secondes = temps_écoulé.getSeconds();
        System.out.println("Vous avez mis "+ secondes+ " secondes.");
    }
}
