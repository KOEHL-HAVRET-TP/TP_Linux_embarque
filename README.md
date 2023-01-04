# TP_Linux_embarqué
__Membres du binôme__  
Loïcia KOEHL  
Alix HAVRET 

## 1 - Prise en main 
Dans un premier temps nous avons flashé la carte SD avec Win32DiskImager.  
Une fois la carte SD insérée dans la carte __VEEK-MT2S__ le démarrage c'est déroulé sans problème.  

Nous avons établit une première connexion, de type série tout d'abord, entre notre ordinateur et la carte afin de communicuqer avec elle. 
Dans un deuxième temps nous établissons, et c'est ce que nous utiliserons pour les TP suivant, une configuration en réseau. C'est à dire que nous allons connecter notre carte VEEK à un réseau spécifique et nous nous connecterons à la carte en SSH.  
La carte dispose d'une adresse IP, obtenu grace à la commande **ipconfig**, le tp suivant nous a fait remarqué que l'adresse IP changeait à chaque fois que nous nous reconnectons . 

Première adresse : 192.168.88.243  
Seconde adresse :192.168.88.226   

Une fois la connexion SSH établie et la découverte des fichiers bien entamée nous avons testé la compilation croisée avec un programme "Hello World".  

__Principe de la cross-compilation :__   

On compile notre programme dans la VM pour le processeur ARM donc le gcc est différent il faut mettre __arm-linux-gnueabihf-gcc hello.c -o hello.o__. Cela nous permet d'avoir un fichier executable.  Mais le programme une fois compilé sera executable sur le SoC mais pas sur la VM.  

Si on lance un gcc 'simple' sur la VM il sera executable sur la VM et pas sur le Soc. 
En effet le gcc de la liaison ssh est un gcc arm, on aurait pu compiler directement dessus mais c’est plus lent. 

Pour finir, on envoie sur le SoC le fichier compilé , donc on utilise la VM avec la commande suivante :  
Scp <nomdufichier> root@<IP_VEEK>:~ (chemin ou le fichier sera placé dans le SoC)


## 2 - 

## 
IP de notre carte : 

