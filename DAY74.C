#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];
    for(int i = 0; i < n; i++)
        scanf("%s", names[i]);

    int count[n];
    for(int i = 0; i < n; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++) {
        if(count[i] != -1) {
            count[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(strcmp(names[i], names[j]) == 0) {
                    count[i]++;
                    count[j] = -1;
                }
            }
        }
    }

    int maxVotes = 0;
    char winner[50];

    for(int i = 0; i < n; i++) {
        if(count[i] != -1) {
            if(count[i] > maxVotes) {
                maxVotes = count[i];
                strcpy(winner, names[i]);
            } else if(count[i] == maxVotes) {
                if(strcmp(names[i], winner) < 0)
                    strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}