// We propose to model a linked list of Books.
// A book is characterized by: Title, Book Code, Author (last name, first name, author code), Date of appearance (day, month, and year), Number of pages, number of copies sold, number of copies remaining in stock, and price.
// 1. Define the appropriate data types. Write the following procedures/functions, knowing that you can use, without implementing, the primitives seen in class: CreateEmptyList, IsListEmpty, AddAtBeginning, AddAtEnd, DisplayList.
// 2. Enter a book
// 3. Search for the existence of a book using its code
// 4. Add Book, which adds a book to the end of the list. It should be noted that a book is added only once to the list.
// 5. Display the title, author's name, and revenue (number of copies sold * price) of the best-selling book
// 6. Given the author's code, display the titles of their books
// 7. Display, for each author existing in the list, the titles of their books. Ensure not to process the same author more than once.
// 8. Create L2023, a list that contains all books whose year of appearance is 2023. Display L2023
// 9. Create L3, a list that contains all books depleted from stock. You are also asked to remove these books from the initial list L. Display L3 |||still needs to be finished
// 10. Propose a usage scenario for the already implemented functionalities. still needs to be finished
// ================================================================================================================
// On se propose de modéliser une liste chaînée de Livres.
// Un livre est caractérisé par : le Titre, le Code du livre, l’Auteur (nom, prénom, code Auteur), Date d’apparition (jour, mois et année), Nombre de pages, nombre de copies vendues, nombre de copies restantes dans le stock et le prix.
// 1. Définir les types de données appropriés. Écrire les procédures/fonctions suivantes tout en sachant que vous pouvez utiliser sans implémenter les primitives vues en cours : CreerListeVide, EstListeVide, AjoutDebut, AjoutFin, AfficherListe.
// 2. Saisir un livre
// 3. Chercher l’existence d’un livre en utilisant son code
// 4. Ajouter Livre qui permet d’ajouter un livre à la fin de la liste. Il est à noter qu’un livre n’est ajouté qu’une seule fois à la liste
// 5. Afficher le titre, le nom de l’auteur et la recette (nombre de copies vendues * le prix) du livre qui est le plus vendu
// 6. Étant donné le code de l’auteur, afficher les titres de ses livres
// 7. Afficher pour chaque auteur qui existe dans la liste les titres de ses livres. Pensez à ne pas traiter le même auteur plus d’une fois
// 8. Créer L2023 une liste qui contient tous les livres dont l’année d’apparition est 2023. Afficher L2023
// 9. Créer L3 une liste qui contient tous les livres épuisés du stock. On vous demande aussi de supprimer ces livres de la liste initiale L. Afficher L3   |||still needs to be finished
// 10. Proposer un scénario d’utilisation des fonctionnalités déjà implémentées. still needs to be finished

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct date1 {
    int jour;
    int mois;
    int annee;
} date;

typedef struct auteur1 {
    int codeAuteur;
    char nom[100];
    char prenom[100];
} auteur;

typedef struct head {
    int code;
    char titre[100];
    int nombreDePage;
    int nombreDeCopieVendu;
    int nombreDeCopieRestante;
    int prix;
    auteur auteurLivre;
    date dateLivre;
} livre;

typedef struct liste {
    livre Livre;
    struct liste *next;
} liste;

date saisirDate();
auteur saisirAuteur();
void afficherLivre(livre LivreX);
livre saisirLivre();

// ===============================================================

liste *creerListVide();
bool estVide(liste *livre);
liste *ajouterDebut(liste *head, int code);
liste *ajouterFin_code_saisir(liste *head, int code);
liste *ajouterFin_avec_element(liste *head, liste *element);
void Afficher_Rec(liste *head);
liste *chercherByCode(int code, liste *head);
liste *AjouterUnique(int code, liste *head);
void AfficherMaxRecette(liste *head);
void AfficherTitreLivreByCodeAuteur(int codeAuteur, liste *head);
void AfficherTitreLivreParChaqueAuteur(liste *head);
liste *CopieLivrel2023(liste *livre2023, liste *head);
liste * supprimer_elementFromList(liste * head,liste *element);
liste *creationUneListeAvecsupprimationItemDeLaListeOriginal(liste **head, liste *epouse);

