#include<stdio.h>
#include<stdlib.h>
typedef struct node{	//Estructura del nodo
	int dato;
	struct node *sgte;
}*nodo,tipoNodo;

typedef struct{		//Estructura de la lista
	nodo front;
	nodo last;
}*lista, tipoLista;

nodo crearNodo(int valor){		//Metodo para crear un Nodo con un valor
	nodo elemento=(nodo) malloc(sizeof(tipoNodo));
	elemento->dato= valor;
	elemento->sgte = NULL;
	return elemento;
}
lista crearLista(){		//Metodo para crear la lista
  lista List = (lista) malloc(sizeof(tipoLista));
  List->front = NULL; 
  List->last = NULL;
  return List;
}
void insertFront(int valor, lista List){	//Metodo para agregar al inicio de la fila, tiene como parametro un valor entero y la lista a la que se va a guardar
	nodo elemento=crearNodo(valor);
	if(empty(List)){	//Metodo para saber si esta vacia, se puede encontrar declarado mas abajo
		elemento->sgte=NULL;
		List->front=elemento;
		List->last=elemento;
	}
	else{
	    elemento->sgte = List->front;
	    List->front=elemento;
    }
}
void insertLast(int valor, lista List){	//Metodo para agragar al final de la fila, tiene los mismos parametros que insertFront
	if(List->last==NULL){
	nodo elemento=crearNodo(valor);
	List->front=elemento;
	List->last=elemento;
}else{
	nodo elemento=crearNodo(valor);
	elemento->sgte=NULL;
	List->last->sgte=elemento;
	List->last=elemento;
}
}
int first(lista List){	//Regresa el primer dato sin eliminar
	int primero;
	if(List->front==NULL){
		printf("\nLa lista esta vacia");
	}
	primero=List->front->dato;
	return primero;
}
int last(lista List){	//Regresa el ultimo dato sin eliminarlo
	int ultimo;
	ultimo=List->last->dato;
	return ultimo;
}

int deleteFront(lista List){	//Metodo para eliminar el nodo que esta al principio y retorna el valor que elimino
	int primero;
	if(size(List)==1){
		nodo elemento=List->front;
		primero= elemento->dato;
		List->front=NULL;
		List->last=NULL;
		free(elemento);
	}
	else{
		nodo elemento=List->front;
		primero=elemento->dato;
		List->front=elemento->sgte;
		free(elemento);
	}
	return primero;
}

int deleteLast(lista List){		//Metodo para eliminar el nodo que esta al final y retorna el valor que elimino
	int ultimo;
	if(size(List)==1){
		nodo elemento=List->last;
		ultimo=elemento->dato;
		List->front=NULL;
		List->last=NULL;
		free(elemento);
	}
	else{
		int i;
		nodo aux=List->front;
		nodo elemento=List->last;
		ultimo=elemento->dato;
		for(i=2;i<size(List);i++){
			aux=aux->sgte;
		}
		aux->sgte=elemento->sgte;
		List->last=aux;
		free(elemento);
	}
	return ultimo;
}

int Delete(int pos,lista List){		//Metodo para elimiar un nodo en determinada posicion, tiene como parametro un dato entero que sera la posicion y la lista
	int numero;
	if(pos==1){
		numero=deleteFront(List);
	}
	else{
		if(pos==size(List)){
			numero=deleteLast(List);
		}
		else{
			int i;
			nodo aux=List->front;
			for(i=2;i<pos;i++){
				aux=aux->sgte;
			}
			nodo elemento=aux->sgte;
			numero=elemento->dato;
			aux->sgte=elemento->sgte;
			free(elemento);
		}
	}
	return numero;
}

void insert(int valor,int pos,lista List){		//Metodo para insertar un valor en determinada posicion, tiene como parametros dos enteros que seran posicion y 
	if(pos==1){									//valor y otro tipo lista que sera la lista donde esta el dato
		insertFront(valor,List);
	}
	else{
		int i;
		nodo elemento=crearNodo(valor);
		nodo aux=List->front;
		for(i=2;i<pos;i++){
			aux=aux->sgte;
		}
		elemento->sgte=aux->sgte;
		aux->sgte=elemento;
	}
}

int size(lista List){		//Metodo para saber el tama�o de la lista
	int contador=0;
	nodo actual=List->front;
	while(actual!=NULL){
		contador++;
		actual=actual->sgte;
	}
	return contador;
}

int empty(lista List){		//Metodo nombrado anteriormente para saber si esta vacia
	return(List->front==NULL);
}
void mostrarLista(lista List){		//Metodo para mostrar todos los datos de la lista
	nodo aux;
	aux=List->front;
	if(aux==NULL){
		printf("\nLa lista esta vacia");
	}
	while(aux!=NULL){
		printf("->");
		printf("%d",aux->dato);
		aux=aux->sgte;
	}
}
int main(){
	int x=0,i,dato=0,pos=0;
	lista d=crearLista();
	do{
		printf("\n--------------------------------------------------\n");
		printf("1. Para agregar al principio de la fila\n");
		printf("2. Para agregar al final de la fila\n");
		printf("3. Para mostrar el primer numero de la lista\n");
		printf("4. Para mostrar el ultimo numero de la lista\n");
		printf("5. Para eliminar el primer dato\n");
		printf("6. Para eliminar el ultimo dato\n");
		printf("7. Para eliminar el dato de una posicion digitada\n");
		printf("8. Para insertar un dato en una posicion digitada\n");
		printf("9. Para mostrar todos los datos de la fila\n");
		printf("0. Para salir\n");
		printf("--------------------------------------------------\n");
		printf("Digite una opcion: ");
		scanf("%d",&x);
		switch(x){
			case 0:
				printf("\nHa salido con exito");
			break;
			case 1:
				printf("\nDigite el dato a ingresar: ");
				scanf("%d",&dato);
				insertFront(dato,d);
			break;
			case 2:
				printf("\nDigite el dato a ingresar: ");
				scanf("%d",&dato);
				insertLast(dato,d);
			break;
			case 3:
				dato=first(d);
				printf("\nEl primer dato de la lista es: %d",dato);
			break;
			case 4:
				dato=last(d);
				printf("\nEl ultimo dato de la lista es: %d",dato);
			break;
			case 5:
				dato=deleteFront(d);
				printf("\nSe ha eliminado el dato: %d",dato);
			break;
			case 6:
				dato=deleteLast(d);
				printf("\nSe ha eliminado el dato: %d",dato);
			break;
			case 7:
				printf("\nDigite la posicion del dato del dato a eliminar: ");
				scanf("%d",&pos);
				dato=Delete(pos,d);
				printf("\nEl dato eliminado es %d",dato);
			break;
			case 8:
				printf("\nDigite la posicion del dato a ingresar: ");
				scanf("%d",&pos);
				printf("\nDigite el dato a ingresar: ");
				scanf("%d",&dato);
				insert(dato,pos,d);
			break;
			case 9:
				mostrarLista(d);
			break;
			default:
				printf("\nDigite una opcion correcta");
		}
	}while(x!=0);
	return 0;
}
