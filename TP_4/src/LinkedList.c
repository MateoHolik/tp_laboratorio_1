#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this ->size;
    }
    return returnAux;
}



static Node* getNode(LinkedList* this, int nodeIndex)//indice del nodo a obtener(nodeIndex)(nodeIndex es 0)
//recorre hasta el puntero anterior al que queremos porque ahi se aloja el puntero al nodo que sigue
{
	Node* pNode;
	pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) //len retorna la long de la lista
	{
		pNode = this->pFirstNode;

		for(int i=0; i < nodeIndex; i++)
		{
			pNode = pNode -> pNextNode;
		}

	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

/* version clase
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNuevoNodo = NULL;
    Node* pAuxNodo=NULL;

    if(this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))
    {
    	pNuevoNodo = (Node*)malloc(sizeof(Node));

    	if(pNuevoNodo != NULL)
    	{
    		if(nodeIndex == 0)
    		{
    			pNuevoNodo ->pNextNode = this ->pFirstNode;
    			this -> pFirstNode = pNuevoNodo;
    			pNuevoNodo->pElement = pElement;
    			this->size++;
    			returnAux = 0;
    		}
    		else
    		{
    			pAuxNodo = getNode(this, nodeIndex -1);

    			if(pAuxNodo != NULL)
    			{
    				pNuevoNodo->pNextNode = pAuxNodo-> pNextNode;
    				//indice 5              indice 4 -> NULL
    				pAuxNodo->pNextNode = pNuevoNodo;
    				pNuevoNodo -> pElement = pElement;
    				this->size ++;
    				returnAux = 0;
    			}
    		}

    	}
    }
    return returnAux;
}
*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* nodoAnterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	Node* nodoNuevo = (Node*)malloc(sizeof(Node));

    	nodoNuevo->pElement = pElement;

    	if (nodeIndex ==0) //CONTROL PARA EL FIRSTNODE
    	{
    		nodoNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode = nodoNuevo;
    	}
    	else
    	{
    		nodoAnterior = getNode(this,nodeIndex-1); //LLAMO EL GETNODE NODINDEX-1 PARA RECUPERAR EL NODO ANTERIOR
			nodoNuevo->pNextNode = nodoAnterior->pNextNode; //nodoNuevo GUARDA EL NODO SIGIENTE
    		nodoAnterior->pNextNode = nodoNuevo; //nodoAnterior GUARDA EL NUEVO
    	}
    	this->size++;
		returnAux = 0;

    }

   	return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{

    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement) //agrega el nodo en alguna posicion
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}


void* ll_get(LinkedList* this, int index)//obtiene el elemento del nodo
{
    void* returnAux = NULL;
    Node* pNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);

    	if(pNodo != NULL)
    	{
    		returnAux = pNodo -> pElement;
    	}
    }
    return returnAux;
}



int ll_set(LinkedList* this, int index, void* pElement)//camiba el elemento de un nodo le asigna otro
{
    int returnAux = -1;
    Node* pNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
       {
       		pNodo = getNode(this, index); // guarda la dire de memo /se obtiene el nodo en el indice que pedimos

       		if(pNodo != NULL)
       		{
       			pNodo->pElement = pElement; //pEelement = puntero a void
       			returnAux = 0;
       		}
       }

    return returnAux;
}




/* version clase
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pNodeAux = NULL;
    Node* pNodeAuxDos = NULL;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeAux = getNode(this, index);
    	if(pNodeAux != NULL)
    	{
    		if(index == 0)
    		{
    			this->pFirstNode = pNodeAux->pNextNode; //apuntas al nodo siguiente para borrar uno
    			this -> size --;
    			free(pNodeAux);
    			returnAux = 0;
    		}
    		else
    		{
    			pNodeAuxDos = getNode(this, index -1);
    			if(pNodeAuxDos != NULL)
    			{
    				pNodeAuxDos->pNextNode = pNodeAux -> pNextNode;
    			}
    		}
    		this->size--;
    		free(pNodeAux);
    		returnAux = 0;
    	}
    }

    return returnAux;
}
*/
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAux;
    Node* pNodeAnterior;
    if(this!=NULL && index>=0 && index <ll_len(this))
    {
    	nodoAux=getNode(this, index);
    	pNodeAnterior=getNode(this, index-1);
    	if(nodoAux != NULL)
    	{
    		if(index==0)
    		{
    			//this->pFirstNode=NULL; coreccion, si lo dejaba en NULL rompia los nodos...
    			this->pFirstNode = nodoAux->pNextNode;
    		}else
    		{
    			pNodeAnterior->pNextNode = nodoAux->pNextNode;
    		}
    		// me falta llamada al free. chequear siempre
    		free(nodoAux);
    		this->size--;
    		returnAux=0;
    	}
    }

    return returnAux;
}




