# Rendu tp D

**[2A] A quoi correspondent ces périphériques ?**<br>
Ces fichiers correspondent à des périphériques spéciaux de type caractère fournis par le noyau Linux.
Ils ne représentent pas de matériel réel, mais donnent accès à certaines fonctionnalités internes du système. 
- /dev/null : c'est la poubelle globalement, supprime les éléments qui s'y trouvent.
- /dev/zero : fournit un flux d’octets nuls
- /dev/random et /dev/urandom : générations de données aléatoires.
- /dev/loop0 : périphérique loop, permet de traiter un fichier comme un disque.<br>

**[2B] En utilisant les fonctions open (man 3 open ) et read (man 3 read), écrivez un programme qui affiche un nombre aléatoire sur un int.**<br>


<br><br>


**[4A] A quoi correspondent les répertoires nommés par des numéros ?**<br>
Chaque dossier numérique = un processus actif identifié par son PID.<br>

**[4B] A quoi correspond le fichier cmdline a l’intérieur d'un de ces répertoires ?**<br>
Le fichier cmdline contient la ligne de commande complète utilisée pour lancer le processus correspondant.
Il inclut le nom du programme ainsi que tous les arguments passés lors de son exécution.<br>

**[4C] A quoi correspond le fichier cwd a l’intérieur d'un de ces répertoires ?**<br>
Le fichier cwd est un lien symbolique qui pointe vers le répertoire de travail courant (current working directory) du processus.<br>

**[4D] A quoi correspond le fichier exe a l’intérieur d'un de ces répertoires ?**<br>
Le fichier exe est un lien symbolique qui pointe vers le fichier exécutable du processus.
Il indique exactement quel programme est en train d’être exécuté par ce PID.<br>

**[4E] A quoi correspond le fichier root a l’intérieur d'un de ces répertoires ?**<br>
Le fichier root est un lien symbolique vers le répertoire racine vu par le processus.
Il correspond à la racine effective du système de fichiers pour ce processus (utile en cas de chroot).

**[4F] Que contient le fichier /proc/devices ?**<br>
Le fichier /proc/devices liste tous les types de périphériques enregistrés dans le noyau, classés en :
- périphériques caractère
- périphériques bloc

Chaque entrée indique leur numéro majeur et leur nom.<br>

**[4G] Que pouvez vous dire du répertoire /proc/self ?**<br>
/proc/self est un lien symbolique spécial qui pointe vers le répertoire /proc/<PID> du processus qui effectue la lecture.<br>


<br><br>


**[6A] Pourquoi peut-on avoir besoin de verrouiller un fichier en écriture ?**<br>
On verrouille un fichier en écriture pour éviter que plusieurs processus écrivent en même temps dans le même fichier, le verrou garantit qu’un seul processus à la fois peut écrire dans le fichier.

**[6B] Programme qui écrit des valeurs aléatoires dans un fichier + verrou d’écriture**<br>


<br><br>


**[8A] En utilisant les fonctions précédentes, créez un programme qui affiche la taille cumulée de tous les fichiers contenus dans un répertoire.**<br>


<br><br>


**[9A] Quelles sont les différentes valeurs (avec leurs symboles) possibles pour le paramètre flags ?**<br>
- O_RDONLY : lecture seule
- O_WRONLY : écriture seule
- O_RDWR : lecture + écriture
- O_CREAT : crée le fichier s’il n’existe pas
- O_EXCL : échoue si le fichier existe déjà
- O_TRUNC : tronque le fichier à 0 si existant
- O_APPEND : écrit à la fin du fichier
- O_NONBLOCK : opérations non bloquantes
- O_SYNC, O_DSYNC, O_RSYNC : synchronisation des écritures/lectures
- O_NOFOLLOW : ne pas suivre les liens symboliques
- O_DIRECTORY : vérifie que c’est un répertoire
- O_CLOEXEC : ferme le descripteur lors d’un exec()<br>

**[9B] Que permet de faire le paramètre mode ?**<br>
Détermine les permissions du fichier créé lorsque O_CREAT est utilisé.

