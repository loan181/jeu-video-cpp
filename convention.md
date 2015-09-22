# Conventions d'écriture des fichiers de texte

## Remarques préliminaires
Les chapitres suivants seront structurés de la manière suivante
  - _Titre_
  - _Explications et syntaxe_
  - _Structure_
  - _Exemple_ (potentiellement)

La partie _Structure_ a la syntaxe suivante : texte en `zone de code`. Certains arguments sont optionels et indiqués entre-parenthèses `(`, `)`.  
Par exemple la structure suivante : `(Bonjour. )J'aime les petits chats( noirs).( Au revoir.)` peut être interprétée comme :
  - Bonjour. J'aime les petits chats.
  - J'aime les petits chats.
  - Bonjour. J'aime les petits chats noirs. Au revoir.
  - etc.

## Textes de base
Chaque texte du jeu sera d'abord marqué par une chaine de caractère `lab qui seras utilisée comme label du texte. Le label sera écrit en miniscules et comportera un seul mot (ou groupe de mots séparés par des '_'), dois être **UNIQUE** pour le fichier de texte courant et ne PAS utiliser les autres caractères de conventions (`:`, `{`, `}`, `|`, `[`, `]`, `$`, `~`). 
Le label sera suivi de `:` indiquant sa fin. Puis le texte (chaine de caractère).

Stucture: `lab:texte`.

Exemple: `retour_nuit:Je suis rentré à la maison une fois la nuit tombée.`

A la fin du texte, la ligne suivante est lue par défaut (sauf indication contraire)

## Texte à question ouverte
Un texte peut eventuellement comporter un choix pour l'utilisateur. Les choix doivent être compris entre-accolades `{`, `}` et séparés par la barre verticale `|`.

Structure: `lab:(texte){choix1|choix2|...|choixN}(texte)`.

Exemple: `embranchement:Un embranchement s'offre à moi, où dois-je aller? {A gauche|A droite|En avant|En arrière}`

## Avis de redirection
La plupart des questions ouvertes donnent (en général) lieu à un autre texte que celui de la prochaine ligne. Pour indiquer quelle est la ligne à executer en fonction de son choix il faut indiquer le label du prochain texte à lire entr crochets `[`, `]`. 

Structure: `lab:(texte){choix1[lab1]|choix2[lab2]|...|choixN[labN]}(texte)`

Un texte sans question ouverte peut également comporter une redirection en utilisant les crochets.

Structure: `lab:texte[lab_d'arrivée]`

Exemple: 
```
embranchement:Un embranchement s'offre à moi, où dois-je aller? {A gauche[cul_de_sac]|A droite[embranchement_droite]|En avant[cul_de_sac]}
embranchement_droite: Oh, Un loup! A l'attaque![attaque_loup]
cul_de_sac: Rien par ici... Demi-tour[embranchement]
```

## Acces à d'autres fichier textes
Tout les textes n'étant pas compris au sein du même fichier texte, pour accéder à un autre fichier texte il faut écrire le fichier cible, le caractère slash `@` et le label voulu dans ce fichier cible.

Structure: `lab:(texte)[fichier_texte_cible@lab_cible]` 

En cas d'absence de label, le fichier texte ciblé sera choisi comme répertoire courant......

## Utlisitions des variables du jeu
Un texte peut inclure une variable intégrante du jeu. Pour cela il devra l'indiquer entre deux symboles dollar `$`.

Structure: `lab:(texte)$var$(texte)`  
Exemple: `debut: Bonjour $name$ comment vas-tu ce matin?`

## Textes non-redondant
Afin d'éviter toute répétition dans un même dialogue qui serait appelé plusieurs fois, il est posible d'écrire le même texte differemment et séparer par les possibilités `~` dans ce même texte. Un des textes séparé par ce symbole sera choisi aléatoirement lors de la lecture de la ligne lors du jeu.

Structure: `lab:texteA(~texteB(~texteC(~texteD...)))`  
Exemple: `matin:Ouhlala j'ai bien dormi moi.~C'est l'heure de se lever !~Quoi déjà ? Allez hop !`

Il peut, également être inclus dans les choix des textes à question ouverte. (Elles auront toutes le même avis de redirection)

Structure: `lab:(texte){choix1A(~choix1B(~choix1C)...)[lab1]|...|choixNA(~choixNB(~choixNC)...)[labN]}(texte)`
