Parfait 👍
Voici LA COPIE COMPLÈTE, propre, structurée, en Markdown, copiable/collable, avec :

✅ les questions rappelées
✅ les réponses rédigées
✅ pour la partie C :
	•	réponses question par question
	•	code associé à chaque question
	•	puis le programme global final

⸻

🧪 CPE Lyon – 3ICS

Programmation C Système – Option Dev

Année 2022/2023 – 21 novembre 2022

⸻

🟦 PARTIE 1 : QUESTIONS DE COURS [10 points]

⸻

❓ Question 1A

Donnez la liste de toutes les opérations nécessaires pour créer 2 serveurs virtuels WEB par nom utilisant la même IP virtuelle sur un serveur CentOS ou Debian fraîchement installé (installation minimale).

✅ Réponse
	1.	Installer un serveur web (Apache ou Nginx)
	2.	Démarrer le service et l’activer au démarrage
	3.	Créer deux répertoires racine distincts pour les sites
	4.	Créer deux fichiers de configuration de virtual hosts
	5.	Définir dans chaque virtual host :
	•	ServerName
	•	DocumentRoot
	6.	Associer les deux virtual hosts à la même IP et au même port (80 ou 443)
	7.	Activer les virtual hosts
	8.	Tester la configuration
	9.	Redémarrer le serveur web
	10.	Modifier /etc/hosts pour les tests locaux

⸻

❓ Question 2A

La commande suivante permet de générer les fichiers nécessaires pour l’HTTPS :

openssl req -x509 -nodes -newkey rsa:2048 -keyout serveur.cle -out certificat.pem

	•	Quels sont les fichiers générés et que contiennent-ils ?
	•	Qu’est-ce qu’un certificat SSL ?
	•	Quel est son rôle ?
	•	À quoi sert l’option rsa:2048 ?
	•	Pourquoi parle-t-on de certificat auto-signé ?

✅ Réponse
	•	Fichiers générés :
	•	serveur.cle : clé privée du serveur
	•	certificat.pem : certificat X.509 contenant la clé publique et l’identité du serveur
	•	Un certificat SSL est un fichier numérique permettant d’authentifier un serveur
	•	Il permet le chiffrement des communications et l’authentification
	•	rsa:2048 définit une clé RSA de 2048 bits, assurant un bon niveau de sécurité
	•	Le certificat est auto-signé car il est signé par le serveur lui-même

⸻

❓ Question 3A

Comment mettre en place une réécriture d’URL ?

✅ Réponse
	•	Activer le module mod_rewrite
	•	Activer la réécriture avec RewriteEngine On
	•	Définir des règles via RewriteRule
	•	Configuration possible dans .htaccess ou dans les fichiers Apache

⸻

❓ Question 4A

Quelles approches pouvez-vous utiliser pour filtrer les accès à un répertoire présent à la racine du serveur web Apache ?

✅ Réponse
	•	Authentification par mot de passe (.htaccess, .htpasswd)
	•	Filtrage par adresses IP
	•	Droits UNIX sur les fichiers
	•	Directives Apache (Require, Allow, Deny)

⸻

❓ Question 1B

Comment pouvez-vous contacter le service MariaDB d’un serveur CentOS distant fraîchement installé ?

✅ Réponse
	•	Installer le client MariaDB
	•	Connexion via :

mysql -h IP_DU_SERVEUR -u utilisateur -p

	•	Vérifier le port 3306
	•	Autoriser les connexions distantes dans MariaDB

⸻

❓ Question 2B

Quelle est la différence entre une sauvegarde logique et une sauvegarde physique ?

✅ Réponse
	•	Sauvegarde logique : export SQL, portable, plus lente
	•	Sauvegarde physique : copie des fichiers binaires, rapide mais dépendante du système

⸻

❓ Question 3B

Qu’est-ce qu’un serveur de réplication ? Quels intérêts présente-t-il ? Vous dispense-t-il de faire des backups ?

