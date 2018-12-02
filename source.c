/**
 * Rat in Maze
 *
 * A rat is placed through the door of a large box without a top. 
 * Walls are set up so that movements in most directions are obstructed. 
 * The rat is carefully observed by several scientists as it makes its way 
 * through the maze until it eventually reaches the exit. There is only 
 * one way out and at the end is a nice chunk of cheese. The rat must 
 * zip through the maze finally, without taking a single false path.
 *
 *
 *
 * @author Akhil Kokani
 * @package Rat in Maze
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 100
#define true 1
#define false 0

int given_maze [ n ][ n ];
char solution_maze [ n ][ n ];
int size_of_maze;
char path_director = '-';

void get_details() {

  int i, j; 

  printf("Enter size of maze: ");
  scanf ( "%d", &size_of_maze );

  printf ( "Initialised your maze: \n" );
  for (i = 0; i < size_of_maze; i++ ) {

    for (j = 0; j < size_of_maze; j++ ) {

      given_maze [ i ][ j ] = 0;
      strcpy ( &solution_maze [ i ][ j ], "." );
      printf("%d ", given_maze[i][j]);
    }
    printf("\n");
  }

  printf ( "Enter maze structure: \n" );
  for (i = 0; i < size_of_maze; i++ ) {
    for (j = 0; j < size_of_maze; j++ ) scanf ( "%d", &given_maze[i][j] );
  }
}

int check_validity_and_path_existence ( int maze[][n], int a, int b) {

  if ( a >= 0 && a < size_of_maze && b >= 0 && b < size_of_maze && maze[a][b] == 1 ) return true;
  return false;
}

int find_path ( int maze[][n], int a, int b, char sol_maze[][n], char path_director ) {

  if ( a == size_of_maze-1 && b == size_of_maze-1 ) {
    
    path_director = '_';
    sol_maze[a][b] = path_director;
    return true;
  }

  if ( (a - 1) == 0 ) sol_maze[0][0] = '|';

  if ( check_validity_and_path_existence(maze, a, b) == true ) {

    sol_maze[a][b] = path_director;

    if ( find_path(maze, a + 1, b, sol_maze, '|') == true ) return true;

    if ( find_path(maze, a, b + 1, sol_maze, '_') == true ) return true;

    sol_maze[a][b] = (char) '.';
    return false;
  }

  return false;
}

int main (  ) {

  get_details();

  if ( find_path(given_maze, 0, 0, solution_maze, '_') == false ) {

    printf("Your rat could not have it's cheese, better luck next time!\n");
    return 0;
  } 
  else {

    printf("Your rat found it's way to have cheese!\n");
    printf("Here is how it went till its cheese: \n");
    for ( int i = 0; i < size_of_maze; i++ ) {

      for ( int j = 0; j < size_of_maze; j++ ) printf("%c ", solution_maze[i][j]);
      printf("\n");
    }
  }
  return 0;
}