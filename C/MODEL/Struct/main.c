#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/// ~~~ Recursive Structure ~~~
typedef struct TreeNode{
  int nr;
  struct TreeNode *left,*right;
}TreeNode_t;




int main(){
  /// ~~~ Structure & Structur Function ~~~
  typedef struct point{
    int x,y;
  }point_t;

  point_t addPoints(point_t p1, point_t p2){
    point_t res;
    res.x=p1.x + p2.x;
    res.y=p1.y + p2.y;
    return res;
  }

  point_t p1={1, 2},p2;
  p2.x=2; p2.y=3;
  point_t pRes=addPoints(p1,p2);

  printf("x - %d\ty - %d\n",addPoints(p1,p2).x, addPoints(p1,p2).y);
  printf("x - %d\ty - %d\n",pRes.x, pRes.y);

  /// ~~~ Structure w/ Pointers ~~~
  typedef struct ExStruct{
    int exInt;
    char *exChar;
  }ExStruct_t;

  printf("%d\n",sizeof(ExStruct_t)); // size: 8 = 4 (int) + 1 (char) + 3 (extra)

  ExStruct_t *tab = malloc(sizeof(ExStruct_t));
  tab[0].exChar = malloc(sizeof(char));

  /// ~~~ Stucture w/ bits/field ~~~
  typedef struct date{
    unsigned sec:6, min:6;
    unsigned hour:5, day:5;
    unsigned month:4;
    unsigned year: 6;
  }date_t;

  void printDate(date_t dateVal){
    printf("%d:%d:%d %d-%d-%d\n",dateVal.hour,dateVal.min,dateVal.sec,dateVal.day,dateVal.month,2000+dateVal.year);
  }

  date_t today={0, 55, 1, 28,1, 20};
  printDate(today);
  printf("%d\n",sizeof(date_t));

  /// ~~~ Enumerations ~~~
  enum days {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
  int work_hours[7];

  for (int i=Mon ; i<=Fri ; i++){
    work_hours[i]=8;
  }
  work_hours[Wed]=5;
  printf("%d\n",work_hours[Wed]);

  /// ~~~ Unions ~~~
  union IntOrUnsigned{
    int32_t i;
    uint32_t u;
  }nr;

  nr.u=-43;
  printf("int - %d\t uint - %u\n", nr.i, nr.u);
}
