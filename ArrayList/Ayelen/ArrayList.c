#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/ArrayList.h"
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements = pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int okSizeUp;

    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            okSizeUp = resizeUp(this);
            if(okSizeUp)
            {
                printf("No se pudo conseguir lugar\n");
                return 0;
            }

        }

        *(this->pElements +  this->size) = pElement;
        this->size++;
        returnAux = 0;

    }

    return returnAux;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {

            free(*(this->pElements+i));

        }
        free(this->pElements);
        free(this);

        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = (this->size);
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index>=0 && index<this->len(this))
    {
        returnAux = *((this->pElements) + index);

    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this != NULL && pElement != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            if(*((this->pElements +i)) == pElement)
            {

                returnAux = 1;
                break;
            }
            else
            {
                returnAux = 0;
            }
        }

    }

    return returnAux;

}



/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL &&  pElement != NULL && index>=0 && index<=(this->len(this)))
    {

        if(index == this->len(this))
        {

            this->add(this,pElement);


        }
        else if(index<this->len(this))
        {
            *(this->pElements + index) = pElement;

        }

        returnAux = 0;
    }


    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;

    if(this != NULL && index>=0 && index<(this->len(this)))
    {
        /*free(this->pElements[index]);

        (this->pElements[index]) = (this->pElements[this->size-1]);*/
        contract(this,index);
        // this->size--;
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    //int i;

    if(this != NULL)
    {
        if((this->reservedSize - this->size <= 10))
        {
            resizeDown(this);
            this->reservedSize = 10;
            this->size = 0;

        }
        returnAux = 0;

    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this != NULL)
    {
        returnAux = al_newArrayList();
        if(returnAux != NULL)
        {
            returnAux->size = this->size;
            returnAux->reservedSize = this->reservedSize;

            returnAux->pElements =(void*) malloc(sizeof(void*)* this->reservedSize);

            if(returnAux->pElements != NULL)
            {
                for(i=0; i<returnAux->size; i++)
                {
                    returnAux->pElements[i] = this->pElements[i];
                }

            }

        }

    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
*/
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL && index>=0)
    {

        if(index == this->len(this))
        {
            if(this->add(this,pElement)==0)
            {
                returnAux=0;
            }
        }
        else
        {
            if(index < this->len(this))
            {
                if(expand(this,index) == 0)
                {
                    if(this->set(this,index,pElement) == 0)
                    {
                        returnAux=0;
                    }
                }
            }
        }
    }


    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i= 0; i<this->size; i++)
        {

            if((this->get(this,i)) == pElement)
            {
                returnAux = i;
                break;
            }

        }

    }

    return returnAux;

}

/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;


    if(this != NULL)
    {
        if(this->len(this) == 0 )
        {
            returnAux = 1;

        }
        else
        {
            returnAux = 0;

        }
    }

    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;


    if(this != NULL && index>=0 && index<(this->len(this)))
    {
        returnAux = this->get(this,index);
        contract(this,index);
    }

    return returnAux;

}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */

ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;
    int i;
    if(this != NULL && from >= 0 && from < to && to <= this->len(this) && from<this->len(this))
    {
        returnAux = al_newArrayList();

        for (i=from; i<to; i++)
        {

            returnAux->add(returnAux,this->get(this,i));

        }
    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)//75%
{
    int i, j, returnAux=-1, equals=0;

    if(this!=NULL && this2!=NULL)
    {
        for(i=0 ; i<this2->size ; i++)
        {
            for(j=0 ; j<this->size ; j++)
            {
                if(this2->size<=this->size)
                {
                    if(*(this2->pElements+i)==*(this->pElements+j))
                    {
                        equals=1;
                        returnAux=1;
                        continue;

                    }

                }
            }
        }
        if(equals==0)
        {
            return 0;
        }

    }

    return returnAux;

}


/** \brief Sorts objects of list, use compare pFunc
* \param pList ArrayList* Pointer to arrayList
* \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [pList or pFunc are NULL pointer]
*                  - (0) if ok
*/
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i,j;

    void* aux;


    if(pFunc != NULL && this != NULL && (order == 1 || order == 0))
    {
        for(i=0; i<this->len(this)-1; i++)
        {
            for(j=i+1; j<this->len(this); j++)
            {

                if(order == 1)
                {
                    if( pFunc(this->get(this,i),this->get(this,j)) == 1 )
                    {
                        aux=this->get(this,i);
                        this->set(this,i,this->get(this,j));
                        this->set(this,j,aux);


                    }
                }
               else if( order == 0)
                {

                    if(pFunc(this->get(this,i),this->get(this,j)) == -1 )
                    {
                         aux=this->get(this,i);
                        this->set(this,i,this->get(this,j));
                        this->set(this,j,aux);
                    }

                }
            }
        }

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** pAux;


    if(this != NULL )
    {
        pAux = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize + AL_INCREMENT));
        if(pAux != NULL)
        {
            this->pElements = pAux;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }


    return returnAux;

}

/** \brief Decrement the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */

int resizeDown(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL )
    {
        this->pElements = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize - AL_INCREMENT));
        this->reservedSize = this->reservedSize - AL_INCREMENT;

        returnAux = 0;

    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && index>=0 && index<=this->len(this))
    {
        this->size++;
        resizeUp(this);

        for(i=this->len(this)-1; i>index; i--)
        {

             this->set(this,i,this->get(this, i-1 ));
        }
        returnAux = 0;

    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;


    if(this != NULL && index>=0 && index<(this->len(this)) )
    {

        for(i=index; i<this->len(this); i++)
        {

            this->set(this,i,this->get(this, i+1 ));

        }
        this->size--;
        returnAux = 0;

    }

    return returnAux;
}
