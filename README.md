# Get Next Line

**Get Next Line** est un projet de l'école 42 qui consiste à développer une fonction en C capable de lire une ligne depuis un descripteur de fichier. Ce projet introduit également l'utilisation des variables statiques pour la gestion de données persistantes.

---

## 📝 Description du Projet

L'objectif principal est de coder la fonction `get_next_line` pour lire une ligne à la fois depuis un fichier ou l'entrée standard. Ce projet met l'accent sur :

- La gestion des descripteurs de fichier.
- L'utilisation de buffers pour optimiser les lectures.
- Le traitement des variables statiques pour conserver un état entre plusieurs appels.

#### 🔑 Notions Clés

- Gestion dynamique de la mémoire (`malloc`, `free`).
- Lecture efficace depuis un descripteur avec `read`.
- Gestion des variables statiques pour préserver des données entre plusieurs appels.
- Respect des normes de code imposées par l'école 42.

---

## 📋 Structure du Projet

### 1. Partie Obligatoire

La fonction `get_next_line` doit :

- Lire une ligne depuis un descripteur de fichier (`fd`).
- Retourner la ligne lue, y compris le caractère `\n` s'il est présent.
- Retourner `NULL` en cas de fin de fichier ou d'erreur.

**Fichiers à rendre** :

- `get_next_line.h` : Contient le prototype de la fonction et les macros nécessaires.
- `get_next_line.c` : Implémente la fonction principale.
- `get_next_line_utils.c` : Contient les fonctions auxiliaires nécessaires.

**Fonctions externes autorisées** :  
`read`, `malloc`, `free`.

### 2. Partie Bonus

Les bonus incluent :

- Une gestion multiple des descripteurs de fichier (lecture alternée sans perte de données).
- Une implémentation avec une seule variable statique.

**Fichiers supplémentaires pour les bonus** :

- `get_next_line_bonus.h`
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`

Les bonus ne seront évalués que si la partie obligatoire est **parfaitement fonctionnelle**.

---

## ⚙️ Instructions d'Utilisation

- **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/0x2Anessie/42-GetNextLine.git
   ```
   ```bash
   cd 42-GetNextLine
   ```
- **Creer 3 fichiers : `texte1.txt`, `texte2.txt` et `texte3.txt`.**

- **Les remplir de texte contenant des retours a la ligne.**

### Partie Obligatoire

1. **Tester le programme :**
   - Ouvrir le fichier get_next_line.c et utiliser le main mis en commentaire pour tester le programme.
  
2. **Lancer le programme et le tester avec un `fd` :**
   ```bash
   gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl_test
   ```
   ```bash
   ./gnl_test texte1.txt
   ```

### Partie Bonus

1. **Tester le programme :**
   - Ouvrir le fichier get_next_line_bonus.c et utiliser le main mis en commentaire pour tester le programme.

2. **Lancer le programme et le tester avec plusieurs `fd` :**
   ```bash
   gcc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_test
   ```
   ```bash
   ./gnl_bonus_test texte1.txt texte2.txt texte3.txt
   ```

--- 

## 🛠️ Rendu

- Tous les fichiers sources (`.c`) et en-têtes (`.h`) doivent être placés à la racine du dépôt.
- La norme de l'école 42 doit être strictement respectée.
- Aucun fichier ou fonction inutilisé ne doit être rendu.

---

## 📜 Licence

Ce projet est soumis aux règles de l'école 42.
