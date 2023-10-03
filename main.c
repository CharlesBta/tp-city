#include <stdio.h>
#include <string.h>

int nombreDeBatiment = 0;

typedef struct{
    int estConstruit;
    char typeBatiment[10];
    int buildingID;
} Case;

typedef struct{
    int x;
    int y;
} Position;

Case grille[10][10];

void construireBuilding(Position position,char type[10]){
    if(grille[position.y][position.x].estConstruit == 0){
        strcpy(grille[position.y][position.x].typeBatiment,type);
        grille[position.y][position.x].buildingID = nombreDeBatiment+1;
        nombreDeBatiment++;
        grille[position.y][position.x].estConstruit = 1;

        return;
    }
    else {printf("Un battiment est deja construit ici\n");
        return;}
}

void informationBuilding(Position position){
    if(grille[position.y][position.x].estConstruit != 0){
        printf("Le batiment est de type %sID: %d\n",grille[position.y][position.x].typeBatiment,grille[position.y][position.x].buildingID);
        return;
    }else{
        printf("Aucun batimen construit ici\n");
        return;}
}

Position endroit(){
    printf("Position x:");
    int x;
    scanf("%d",&x);
    printf("Position y:");
    int y;
    scanf("%d",&y);
    getchar();
    Position position;
    position.x= x;
    position.y = y;
    return position;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grille[i][j].estConstruit = 0;
        }
    }
    int value;
    printf("1. Construire batiment\n2. Information position\n3. Quitter\n");
    scanf("%d",&value);
    while(value != 0){
        if(value == 1){
            Position position = endroit();
            char typeBatiment[10];
            printf("Quel est le type de batiment ?");
            fgets(typeBatiment, 10, stdin);
            construireBuilding(position,typeBatiment);
        }
        else if(value == 2){
            Position position = endroit();
            informationBuilding(position);
        }
        printf("1. Construire batiment\n2. Information position\n3. Quitter\n");
        scanf("%d",&value);
        getchar();
    }

    return 0;
}