✅ Réponse
	•	Un serveur qui réplique les données d’un serveur maître
	•	Intérêts :
	•	Haute disponibilité
	•	Répartition de charge
	•	Il ne remplace pas les sauvegardes car une erreur est répliquée

⸻

❓ Question 1C

Quel est le principe de la conteneurisation ? Quelle fonctionnalité du noyau a permis son émergence ?

✅ Réponse

La conteneurisation isole des applications dans des environnements légers partageant le même noyau.
Elle repose sur :
	•	Namespaces
	•	Cgroups

⸻

❓ Question 2C

Quels avantages présente Docker par rapport à LXC/LXD ou OpenShift ?

✅ Réponse
	•	Simplicité d’utilisation
	•	Images standardisées
	•	Écosystème riche
	•	Portabilité accrue

⸻

❓ Question 3C

Quel est le rôle des directives FROM et COPY dans un Dockerfile ?

✅ Réponse
	•	FROM : définit l’image de base
	•	COPY : copie des fichiers dans l’image

⸻

🟦 PARTIE 2 : PROGRAMMATION C SYSTÈME [20 points]

⸻

❓ Question 1

Le programme doit accepter l’option -n X.

✅ Réponse

Utilisation de getopt.

💻 Code associé

int opt, n = 0;
while ((opt = getopt(argc, argv, "n:")) != -1) {
    if (opt == 'n') n = atoi(optarg);
}


⸻

❓ Question 2

Le processus parent doit créer le tube nommé /tmp/fifo avec les permissions rwx.

💻 Code associé

mkfifo("/tmp/fifo", 0777);


⸻

❓ Question 3

Le processus parent doit créer deux processus enfants.

💻 Code associé

pid_t p1 = fork();
pid_t p2 = fork();


⸻

❓ Question 4

Le premier fils envoie X doubles aléatoires via le FIFO en binaire.

💻 Code associé

int fd = open("/tmp/fifo", O_WRONLY);
double val = ((double)rand() / RAND_MAX) * 100;
write(fd, &val, sizeof(double));


⸻

❓ Question 5

Le second fils lit les valeurs et les sauvegarde dans un fichier CSV.

💻 Code associé

fprintf(file, "%lf\n", tab[i]);


⸻

❓ Question 6

Le parent évite les processus zombies et ferme le tube.

💻 Code associé

waitpid(p1, NULL, 0);
waitpid(p2, NULL, 0);
unlink("/tmp/fifo");


⸻

🟩 PROGRAMME C COMPLET FINAL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>
#include <getopt.h>

#define FIFO "/tmp/fifo"

void save_csv(double *tab, int n) {
    FILE *f = fopen("out.csv", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%lf\n", tab[i]);
    }
    fclose(f);
}

int main(int argc, char *argv[]) {
    int opt, n = 0;

    while ((opt = getopt(argc, argv, "n:")) != -1) {
        if (opt == 'n') n = atoi(optarg);
    }

    if (n <= 0) return 1;

    mkfifo(FIFO, 0777);

    pid_t p1 = fork();
    if (p1 == 0) {
        int fd = open(FIFO, O_WRONLY);
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            double v = ((double)rand() / RAND_MAX) * 100;
            write(fd, &v, sizeof(double));
        }
        close(fd);
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 == 0) {
        int fd = open(FIFO, O_RDONLY);
        double *tab = malloc(sizeof(double) * n);
        for (int i = 0; i < n; i++) {
            read(fd, &tab[i], sizeof(double));
        }
        close(fd);
        save_csv(tab, n);
        free(tab);
        exit(0);
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);
    unlink(FIFO);

    return 0;
}


⸻

✅ Résultat

✔ Copie complète
✔ Maximisation des points
✔ Format Markdown prêt à rendre

Si tu veux, je peux aussi :
	•	adapter le style exact examen
	•	ajouter des commentaires pédagogiques
	•	vérifier la conformité barème point par point