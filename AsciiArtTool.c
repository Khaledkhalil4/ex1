#include "AsciiArtTool"

#define MAX_BUFFER 256
RLEList asciiArtRead(FILE* in_stream)
{
    RLEList list=RLEListCreate();
    //RLEList* header=&list;
    FILE* input=fopen(in_stream,"r");
    if(input== NULL)
    {
        return -1;
    }
    char buffer[MAX_BUFFER]={0}; //
    while(fgets(input,MAX_BUFFER,in_stream)!= NULL)
    {   
        previousChar=buffer[0]
        int count =0;
        for(int i=0;i<MAX_BUFFER;i++)
        {
            if(previousChar==buffer[i])
            {
                count++;
                continue;
            }
            else
            {
                RLEListAppend(list,previousChar);
                list->timesAppeared=count;
                previousChar=buffer[i];
                count=0;
                list=list->next;
            }
        }
        
    }
  //  &list=header;
    fclose(in_stream);
    return list;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    int length=RLEListSize(list);
    char* asciiArt=malloc(sizeof(*(asciiart))*length+1);
    RLEList tempList=list;
    while(tempList)
    {
        for(int i=0;i<tempList->timesAppeared;i++)
        {
            
        }
    }
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{

}