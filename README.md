# TP_Linux_embarqué
__Membres du binôme__  
Loïcia KOEHL  
Alix HAVRET 

## 1 - Prise en main 
### Préparation carte SD, connexion série et SSH avec la carte VEEK-MT2S
Dans un premier temps nous avons flashé la carte SD avec Win32DiskImager.  
Une fois la carte SD insérée dans la carte __VEEK-MT2S__ le démarrage c'est déroulé sans problème.  

Nous avons établit une première connexion, de type série tout d'abord, entre notre ordinateur et la carte afin de communicuqer avec elle. 
Dans un deuxième temps nous établissons, et c'est ce que nous utiliserons pour les TP suivant, une configuration en réseau. C'est à dire que nous allons connecter notre carte VEEK à un réseau spécifique et nous nous connecterons à la carte en SSH.  
La carte dispose d'une adresse IP, obtenu grace à la commande **ipconfig**, le tp suivant nous a fait remarqué que l'adresse IP changeait à chaque fois que nous nous reconnectons . 

Première adresse : 192.168.88.243  
Seconde adresse :192.168.88.226   
Troisième adresse :192.168.88.210 
Quatrième adresse :192.168.88.202

Une fois la connexion SSH établie et la découverte des fichiers bien entamée nous avons testé la compilation croisée avec un programme "Hello World".  

### Cross-compilation  

On compile notre programme dans la VM pour le processeur ARM donc le gcc est différent il faut mettre __arm-linux-gnueabihf-gcc hello.c -o hello.o__. Cela nous permet d'avoir un fichier executable.  Mais le programme une fois compilé sera executable sur le SoC mais pas sur la VM.  

Si on lance un gcc 'simple' sur la VM il sera executable sur la VM et pas sur le Soc. 
En effet le gcc de la liaison ssh est un gcc arm, on aurait pu compiler directement dessus mais c’est plus lent. 

Pour finir, on envoie sur le SoC le fichier compilé , donc on utilise la VM avec la commande suivante :  
scp <nomdufichier> root@<IP_VEEK>:~ (chemin ou le fichier sera placé dans le SoC)

### Chenillard 
  
  Wesh bas j'ai pas les codes   
  mais il est réussi :)  
  
## 2 - Modules kernel  
Je sais plus c'était quoi les codes ..
  
On lance le makefile qui crée le_module.ko.  
Une fois le module crée on le charge avec __sudo insmod le_module.ko__ et on envoie le message avec __sudo dmesg__ .  
Si le module a bien été crée et chargé alors s'affichent les messages émis par les modules 

### CrossCompilation de modules noyau 
  
  
  
### Chenillard
  
  
## 3 - Device tree
definition device tree : strcuture de données qui contient les composants qui seront utilisés par le système d'exploitation.  

  Dans un premier temps on modifie le fichier .dts en remplacant une 
  
  
  ### fichier gpio-leds 
  
  export CROSS_COMPILE=<chemin_arm-linux-gnueabihf-> 
  
  export ARCH=arm
  
  
  Rôles des fonctions : 
  
  __probe__ : la fonction permet d'allouer de la mémoire pour les leds, de bloquer les autres utilisateurs pour l'accès à cette mémoire et aussi d'allumer l'ensemble des leds.  
  
  __read__ : permet de lire le caractère donné pour LED et de la copier dans un registre adapté. Si la copie échoue, alors une erreur est envoyée. La fonction s'arrête quand l'ensemble des élèments ont été copié.  
  
  __write__ : permet de remplir la strcuture de données ensea_led_dev avec les données du fichier private_data,de manière sécurisée. On stock dans success la copie de ces valeurs, si success vaut 0 alors on écrit les données dans les registres pour mettre à jour la valeur des LEDS et donc programmer leur allumage. Elle renvoit ce que l'on a donnée en entrée si la fonctione c'est bien déroulée.  
  
  __remove__: Ecrit 0 dans chaque registre des LEDS, les LEDS s'éteignent toutes. Et supprime le dossier crée dans l'initialisation avec les valeurs choisies pour les LEDS.  
