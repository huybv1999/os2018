#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define BUFFER_SIZE (100)
typedef struct 
{
  int type;  // 0 = chicken, 1 = fries
  int amount; // amount of product
  int unit; // 0 = piece, 1 = gram 
} item;

item buffer[BUFFER_SIZE];
int first = -1;
int last = 0;
bool CheckFirstTime = true;
 void produce(item* i){
 if ((first + 1)%BUFFER_SIZE == last && CheckFirstTime == false) return;
 first = (first + 1) % BUFFER_SIZE;
 memcpy(&buffer[first], i , sizeof(item));
}

 item* consume(){
 if (last  == (first+1)%BUFFER_SIZE) return NULL;
 item* i = malloc(sizeof(item));
 memcpy(i, &buffer[last] , sizeof(item));
 last = (last + 1) % BUFFER_SIZE; 
 return i;
}

void println(item i)
{
  printf("%d %d %d \n ", i.type, i.amount, i.unit); 
}

item ItemNew(char x, int y, char z)
{
  item i;
  i.type = x;
  i.amount = y;
  i.unit = z; 
  return i;
}



 int main()
{
      item chicken, fries;
      chicken = ItemNew(0, 15, 1);
      fries = ItemNew(1, 150, 0);
      item *PointToChicken =  &chicken;
      item *PointToFries = &fries;
      produce(PointToChicken);
      produce(PointToFries);
      item* serve = consume(); 
      if (serve != NULL)  println(*serve);
      return 0;
}

// You know. Saitama can defeat Goku with one punch :) //
// And Jiren could kill saitama with one blow :) //
// Yuno Gasai is still my best waifu :) //
     // -Bui Vu Huy - the creator of Anime //
