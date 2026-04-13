#include <stdio.h>

#define MAX 100

int table[MAX];

void insert(int m, int key){
    int h = key % m;
    for(int i=0;i<m;i++){
        int idx = (h + i*i) % m;
        if(table[idx] == -1){
            table[idx] = key;
            return;
        }
    }
}

void search(int m, int key){
    int h = key % m;
    for(int i=0;i<m;i++){
        int idx = (h + i*i) % m;
        if(table[idx] == key){
            printf("FOUND\n");
            return;
        }
        if(table[idx] == -1) break;
    }
    printf("NOT FOUND\n");
}

int main(){
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for(int i=0;i<m;i++) table[i] = -1;

    while(q--){
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if(op[0] == 'I')
            insert(m, key);
        else
            search(m, key);
    }
    return 0;
}