int main() {
    liste *head = creerListVide();

    livre livre1 = {1, "World of Warcraft", 300, 50, 0, 25, {101, "Auteur1Nom", "Auteur1Prenom"}, {1, 1, 2023}};
    liste *node1 = malloc(sizeof(liste));
    node1->Livre = livre1;
    node1->next = head;
    head = node1;

    livre livre2 = {2, "The Lord of the Rings", 500, 30, 120, 30, {102, "Auteur2Nom", "Auteur2Prenom"}, {2, 2, 2022}};
    liste *node2 = malloc(sizeof(liste));
    node2->Livre = livre2;
    node2->next = head;
    head = node2;

    livre livre3 = {3, "Harry Potter", 400, 40, 0, 20, {106, "Auteur3Nom", "Auteur3Prenom"}, {3, 3, 2023}};
    liste *node3 = malloc(sizeof(liste));
    node3->Livre = livre3;
    node3->next = head;
    head = node3;

    livre livre4 = {4, "1984", 250, 20, 80, 15, {106, "Auteur4Nom", "Auteur4Prenom"}, {4, 4, 2022}};
    liste *node4 = malloc(sizeof(liste));
    node4->Livre = livre4;
    node4->next = head;
    head = node4;

    livre livre5 = {5, "To Kill a Mockingbird", 350, 25, 0, 18, {105, "Auteur5Nom", "Auteur5Prenom"}, {5, 5, 2022}};
    liste *node5 = malloc(sizeof(liste));
    node5->Livre = livre5;
    node5->next = head;
    head = node5;

    livre livre6 = {6, "The Great Gatsby", 200, 35, 0, 22, {106, "Auteur6Nom", "Auteur6Prenom"}, {6, 6, 2023}};
    liste *node6 = malloc(sizeof(liste));
    node6->Livre = livre6;
    node6->next = head;
    head = node6;

    // printf("=====================================================\n");
    // printf("=====================================================\n");
    // printf("=====================================================\n");
    // printf("=====================================================\n");
    // Afficher_Rec(head);
    // AfficherMaxRecette(head);
    // AfficherTitreLivreByCodeAuteur(56,head);
    liste *livre2023 = creerListVide();
    livre2023 = CopieLivrel2023(livre2023, head);

    liste *epouse = creerListVide();
    epouse = creationUneListeAvecsupprimationItemDeLaListeOriginal(&head, epouse);
    // AfficherTitreLivreParChaqueAuteur(livre2023);
    Afficher_Rec(head);
}

auteur saisirAuteur() {
    auteur AuteurX;
    printf("Donner le nom de l'auteur:\n");
    scanf("%s", AuteurX.nom);

    printf("Donner le prenom de le auteur:\n");
    scanf("%s", AuteurX.prenom);

    printf("Donner le numero de l'auteur:\n");
    scanf("%d", &AuteurX.codeAuteur);
    return AuteurX;
}

date saisirDate() {
    date Datex;
    printf("Donner le jour:\n");
    scanf("%d", &Datex.jour);

    printf("Donner le Mois:\n");
    scanf("%d", &Datex.mois);

    printf("Donner le annees:\n");
    scanf("%d", &Datex.annee);
    return Datex;
}

livre saisirLivre(int code) {
    livre LivreX;
    LivreX.code = code;
    printf("Donner le titre:\n");
    scanf("%s", LivreX.titre);
    printf("Donner nombre de pages:\n");
    scanf("%d", &LivreX.nombreDePage);
    printf("Donner nombre de Copies Vendu:\n");
    scanf("%d", &LivreX.nombreDeCopieVendu);
    printf("Donner nombre de Copie restante:\n");
    scanf("%d", &LivreX.nombreDeCopieRestante);
    printf("Donner le prix:\n");
    scanf("%d", &LivreX.prix);
    LivreX.auteurLivre = saisirAuteur();
    LivreX.dateLivre = saisirDate();

    return LivreX;
}

void afficherLivre(livre LivreX) {
    printf("Code : %d\n", LivreX.code);
    printf("Titre : %s\n", LivreX.titre);
    printf("Nombre de pages : %d\n", LivreX.nombreDePage);
    printf("Nombre de copies vendues : %d\n", LivreX.nombreDeCopieVendu);
    printf("Nombre de copies restantes : %d\n", LivreX.nombreDeCopieRestante);
    printf("Prix : %d\n", LivreX.prix);

    printf("Auteur :\n");
    printf("   Nom : %s\n", LivreX.auteurLivre.nom);
    printf("   Prenom : %s\n", LivreX.auteurLivre.prenom);
    printf("   Code de le auteur : %d\n", LivreX.auteurLivre.codeAuteur);

    printf("Date du livre :\n");
    printf("   Jour : %d\n", LivreX.dateLivre.jour);
    printf("   Mois : %d\n", LivreX.dateLivre.mois);
    printf("   Annee : %d\n", LivreX.dateLivre.annee);
}

liste *creerListVide() {
    return NULL;
}

bool estVide(liste *livre) {
    if (livre == NULL)
        return true;
    else
        return false;
}

liste *ajouterDebut(liste *head, int code) {
    liste *temp = malloc(sizeof(liste));
    if (estVide(temp)) {
        printf("Error No space in memory!");
        exit(-1);
    }
    temp->Livre = saisirLivre(code);
    temp->next = head;
    return temp;
}

liste *ajouterFin_code_saisir(liste *head, int code) {

    liste *temp = malloc(sizeof(liste));
    if (estVide(temp)) {
        printf("Error No space in memory!");
        exit(-1);
    }
    temp->Livre = saisirLivre(code);
    temp->next = NULL;

    if (estVide(head))
        return temp;

    liste *last = head;
    while (last->next) {
        last = last->next;
    }
    last->next = temp;
    return head;
}

