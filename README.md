### RG137-kvadar-do-kvadrata

## Kvadar do kvadrata ![cuboid](https://i.ibb.co/5Mr9dKZ/kvadar.jpg)

Projekat je nastao na kursu Računarska grafika. Za implementaciju su korišćene biblioteke OpenGL i SOIL(za teksturu). Kao inspiracija poslužila je igrica Bloxorz.

## Instalacija i pokretanje :computer:

Da bi se program izvršavao na vašem računaru, potrebno je da: instalirate biblioteke OpenGL i SOIL ```sudo apt-get install binutils-gold freeglut3 freeglut3-dev libsoil-dev```, nakon ovoga treba preuzeti projekat sa github-a, raspakovati i preko terminala se pozicionirati u datoteku gde je smešten program, zatim izvršiti komandu ```make```. Program pokrenuti komandom:
```sh
./kvadar_do_kvadrata
```
## Opis

Cilj ove igrice, kao što i sam naziv kaže, je da se dođe do crnog kvadrata u prva dva nivoa i crvenog u poslednjem(znak da se došlo do kraja). Ovo se postiže pomeranjem kvadra po poligonu strelicama na tastaturi. U slučaju da igrač pomeri kvadar na polje van poligona, igrica prestaje sa radom i ispisuje se odgovarajuća poruka u terminalu.

## :diamond_shape_with_a_dot_inside: Kretanje i komande
Taster | Događaj  
----- | ------ 
<kbd>G</kbd> | pocetak igre
<kdb>:arrow_left:</kdbg> | kvadar se rotira u levo za 90<sup>o</sup>, ako kvadar stoji uspravno, u suprotnom se translira za jedno polje u levo
<kdb>:arrow_up:</kdbg> | kvadar se rotira na gore za 90<sup>o</sup>, ako kvadar stoji uspravno, u suprotnom<sup>*</sup>
<kdb>:arrow_right:</kdbg> | kvadar se rotira u desno za 90<sup>o</sup>, ako kvadar stoji uspravno, u suprotnom se translira za jedno polje u desno
<kdb>:arrow_down:</kdbg> | kvadar se rotira na dole za 90<sup>o</sup>, ako kvadar stoji uspravno, u suprotnom<sup>*</sup>
<kbd>Esc</kbd> | izlaz iz igre

*izuzetak kod kretanja pogledati na [linku](https://github.com/MATF-RG18/RG137-kvadar-do-kvadrata/tree/master/Pictures%20and%20videos/Videos)! 

## Dodatno
Izveštaji razvoja igrice se nalaze na [wiki](https://github.com/MATF-RG18/RG137-kvadar-do-kvadrata/wiki) stranici, a za bolji uvid probati samu igricu :wink:.
