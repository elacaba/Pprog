/*
  Project: Yes... the same... the f...ing game

  Rev. 1.0
  10/17/2018



  Definition of a participant in the game (other than the player).
  There are a number of abilities (read from a file). Each character
  has a degree of skills in each one of them. When the character
  "plays" an ability will receive a random score that will be
  generated as a gaussian centered around its level of skill in that
  ability and with a prescribed variance.

*/


typedef struct {
  int id;
  char *name;
  int r_map, c_map;
  char **map;
  char **fore;
  char **back;
  int is_bw;
  int n_skill;
  int *skill;
  int last_score;  
} person;



person *read_person(FILE *f);


/*
  Returns the random score and puts it in last_score
*/
int play(person *p, int skill);


int get_last(person *p);

void kill_kill_kill(person *p);