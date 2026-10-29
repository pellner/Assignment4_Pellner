#include <stdio.h>
#include <string.h>
#include "item.h"
#include <stdlib.h>



void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){//use this to add 5 diff items in array and allocate memory use strlen to get length to know how much memory to allocate. use index paramater of this function to access the element of the array you want to add data to 
    item_list[index].price=price;//stores the price of the item
    
    item_list[index].sku=malloc(strlen(sku)+1);//allocates memory for sku and copys sku to sku memory
    strcpy(item_list[index].sku, sku);
    
    item_list[index].name=malloc(strlen(name)+1);//allocated memory
    strcpy(item_list[index].name, name);//copys name to memory name spot
    
    item_list[index].category=malloc(strlen(category)+1);//allocates memory
    strcpy(item_list[index].category, category);

}

void free_items(Item *item_list, int size){// use this to free memory of program
    
    /*
    free
    item_list[index].sku=malloc(strlen(sku)+1);
    strcpy(item_list[index].sku, sku);

    item_list[index].name=malloc(strlen(name)+1);
    strcpy(item_list[index].name, name);

    item_list[index].category=malloc(strlen(sku)+1)
    strcpy(item_list[index].category, category);                                             
    */
    for(int i=0; i<size; i++){
        free(item_list[i].sku);
	free(item_list[i].name);
	free(item_list[i].category);

    }
    //free the memory allocated to the array
    free(item_list);
}

double average_price(Item *item_list, int size){// use avg to calculate the avg price of all combined items

    double total=0;
    for(int i=0; i<size; i++){
        total=total + item_list[i].price;//adds the prices of all items in item_list

    }
    double avgval=total/size;
    return avgval;
}

void print_items(Item *item_list, int size){// use this to print_items function to the screen
   
    for(int i=0; i<size; i++){
        printf("############\n");
        //print item name
        printf("Item Name: %s\n", item_list[i].name);

        //print sku
        printf("Item Sku: %s\n", item_list[i].sku);

        //print category
        printf("Item category: %s\n", item_list[i].category);

        //print price 
        printf("Item Price: %f\n", item_list[i].price);
	printf("\n");
    }
}

int main(int argc, char *argv[]){

    Item *item_list = malloc(5 * sizeof(Item));//adds memory for the array
    	 
    //send values to add item to store in item_list
    add_item(item_list, 3.50, "16735", "Bread", "Sourdough", 0);
    add_item(item_list, 5.60, "49573", "Ceral", "Cinnamon Toast Crunch", 1);
    add_item(item_list, 8.99, "82537", "Sodas", "12 Pack Gatorade", 2);
    add_item(item_list, 4.50, "29473", "Berries", "Bannanas", 3);
    add_item(item_list, 3.99, "13564", "Dairy", "Whole Milk", 4);
    //passsing item_list and sizr to print items
    print_items(item_list, 5);
    double avgPrice = average_price(item_list, 5);
    printf("The Average price of items= %f\n",avgPrice);
    printf("\n");      


     if(argc > 1){
        int i=0;
        printf("Looking for item \n");
        while(i<5){
            if(strcmp(item_list[i].sku, argv[1])==0){
                printf("Item Found\n");
                printf("Item Name: %s\n", item_list[i].name);
                printf("Item Sku: %s\n", item_list[i].sku);
                printf("Item Price: %f\n", item_list[i].price);
                break;
            }
            i++;
        }
        if(i==5){
            printf("Item not found");
        }
    }
     
    free_items(item_list, 5);

    return 0;
}
// output should look like this 
// ###########
// item name= reese's cereal
// item sku=19282
// item category= breakfast
// item price =5.00
// ###########
// item name= etc..
// item sku=etc..
// item category=etc..
// item price= etc..
// ###########
// item name=etc..
// item sku=etc..
// item category=etc..
// item price=etc..
// ###########
// average price of items=etc..