**[9C] En utilisant les fonctions précédentes, écrire un programme qui sauvegarde la valeur 19496893802562113L dans un fichier binaire. Ouvrez le fichier. Qu'observez-vous ?**<br>
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    long val = 19496893802562113L;
    int fd = open("val.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, &val, sizeof(long));
    close(fd);
    return 0;
}
```
<br>

**[9D] Créez un programme qui enregistre la valeur 0x4142434451525354L dans un fichier, en utilisant les fonctions précédentes. Affichez la valeur avec un printf en décimal et hexadécimal ? Que contient le fichier binaire ?**<br>
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    long val = 0x4142434451525354L;
    int fd = open("val2.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, &val, sizeof(long));
    close(fd);

    printf("Décimal : %ld\nHex : 0x%lX\n", val, val);
    return 0;
}
```
Décimal affiché : 4702394921427288788
Hexadécimal affiché : 0x4142434451525354
Contenu du fichier binaire : représentation binaire sur 8 octets, non lisible comme du texte.
<br>

**[9E] Enregistrez la valeur précédente dans un fichier en utilisant la fonction fprintf. Que constatez-vous ?**<br>
```c
#include <stdio.h>
int main() {
    FILE *f = fopen("val3.txt", "w");
    long val = 0x4142434451525354L;
    fprintf(f, "%ld\n", val);
    fclose(f);
    return 0;
}
```
<br>

**[9F] Quelle est la différence essentielle entre un fichier binaire et un fichier texte ?**<br>
Fichier binaire : 
- Plus rapide à lire/écrire pour le programme
- Taille fixe selon le type 
- Données codées directement en mémoire

fichier txt : 
- Données codées en caractères lisibles
- Taille variable selon représentation ASCII
- Lisible par l’homme
<br>

**[9G] Que pouvez-vous dire du principe 'little endian' et 'big endian' ?**<br>
little endian : ordre d'octets dans lequel l'octet le moins significatif est stocké à l'adresse mémoire la plus basse.<br>
big endian : ordre d'octets dans lequel l'octet le plus significatif est stocké à l'adresse mémoire la plus basse.<br>

**[9H] A quelle groupe appartiennent les processeurs de la famille des Intel/AMD ?**<br>
little endian

**[9I] Donnez un modèle de processeur appartenant a l'autre groupe.**<br>
- Motorola 68000
- les SPARC (Sun Microsystems) 
- System/370 (IBM)

**[9J] Il existe d'autres fonctions permettant de lire et d’écrire dans un fichier, qui sont respectivement fread et fwrite. Quelles sont les différences entre read et fread ou write et fwrite ?**<br>
- fread : permet de lire un certain nombre d'octets à partir d'un flux
- fwrite : permet d'écrire un certain nombre d'octets vers le flux spécifié en quatrième paramètre, il faut jouer sur deux paramètres : le nombre de bloc d'octets à lire ainsi que la taille de chacun des blocs.

Les différences entre read et fread ou write et fwrite sont que pour read/write, tout se passe sur descripteurs de fichiers (int) au niveau systeme (bas niveau) et que ils sont non bufferisés par défaults. Pour fread/fwrite, lui est bufferisé par la librairié stdio et qu'il est plus pratique d'usage pour les fichiers en binaire ou en txt.<br>

**[9K] Quelles informations importantes pouvez vous tirer du code précédent ?**<br>
Il y a la présence d'un buffer pour optimiser la lecture/écriture. Et le code contient le descripteur de fichier (fd). C'est tout...

**[9L] En utilisant fwrite, écrire un programme qui enregistre 100 valeurs (de 0 a 100) de type int en binaire dans un fichier et les affiche simultanément. Que pouvez vous observer dans le fichier ?**<br>


**[9M] Écrire un second programme qui lit les valeurs précédentes du fichier et les affiche ?**<br>


<br><br>


**[10A] Écrivez un programme qui enregistre les valeurs de 10 a 30 dans un fichier binaire.**<br>

**[10B] Votre programme doit ensuite relire les données stockées a raison d’une valeur sur trois (vous devez utiliser lseek)**<br>

**[10C] Maintenant votre programme doit, en plus, lire la 5ieme valeur enregistrée dans le fichier.**<br>


<br><br>


**[11A] Créez un tableau de 4 « Personne »**<br>

**[11B] Affichez les données stockées dans les structures (nom, age et poids de chaque « Personne »)**<br>

**[11C] Créez une fonction qui sauvegarde le contenu du tableau dans un fichier binaire.**<br>

**[11D] Créez une fonction qui lit les données du fichier précédent et les affiche au fur et à mesure de la lecture. Vous devez bien sur retrouver les données qui étaient stockées dans les structures.**<br>

**[11E] Créez une fonction qui lit les données du fichier précédents et les stocke dans un tableau de « Personne »**<br>

**[11F] Même exercice que précédemment (reprenez toutes les questions), mais cette fois avec la structure suivante :**<br>