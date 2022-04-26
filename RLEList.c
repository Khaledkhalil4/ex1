#include "RLEList.h"
#include <string.h>
#include <stdlib.h>

#define NULL_LIST -1
#define TWO 2
#define TEN 10

typedef struct RLEList_t{
    char letter;
    int timesAppeared;
    struct RLEList_t *next;
    //TODO: implement
} RLEList_t;


//implement the functions here
RLEList RLEListCreate()
{
    RLEList ptr=malloc(sizeof(*ptr));
    if(ptr == NULL)
    {
        return NULL;
    }
    ptr->letter='\0';
    ptr->timesAppeared=0;
    ptr->next=NULL;
    return ptr;
}

void RLEListDestroy(RLEList list)
{
    while(list)
    {
        RLEList toDelete=list;
        list=list->next;
        free(toDelete);
    }
}

RLEListResult RLEListAppend(RLEList list, char value)
{
    if(list == NULL)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList tempList=list;
    while(tempList->next)
    {
        tempList=tempList->next;
    }
    if(value == tempList->letter)
    {
        tempList->timesAppeared+=1;
    }
    else
    {
        RLEList newList=RLEListCreate();
        if(!newList)
        {
            return RLE_LIST_OUT_OF_MEMORY;
        }
        tempList->next=newList;
        newList->letter=value;
        newList->timesAppeared+=1;
    }
    return RLE_LIST_SUCCESS;
}

int RLEListSize(RLEList list)
{
    if(list == NULL)
    {
        return NULL_LIST;
    }
    int totalCharacters=0;
    RLEList tempList=list;
    while(tempList)
    {
        totalCharacters+=tempList->timesAppeared;
        tempList=tempList->next;
    }
    return totalCharacters;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if(list == NULL)
    {
        return(RLE_LIST_NULL_ARGUMENT);
    }

    if (index>=RLEListSize(list) || index <0 )
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    index++;
    int currentIndex=0;
    RLEList previous=list;
    RLEList tempList=list->next;
    while(tempList)
    {
        currentIndex+=tempList->timesAppeared;
        if(index <= currentIndex)
        {
            tempList->timesAppeared--;
            if(tempList->timesAppeared == 0)
            {
                RLEList nextList=tempList->next;
                if(nextList!=NULL && previous->letter==nextList->letter)
                {
                    previous->timesAppeared+=nextList->timesAppeared;
                    previous->next=nextList->next;
                    free(tempList->next);
                    free(tempList);
                    break;
                }
                previous->next=tempList->next;
                free(tempList);
                break;
            }
            break;
        }
        previous=tempList;
        tempList=tempList->next;
    }
    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result) //check *RESULT
{
    if(!list)
    {
        if(result)
        {
            *result= RLE_LIST_NULL_ARGUMENT;
        }
        return 0;
    }
    if(index>= RLEListSize(list) || index<0)
    {
        if(result)
        {
            *result=RLE_LIST_INDEX_OUT_OF_BOUNDS;
        }
        return 0;
    }
    index++;
    RLEList tempList=list->next;
    int currentIndex=0;
    while(tempList)
    {
        currentIndex+=tempList->timesAppeared;
        if(currentIndex>=index)
        {
            if(result)
            {
                *result=RLE_LIST_SUCCESS;
            }
            return(tempList->letter);
        }
        tempList=tempList->next;
    }

    return 0;
}

char* numberToString(RLEList currentNode)
{
    int i=0;
    int num=currentNode->timesAppeared;
    while(num)
    {
        i++;
        num/=TEN;
    }
    char* numberString=malloc(sizeof(*numberString)*(i+1));
    if(!numberString)
    {
        return NULL;
    }
    numberString[i]='\0';
    num=currentNode->timesAppeared;
    for(i=i-1;i>=0;i--)
    {
        numberString[i]=(num%TEN)+'0';
        num/=TEN;
    }
    return numberString;
}

char* RLEListExportToString(RLEList list, RLEListResult* result) // check
{
    if(!list)
    {
        if(result)
        {
            *result=RLE_LIST_NULL_ARGUMENT;
        }
        return NULL;
    }
    RLEList tempList=list;
    int length=0;
    while(tempList)
    {
        length++;
        int numberCount=tempList->timesAppeared;
        while(numberCount)
        {
            length++; //sizeof(int)
            numberCount/=TEN;
        }
        length++;  //\n
        tempList=tempList->next;
    }
    char* encodedWord=malloc(sizeof(char)*(length+1));
    if(encodedWord == NULL)
    {
        if(result)
        {
            *result=RLE_LIST_OUT_OF_MEMORY;
        }
        return NULL;
    }
    for(int j=0;j<length+1;j++)
    {
        encodedWord[j]='\0';
    }
    tempList=list->next;
    while(tempList)
    {
        char letterString[TWO] = {tempList->letter, '\0'};
        strcat(encodedWord, letterString);
        char* numberString=numberToString(tempList);
        if(numberString == NULL)
        {
            if(result)
            {
                *result=RLE_LIST_OUT_OF_MEMORY;
            }
            return NULL;
        }
        strcat(encodedWord,numberString);
        free(numberString);
        char newLineString[TWO] = {'\n', '\0'};
        strcat(encodedWord, newLineString);
        tempList=tempList->next;
    }
    if(result)
    {
        *result=RLE_LIST_SUCCESS;
    }
    return encodedWord;
}



RLEListResult RLEListMap(RLEList list, MapFunction map_function) //check
{
    if(list == NULL || map_function == NULL)
    {
        return(RLE_LIST_NULL_ARGUMENT);
    }
    RLEList tempList=list->next;
    while(tempList)
    {
        tempList->letter=map_function(tempList->letter);
        tempList=tempList->next;
    }
    return RLE_LIST_SUCCESS;

}