/* version clase
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int largo;


    if(this != NULL)
    {
    	largo = ll_len(this);

    	if(largo > 0 )
    	{
    		for(int i = 0; i < largo; i++ )
    		{
    			ll_remove(this, i);
    		}
    		returnAux = 0;
    	}
    }

    return returnAux;
}
*/
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int largo;


    if(this != NULL)
    {
    	largo = ll_len(this);
		while(largo > 0)
		{
			ll_remove(this, 0);
			largo--;
		}

		returnAux = 0;
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;



    if(this != NULL && ll_clear(this) == 0)
    {
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(int i = 0; i < len; i++)
    	{
    		if( ll_get(this, i)== pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL )
    {
    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))//menor o igual, para
    {
    		returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);

    	ll_remove(this, index);
    }

    return returnAux;
}



/*version clase
 *
 int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if(this != NULL)
    {
    	if(ll_len(this) != -1) //SAQUEPUNTERO AL ELEMENTO EN EL LLAMADO AL LL_LEN

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
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoAux = NULL;
    int i;

    if(this != NULL)
    {
        returnAux = 0;
        for(i = 0; i < ll_len(this); i++)
        {
        	nodoAux = getNode(this, i);
            if(nodoAux->pElement == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElementAux = NULL;
    int retorno;
    int i;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < ll_len(this2); i++)
        {
        	pElementAux = ll_get(this, i);
            retorno = ll_contains(this2, pElementAux);
            if(retorno == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}


/* CLASE
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* pElement = NULL;

    if(this != NULL && this2 != NULL)
    {
    	len = ll_len(this);

    	returnAux = 1;

    	for(int i = 0; i < len; i++)
    	{
    		pElement = ll_get(this2, i);

			if(ll_contains(this, pElement)== 0)
			{
				returnAux = 0;
				break;
			}
    	}
    }

    return returnAux;
}*/


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElementAux;

    if(this!=NULL)
    {
    	if(from>=0 && from<=ll_len(this) && to > from && to<= ll_len(this))
    	{
    		cloneArray=ll_newLinkedList();

    		if(cloneArray!= NULL)
    		{
    			for(i=from; i<to; i++)
    			{
    				pElementAux = ll_get(this, i);
    				//validar si metio el dato y con el retorno controlar si salio ok o dio mal
    				ll_add(cloneArray, pElementAux);
    			}
    		}
    	}
    }

    return cloneArray;
}



/* CLASE
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    Node* auxNode = NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this)) //>= porque podria empezar en el indice 0
    {
    	subList = ll_newLinkedList();

    	if(subList != NULL)
    	{
    		for(int i=from; i<to; i++)
    		{
    			auxNode = getNode(this, i); //traes al nodo
    			ll_add(subList, auxNode);
    		}
    	}
    }
    return subList;
}*/




LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone = NULL;

    if(this != NULL)
    {
    	clone = ll_subList(this, 0, ll_len(this));
    }

    return clone;
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* pElementAux1;
    void* pElementAux2;
    int i;
    int flagSort;
    int length;

    if(this!=NULL && order>=0 && pFunc != NULL)
    {
        length = ll_len(this);

        do
        {
        	flagSort=0;

            for (i = 0; i < length-1; i++)
            {
            	pElementAux1 = ll_get(this, i);
            	pElementAux2 = ll_get(this, i + 1);

                if( ((pFunc(pElementAux1, pElementAux2) < 0) && !order) || ((pFunc(pElementAux1, pElementAux2) > 0) && order) )
                {
                    ll_set(this, i, pElementAux2);
                    ll_set(this, i + 1, pElementAux1);
                    flagSort = 1;
                }
            }
        }while(flagSort);

        returnAux = 0;
    }
    return returnAux;
}



/* clase
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int estaOrdenado;
    int len;
    void* auxElemento = NULL;
    void* auxElemento2 = NULL;

    if(this != NULL && (order == 0 || order == 1) && pFunc != NULL)
    {
    	len = ll_len(this);
    	do
    	{
    		estaOrdenado = 1;
    		len --;

    		for(int i = 0; i< len; i++)
    		{
    			auxElemento = ll_get(this, i);
    			auxElemento2 = ll_get(this, i+1);
    			if((pFunc(auxElemento, auxElemento2) > 0 && order == 1) || (order == 0 && pFunc(auxElemento, auxElemento2) < 0))//ascendente el orden, func criterio dice q el segundo es mayor
    			{
    				//pFunc dice que el segundo elemento es mayor
    				ll_set(this, i, auxElemento2);
    				ll_set(this, i+1, auxElemento);
    				estaOrdenado = 0;

    	    		ll_set(this, i, auxElemento2);
    	    		ll_set(this, i+1, auxElemento);
    	    		estaOrdenado = 0;
    	    	}

    			//aux = pArray[i];
    			 //pArray[i+1] = aux;

    			 estaOrdenado = 0;

    		}
    	}while(estaOrdenado == 0);
    }

    return returnAux;

}*/

