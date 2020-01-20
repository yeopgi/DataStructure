#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    /*  Å¥žŠ ÀÚÀ¯ÀúÀåŒÒ¿¡ »ýŒº */
    (*Queue )        = ( LinkedQueue*)malloc(sizeof( LinkedQueue ) );
    (*Queue )->Front = NULL;
    (*Queue )->Rear  = NULL;
    (*Queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( !LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode(Popped);    
    }

    /*  Å¥žŠ ÀÚÀ¯ ÀúÀåŒÒ¿¡Œ­ ÇØÁŠ */
    free( Queue );
}

Node* LQ_CreateNode( char* NewData )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    NewNode->Data = (char*)malloc( strlen( NewData) + 1);

    strcpy(NewNode->Data, NewData);  /*  µ¥ÀÌÅÍžŠ ÀúÀåÇÑŽÙ. */

    NewNode->NextNode = NULL; /*  ŽÙÀœ ³ëµå¿¡ ŽëÇÑ Æ÷ÀÎÅÍŽÂ NULL·Î ÃÊ±âÈ­ ÇÑŽÙ. */

    return NewNode;/*  ³ëµåÀÇ ÁÖŒÒžŠ ¹ÝÈ¯ÇÑŽÙ. */
}

void  LQ_DestroyNode(Node* _Node )
{
    free(_Node->Data);
    free(_Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
    if ( Queue->Front == NULL ) 
    {        
        Queue->Front = NewNode;
        Queue->Rear  = NewNode;
        Queue->Count++;
    } 
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

Node* LQ_Dequeue( LinkedQueue* Queue )
{
    /*  LQ_Dequeue() ÇÔŒö°¡ ¹ÝÈ¯ÇÒ ÃÖ»óÀ§ ³ëµå */
    Node* Front = Queue->Front;

    if ( Queue->Front->NextNode == NULL )
    {
        Queue->Front = NULL;
        Queue->Rear  = NULL;
    }
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--;

    return Front;
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL);
}