liste *ajouterFin_avec_element(liste *head, liste *element) {

    liste *temp = malloc(sizeof(liste));
    if (estVide(temp)) {
        printf("Error No space in memory!");
        exit(-1);
    }
    temp->Livre = element->Livre;
    temp->next = NULL;

    if (estVide(head))
        return temp;

    liste *last = head;
    while (last->next) {
        last = last->next;
    }
    last->next = temp;
    return head;
}

void Afficher_Rec(liste *head) {
    if (estVide(head))
        printf("fin\n");
    else {
        afficherLivre(head->Livre);
        printf("===========================\n");
        head = head->next;
        Afficher_Rec(head);
    }
}

liste *chercherByCode(int code, liste *head) {
    while (head && head->Livre.code != code) {
        head = head->next;
    }
    return head;
}

liste *AjouterUnique(int code, liste *head) {

    if (!chercherByCode(code, head)) {
        head = ajouterFin_code_saisir(head, code);
    } else {
        printf("Element deja Existe");
    }
    return head;
}

void AfficherMaxRecette(liste *head) {
    liste *temporelle = head;

    if (estVide(head)) {
        printf("Liste est vide!");
        return;
    }
    liste *livreMaxRecette = temporelle;
    int recette = livreMaxRecette->Livre.nombreDeCopieVendu * livreMaxRecette->Livre.prix;
    temporelle = temporelle->next;

    while (!estVide(temporelle)) {
        if (recette < (temporelle->Livre.nombreDeCopieVendu * temporelle->Livre.prix)) {
            livreMaxRecette = temporelle;
            recette = temporelle->Livre.nombreDeCopieVendu * temporelle->Livre.prix;
        }
        temporelle = temporelle->next;
    }
    printf("le titre : %s\nle nom : %s\nla recette :%d\n", livreMaxRecette->Livre.titre,
           livreMaxRecette->Livre.auteurLivre.nom, recette);
}

void AfficherTitreLivreByCodeAuteur(int codeAuteur, liste *head) {
    bool found = false;
    while (head) {
        if (head->Livre.auteurLivre.codeAuteur == codeAuteur) {
            printf("\tTitre:%s\n", head->Livre.titre);
            found = true;
        }
        head = head->next;
    }
}

void AfficherTitreLivreParChaqueAuteur(liste *head) {
    if (estVide(head)) {
        printf("Liste est vide!");
        return;
    }
    liste *temp = head;
    int nombreDeAuteur = 0;
    int *listeAuteur = NULL;
    while (temp) {
        int id = temp->Livre.auteurLivre.codeAuteur;
        bool find = false;

        for (int i = 0; i < nombreDeAuteur; i++) {
            if (listeAuteur[i] == id) {
                find = true;
                break;
            }
        }
        if (!find) {
            nombreDeAuteur++;
            listeAuteur = realloc(listeAuteur, nombreDeAuteur * sizeof(int));
            if (listeAuteur == NULL) {
                printf("pas d'espace memoire!");
                exit(-1);
            }
            listeAuteur[nombreDeAuteur - 1] = id;
        }
        temp = temp->next;
    }
    for (int i = 0; i < nombreDeAuteur; i++) {
        printf("IdAuteur:%d\n", listeAuteur[i]);
        AfficherTitreLivreByCodeAuteur(listeAuteur[i], head);
    }
    free(listeAuteur);
}

liste * CopieLivrel2023(liste * livre2023,liste *head){

    if(estVide(head)){
        return NULL;
    }
    liste * temp = head;
    while(temp){
        if(temp->Livre.dateLivre.annee == 2023){
            livre2023=ajouterFin_avec_element(livre2023,temp);
        }
        temp=temp->next;
    }
    return livre2023;
}

liste *supprimer_elementFromList(liste *head, liste *element) {
    if (!head || !element) {
        return head; 
    }
    if (head == element) {
        liste *newHead = head->next;
        free(head);
        return newHead;
    }
    liste *current = head;
    liste *previous = NULL;

    while (current && current != element) {
        previous = current;
        current = current->next;
    }

    if (current) {
        previous->next = current->next;
        free(current);
    }
    return head;
}

liste *creationUneListeAvecsupprimationItemDeLaListeOriginal(liste **head, liste *epouse) {
    if (estVide(*head)) {
        return NULL;
    }

    liste *actual = *head;
    liste *temp = NULL; 

    while (actual) {
        if (actual->Livre.nombreDeCopieRestante == 0) {
            epouse = ajouterFin_avec_element(epouse, actual);

            temp = actual->next;
            *head = supprimer_elementFromList(*head, actual);
            actual = temp;
        } else {
            actual = actual->next;
        }
    }

    return epouse;
}
