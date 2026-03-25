import java.time.LocalDate;

public class ProgPrincipal {
    public static void main(String[] args) { 
        Article MonArticle = new Article("TINTINN01", "Tintin au congo", 13.50);
        System.out.println(MonArticle); 

        Article MonArticle2 = new Article("TINTINN02", "Le crabe aux pinces d'or", 15.50);
        System.out.println(MonArticle2); 
        
        Personne herge = new Personne("Hergé", "R", LocalDate.of(2000,1,1));
        livre MonLivre = new livre("TINTIN03", "Tintin au pays des Soviets", 8.5,"?", 96, herge);
        System.out.println(MonLivre);

        Personne Gorges = new Personne("claude", "R", LocalDate.of(2000,12,12));
        dvd MonDvd = new dvd("DVD01", "La soupe aux choux", 19.5, 98, Gorges);
        System.out.println(MonDvd);
    }
}