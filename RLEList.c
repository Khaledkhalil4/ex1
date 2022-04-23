#include "RLEList.h"
#include <string.h>


struct RLEList_t{
    char c;
    int timesAppeared;
    RLEList* next;  
    //TODO: implement
};
//add temp list to all functions
//implement the functions here
RLEList RLEListCreate()
{
    RLEList ptr=malloc(sizeof(*ptr));
    if(ptr != NULL)
    {
        return NULL;
    }
    assert(ptr != NULL);
    ptr->next=NULL;  
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
    if(value == NULL)
    {
        return(RLE_LIST_NULL_ARGUMENT);
    }
    if(list == NULL)
    {
        return(RLE_LIST_OUT_OF_MEMORY);
    }
    list->c=value;
    return(RLE_LIST_SUCCESS);
}

int RLEListSize(RLEList list)
{
    if(list == NULL)
    {
        return -1;
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
    int length=RLEListSize(list);

    if (index>length || index <0 )
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS; 
    }
    int currentIndex=0;
    RLEList previous=list;
    RLEList tempList=list;
    while(tempList)
    { 
        currentIndex+=tempList->timesAppeared;
        if(index <= currentIndex)
        {
            tempList->timesAppeared--;
            if(tempList->timesAppeared == 0)
            {
                previous->next=tempList->next;
                free(list);
                break;
            } 
        } 
        if(tempList=previous)
        {
            tempList=tempList->next;
            continue;
        }
        previous=list; 
        tempList=tempList->next;    
    } 
    return RLE_LIST_SUCCESS;      
}

char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    RLEList tempList=list;
    if(result == RLE_LIST_SUCCESS)
    {
        int currentIndex=0;
        while(tempList)
        {
            currentIndex+=list->timesAppeared;
            if(currentIndex>=index)
            {
                return(tempList->c);
            }
            tempList=tempList->next;
        }
    }
    else 
    {
        return 0;
    }
}

char* numberToString(RLEList currentNode)
{
    int i=0;
    int num=urrentNode->timesAppeared;
    while(num)
    {
        i++
        num/=10;
    }
    char* numberString=malloc(sizeof(*(numberString)*i));
        if(numberToString == NULL)
        {
            return RLE_LIST_NULL_ARGUMENT;
        }
    int j=0;
    while(currentNode->timesAppeared)
    {
        numberString[j]=(currentNode->timesAppeared%10)+'0'
        currentNode->timesAppeared/=10;
        j++;
    }
    return numberString;
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    RLEList tempList=list;
    if(result == RLE_LIST_SUCCESS)
    {  
        int length;
        while(tempList)
        {
            length+=sizeof(tempList->c)
            while(tempList->timesAppeared)
            {
                length++; //sizeof(int)
                tempList->timesAppeared/=10;   //check the 3otek
            }
            length++;  //\n
        }
        char* encodedWord=malloc(length+1);
        if(encodedWord == NULL)
        {
            return RLE_LIST_NULL_ARGUMENT;
        }
        for(int j=0;j<length+1>;j++)
        {
            encodedWord[j]='\0';
        }
        tempList=list;
        int i=0;
        while(tempList)
        {
            strcat(encodedWord,tempList->c)
            char* numberString=numberToString(tempList);
            strcat(encodedWord,numberString);
            free(numberString);
            strcat(encodedWord,'\n');
            tempList=tempList->next;
        }
        return encodedWord;
    }
    else
    {
        return NULL;
    }
}



RLEListResult RLEListMap(RLEList list, MapFunction map_function)
{
    if(list == NULL)
        {
            return(RLE_LIST_NULL_ARGUMENT);
        }
    RLEList tempList=list;
    while(tempList)
        {   
            tempList->c=map_function(tempList->c);
            tempList=tempList->next;
        }
    return RLE_LIST_SUCCESS;
    
}