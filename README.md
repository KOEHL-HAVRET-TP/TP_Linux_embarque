
# <div align="center">TP_Linux_embarqué</div> 

__Membres du binôme__  
Loïcia KOEHL  
Alix HAVRET 

# 1 - Prise en main 
## Préparation carte SD, connexion série et SSH avec la carte VEEK-MT2S.    
__Carte VEEK-MT2S__ : kit de développement tout-en-tout pour l'embarqué avec système d'exploitation Linux (dans notre cas).

Dans un premier temps nous avons flashé la carte SD avec Win32DiskImager.  
Une fois la carte SD insérée dans la carte __VEEK-MT2S__ le démarrage c'est déroulé sans problème.  

Nous avons établit une première connexion, de type série tout d'abord, entre notre ordinateur et la carte afin de communiquer avec elle. 
Dans un deuxième temps nous établissons, et c'est ce que nous utiliserons pour les TP suivant, une configuration en réseau. C'est à dire que nous allons connecter notre carte VEEK à un réseau spécifique et nous nous connecterons à la carte en SSH.  
La carte dispose d'une adresse IP, obtenu grace à la commande **ipconfig**.   
L'adresse IP changeait à chaque reconnexion au réseau.

Première adresse : 192.168.88.243  
Seconde adresse :192.168.88.226   
Troisième adresse :192.168.88.210  
Quatrième adresse :192.168.88.202  
Cinquième adresse : 192.168.88.192  
Sixième adresse : 192.168.88.187  
Septième adresse : 192.168.88.175  

Une fois la connexion SSH établie et la découverte des fichiers bien entamée nous avons testé la compilation croisée avec un programme "Hello World".  

## Cross-compilation  

On compile notre programme dans la VM pour le processeur ARM donc le gcc est différent il faut mettre __arm-linux-gnueabihf-gcc hello.c -o hello.o__. Cela nous permet d'avoir un fichier executable.  Mais le programme une fois compilé sera executable sur le SoC mais pas sur la VM.  

Si on lance un gcc 'simple' sur la VM il sera executable sur la VM et pas sur le Soc. 
En effet le gcc de la liaison ssh est un gcc arm, on aurait pu compiler directement dessus mais c’est plus lent. 

Pour finir, on envoie sur le SoC le fichier compilé , donc on utilise la VM avec la commande suivante :  
__scp <nomdufichier> root@<IP_VEEK>:~ (chemin ou le fichier sera placé dans le SoC)__  

Lignes à lancer avant chaque cross- compilation sur la VM :  
__export CROSS_COMPILE=/usr/bin/arm-linux-gnueabihf-__  
__export ARCH=arm__  

__export__ : nous permet de déclarer notre variable dans l'ensemble des environnements à notre disposition.  

  
## Chenillard TP1  
 Le premier chenillard a été réalisé en allant modifier les fichiers __brightness__ des différentes LEDS directement à la source. Ce dernier a été réussi. 
  
# 2 - Modules kernel  
Nous utiliserons des modules, des morceaux de code qui peuvent être chargés et déchargés dans le noyau à la demande.  
Afin de lancer nos modules, on crée un Makefile pour créer notre exécutable.  

Une fois le module créé on le charge avec __sudo insmod le_module.ko__ et on envoie le message avec __sudo dmesg__ .  
Si le module a bien été crée et chargé alors s'affichent les messages émis par les modules.
Pour lancer les modules sur la carte VEEK on applique le principe de la cross-compilation détaillé plus haut, avec l'envoi du fichier .ko sur la VEEK.  

Le chenillard réalisé dans ce TP sera détaillé à la fin car nous sommes partis de la même base.  
  
# 3 - Device tree

__Definition device tree__ : structure de données qui contient les composants qui seront utilisés par le système d'exploitation.   
  
  ## fichier gpio-leds 
 
  Rôles des fonctions : 
  
  __probe__ : la fonction permet d'allouer de la mémoire pour les leds, de bloquer les autres utilisateurs pour l'accès à cette mémoire et aussi d'allumer l'ensemble des leds.  
  
  __read__ : permet de lire le caractère donné pour LED et de la copier dans un registre adapté. Si la copie échoue, alors une erreur est envoyée. La fonction s'arrête quand l'ensemble des élèments ont été copié.  
  
  __write__ : permet de remplir la strcuture de données ensea_led_dev avec les données du fichier private_data,de manière sécurisée. On stock dans success la copie de ces valeurs, si success vaut 0 alors on écrit les données dans les registres pour mettre à jour la valeur des LEDS et donc programmer leur allumage. Elle renvoit ce que l'on a donnée en entrée si la fonctione c'est bien déroulée.  
  
  __remove__: Ecrit 0 dans chaque registre des LEDS, les LEDS s'éteignent toutes. Et supprime le dossier crée dans l'initialisation avec les valeurs choisies pour les LEDS.  



## TP final 

Dans fonction script_pattern_write  
Dans l'exucution on met un décimal (un entier), il va être récupéré, puis avec atoi on trasnforme notre chaine de caractère obtenu en entier, cet entier est ensuite transformé en decimal .  



## Annexes : Commande complémentaire 
%x = affichage en hexa
%2x = affichage en hexa mais forcer pour avoir 2 caractères 
  
