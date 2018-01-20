#include<unistd.h>
#include<stdbool.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 100
typedef struct 
{
  int type;  // 0 = chicken, 1 = fries, 2 = pepsi
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
 printf("Comsume: first = %d, last = %d \n", first, last);
}

item* consume(){
 if (last  == (first+1)%BUFFER_SIZE) return NULL;
 item* i = malloc(sizeof(item));
 memcpy(i, &buffer[last] , sizeof(item));
 last = (last + 1) % BUFFER_SIZE;
 printf("Comsume: first = %d, last = %d \n", first, last); 
 return i;
}

void println(item* i)
   {
    printf("%d %d %d \n ", i->type, i->amount, i->unit);
   }

item ItemNew(char x, int y, char z)
{
  item i;
  i.type = x;
  i.amount = y;
  i.unit = z; 
  return i;
}

void* pthreadProduce(void *param){
      item chicken, fries, pepsi;
      chicken = ItemNew(0, 15, 1);
      fries = ItemNew(1, 150, 0);
      pepsi = ItemNew(2, 10, 1);
      item *PointToChicken =  &chicken;
      item *PointToFries = &fries;
      item *PointToPepsi = &pepsi;
      produce(PointToChicken);
      produce(PointToFries);
      produce(PointToPepsi);

}

void* pthreadconsume(void *param){
    println(consume());
    println(consume());

}

 int main()
{
       // Begin to create thread //
      pthread_t tid1, tid2;
      pthread_create;
      pthread_create(&tid1, NULL, pthreadProduce ,NULL);
      pthread_join(tid1, NULL);
      pthread_create(&tid2, NULL, pthreadconsume, NULL);
      pthread_join(tid2, NULL);
      
      return 0;
      
}
       
     
   // You know, Yuno Gasai is still my best waifu :) //
