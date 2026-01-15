# PROJET_CC
TITRE DU PROJRET : **VISUALISEUR DE DONNEES SIMPLES**    
# 1. DESCRIPTION DU PROJET 
Ce projet consiste à créer une application capable de représenter graphiquement 
des données fixes à l’aide de deux types de graphiques : 
📊 GRAPHIQUE A BARRES : pour comparer visuellement plusieurs valeurs ; 
 DIAGRAMME DE CAMEMBERT (ou « pie chart ») : pour montrer la 
répartition proportionnelle d’un ensemble de données ; 
# 2. FONCTIONNALITES PRINCIPALES  
 📊 Affichage de graphiques a barres : chaque barres représentent une 
valeur numérique la hauteur de chaque barre est proportionnelle a la 
donnée comparaison des valeurs et données (scores, notes, vente par mois)  
☑️ Affichage du diagramme en camembert ou chaque portion du diagramme 
représente un pourcentage du pourcentage total  
 Utilisation des données fixes données codées directement dans le 
programme (tableau, vecteur) par exemple (maths:40, GAP:30, anglais:20)  
☑️ Différenciation visuelle des couleurs différentes pour chaque barre ou 
portion  
## Titre et légendes : titre du graphique  
 📉 Echelle simple : adaptation à partir de la taille de la fenêtre  
🅰️Affichage des labels ou noms des catégories (matières, produits)  
# 3. 🐛 PROBLEMES TECHNIQUES POSSIBLES  
⚠️ PROBLEMES MATHEMATIQUES ET LIES AUX DONNEES  
• mauvaise normalisation des donnés (exemple: pourcentage>100)  
• valeurs nulles ou négatives  
• Mauvaise conversion des valeurs en angles  

## 🐛pPROBLEMES LIES AU GRAPHISME ET A L'AFFICHAGE  
• 📊 Barres trop grandes ou trop petites  
• texte qui dépasse de l'écran  
• La gestion des marges (axes, bords de la fenêtre)  
• 🖌Dessiner un cercle ou des arcs de cercles  
## 🧨 PROBLEMES DE CODE  
Mauvaise structure du programme (sans les fichiers en-têtes et .cpp)  
## ⚠️ PROBLEMES LIES A LA BIBLIOTHEQUES GRAPHIQUE (SDL/SDL3)  
SDL ne possède pas de fonctions pour :  
• 🖌️ Dessiner des cercles ou des arcs de cercles  
Pour cela il faut utiliser:  
• imGui ou Dear ImGui pour créer des interfaces graphiques pour 
des applications, des outils de développement ou des moteurs 
de jeu ;  
# 4. 🛠 TECHNIQUES A UTILISER ET ETAPES  
➡️ L'utilisation des structures, des tableaux, des vecteurs, des classes ;  
➡️ Des techniques mathématiques pour la normalisation des données, le calcul 
des pourcentages, la trigonométrie pour les portions du camembert (sin, cos) ;  
➡️ Conversion des angles en radians ;  
 📐 La mise à l'échelle techniques graphiques ;  
 🖌️ Dessin de rectangles (pour le graphique a barre) ;  
 🎨dessin des cercles et arcs (camembert) ;  
🔴 Couleurs RGB différentes ;  
📝 Affichage de texte (titres, légendes) ;  
➡️ Utilisation d'une boucle pour chaque portion ;  
## 🏴techniques de programmation  
• 🖋️ commenter le code pour sa compréhension ;  
• Utiliser les fonctions déclarées dans les fichiers en-tête et les appeler plu tard ;  
• Séparer le code (données, calculs, affichage) ;  
• utilisation de la SDL3, imGui, pour le rendu graphique ;  
# 5. 💡EXEMPLES CONCRETS D'UTILISATION 
