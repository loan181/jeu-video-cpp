##Convention d'écriture du fichier texts.txt:

### Remarque préliminaire:
Les chapitres suivant seront strucutré de la manière suivante:
  - _Titre_
  - _Explications et syntaxe_
  - _Structure_
  - _Exemple_ (potentiellement)

La _Structure_ à la syntaxe suivante : texte en `zone de code`. Certain argument sont optionels et indiqués entre-parenthèses `(` `)`.  
Par exemple la structure suivante : `(Bonjour. )J'aime les petits chats( noirs).( Au revoir.)`, peut être interprétée comme :
  - Bonjour. J'aime les petits chats.
  - J'aime les petits chats.
  - Bonjour. J'aime les petits chats noirs. Au revoir.
  - etc...

L'utilisation des points de suspenssions `...` signifie la potentielle répétition de la dernière séquence autant de fois que souhaité.

### Textes de base:
Chaque texte du jeu seras d'abord marqué par une chaine de caractère _lab_ qui seras utiliser comme label du texte. Le label comportera un seul mot (potentiellement séparé par des '_'),dois être UNIQUE pour le fichier de texte courant et ne PAS utiliser les autres caractères de conventions (`:`, `{`, `}`, `|`, `[`, `]`, `$`, `~`).  
Le label sera suivi de `:` indiquant sa fin. Puis le texte (chaine de caractère).

Stucture: `lab:texte`.  
Exemple: `retour_nuit:Je suis rentré à la maison une fois la nuit tombée.`

A la fin du texte, la ligne suivante est lue par défaut (sauf indication contraire)


### Textes à question ouverte:
Un texte peut eventuellement comporté un choix à l'utilisateur. Les choix doivent être compris entre-accolades `{ }` et séparés par la barre verticale `|`.

Structure: `lab:(texte){choix1|choix2|...|choixN}(texte)`.  
Exemple: `embranchement:Un embranchement s'offrai à moi, ou dois-je aller? {A gauche|A droite|En avant|En arrière}`

### Avis de redirection:
La plupart des question ouvertes ouvrent (en général) lieu à un autre texte que celui de la prochaine ligne, pour indiquer quelle est la ligne à executere en fonction de son choix il faut indiquer le label du prochain texte à lire entre-crochets `[` `]`. 

Structure: `lab:(texte){choix1[lab1]|choix2[lab2]|...|choixNlabN}(texte)`

Un texte sans questions ouvertes peut également comporter une redirection en utilisant les crochets.

Structure: `lab:texte[lab_d'arrivée]`

Exemple: 
```
embranchement:Un embranchement s'offrai à moi, ou dois-je aller? {A gauche[cul_de_sac]|A droite[embranchement_droite]|En avant[cul_de_sac]}
embranchement_gauche: Oh, Un loup! A l'attaque![Attaque_loup]
cul_de_sac: Rien par ici... Demi-tour[embranchement]
```

### Utlisitions des variables du jeu:
Un texte peut inclure une variable intégrante du jeu. Pour cela il devra l'indiquer entre deux symboles dollar `$`.

Structure: `lab:(texte)$var$(texte)`  
Exemple: `debut: Bonjour $name$ comment vas-tu ce matin?`

### Textes non-redondant:
Afin d'éviter toute répétitions dans des textes. Ecrire le même texte differemment et séparer par `~`. Un des textes séparé par ce symbole sera choisi aléatoirement lors de la lecture de la ligne.

Structure: `lab:texteA(~texteB(~texteC(~texteD...)))`  
Exemple: `matin:Ouhlala j'ai bien dormi moi.~C'est l'heure de se lever!~Quoi déjà? Allez hop!`

Et peut, également être inclus dans les choix des textes à questions ouvertes. (Elles auront toutes le même avis de redirection)

Structure: `lab:(texte){choix1A(~choix1B(~choix1C)...)[lab1]|...|choixNlabN(~choixNB(~choixNC)...)}(texte)`



REMARQUE POUR ROBIN:
 - Est ce mieux de remplacer le caractère suivant un label par `#` vue que `:` seras potentiellement utilisé dans le texte?
 - Est-ce pas trop dure à implémenter la partie de non-redondance ?
