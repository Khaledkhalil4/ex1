#include "RLEList.h"


struct RLEList_t{
    char c;
    int timesAppeared;
    RLEList next;  
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
    while(list)
    {
        totalCharacters+=list->timesAppeared;
        list=list->next;
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
    while(list)
    { 
        currentIndex+=list->timesAppeared;
        if(index <= currentIndex)
        {
            list->timesAppeared--;
            if(list->timesAppeared == 0)
            {
                previous->next=list->next;
                free(list);
                break;
            } 
        } 
        if(list=previous)
        {
            list=list->next;
            continue;
        }
        previous=list; 
        list=list->next;    
    } 
    return RLE_LIST_SUCCES       
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
            tempList=templist->next;
        }
    }
    else 
    {
        return 0;
    }
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    RLEList tempList=list;
    if(result == RLE_LIST_SUCCESS)
    {
        int len=RLEListSize(list);
        char* word=malloc(sizeof(*(word)*len+1));
        int i=0;
    }
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function)
{
    
}