#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "input_problem_1.txt"

#define MAXROWS 100
#define MAXCOLS 100
#define MAXWORDS 10

char grid[MAXROWS][MAXCOLS];
char wordsToFind[MAXWORDS][MAXCOLS];

int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int search_2D(char grid[MAXROWS][MAXCOLS], int row, int col, char word[], int size)
{

    //length of word
    int len = strlen(word);

    if(grid[row][col] != word[0]){
        //printf("Grid element = %c, word element = %c \n", grid[row][col], word[0] ); // for debugging purpose
        return 0;
    }

    else{
        for (int dir = 0; dir < 8; dir++) 
        {
            int k, rd = row + x[dir], cd = col + y[dir];
            for (k = 1; k < len; k++) {
                
                if (rd >= size || rd < 0 || cd >= size || cd < 0){
                    break;
                }
                //printf("grid element = %c, word element = %c \n", grid[rd][cd], word[k] ); // for debugging purpose

                // If not matched,  break
                if (grid[rd][cd] != word[k]){
                    break;
                }
    
                // Moving in particular direction
                rd += x[dir], cd += y[dir];

            }
            if (k == len){
                return 1;
            }   
        }
        return 0;
    }
}

void patternSearch(char grid[MAXROWS][MAXCOLS], char word[], int size)
{
    int count=0;
    // Consider every point as starting
    // point and search given word
    // printf("%s", word); // for debugging purpose
    for (int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            int temp = search_2D(grid, row, col, word, size);
            //printf("temp = %d\n", temp);  // for debugging purpose

            count += temp;  
            //printf("count = %d\n", count); // for debugging purpose
        }   
    }  
    printf("%s %d ",word, count);  
}



int main()
{
    FILE *scores;
    int testi;

	freopen("input_problem_1.txt", "r", stdin);
	int size, numWords, numTestCases;

// 1. Input number of test cases
	scanf("%d", &numTestCases);

// 2. Input number of rows
	for (testi = 0; testi < numTestCases; testi++) {
		scanf("%d", &size);
    //numTestCases=1; // for debugging purpose
// 3. Input number of number of words
		scanf("%d", &numWords);

// 4. Iterate for words to find
		for (int i = 0; i < numWords; i++) {
			scanf("%s", wordsToFind[i]);
		}
// 5. Iterate to input the grid
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				scanf(" %c", &grid[i][j]); // Note: there should be a space before %c to skip spaces and newlines
			}
		}
        /*
        printf("%d \n", numTestCases);
        printf("%d \n", numWords);
        printf("%d \n", size);
        for (int i = 0; i < numWords; i++) {
            printf("%s \n", wordsToFind[i]);
            
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf(" %c", grid[i][j]); // Note: there should be a space before %c to skip spaces and newlines
            }
            printf("\n");
        }
        */ // for debugging purpose
        for(int count=0; count<numWords; count++){
            patternSearch(grid, wordsToFind[count], size);
            //continue;
        }
        printf("\n");
    #ifdef DEBUG
            for (int i = 0; i < numWords; i++) {
                    printf("%s \n", wordsToFind[i]);
                }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    printf("%c", grid[i][j]);
                }
                printf("\n");
            }
    #endif
    }

}
