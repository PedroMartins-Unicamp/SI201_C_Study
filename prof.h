#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No * esq;
    struct No * dir;
}No;

typedef struct Tree {
    No * raiz;
}Tree;

typedef struct Lista{
    int *v;
    int top,max;
}Lista;

Lista * newLista(int max){
    Lista * aux = (Lista *)malloc(sizeof(Lista));
    aux->top = 0;
    aux->max = max;
    aux->v = (int *)malloc(sizeof(int)*max);
    return aux;
}

void printL(Lista *l){
    printf("[");
    for(int i=0;i<l->top;i++){
        printf("%d",l->v[i]);
        if(i<l->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

void addL(Lista *l, int valor){
    if(l->top==l->max){
        printf("Lista cheia\n");
        exit(0);
    }
    l->v[l->top++]=valor;
}


No * newNo(int valor){
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}
Tree * newTree(){
    Tree * aux  = (Tree *)malloc(sizeof(Tree));
    aux->raiz = NULL;
    return aux;
}
/** adiciona um elemento na árvore.
 * Assumo que t não é null.
 */
void addNo(No * t,int valor){
    if(valor<t->valor){
        //inserir esquerdo
        if(t->esq==NULL){
            t->esq = newNo(valor);
        }else{
            addNo(t->esq,valor);
        }
    }else{
        //inserir direito
        if(t->dir==NULL){
            t->dir = newNo(valor);
        }else{
            addNo(t->dir,valor);
        }
    }
    
}
void addNoT(Tree * t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

No * buscaRec(No *no,int valor){
    if(no==NULL){
        return NULL;
    }else{
        if(no->valor==valor){
            return no;
        }else{
            if(valor<no->valor){
                return buscaRec(no->esq,valor);
            }else{
                return buscaRec(no->dir,valor);
            }
        }
    }
}

No * buscaIterativa(No *no,int valor){
    No * aux = no;
    while(aux!=NULL){
        if(aux->valor==valor){
            return aux;
        }
        if(valor<aux->valor){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }
    return NULL;
}

//em ordem
void print(No *no){
    if(no!=NULL){
        print(no->esq);
        printf(" %d",no->valor);
        print(no->dir);
    }
}

//preOrdem
void printPreOrdem(No *no){
    if(no!=NULL){
        printf(" %d",no->valor);
        printPreOrdem(no->esq);
        printPreOrdem(no->dir);
    }
}

//posOrdem
void printPosOrdem(No *no){
    if(no!=NULL){
        printPosOrdem(no->esq);
        printPosOrdem(no->dir);
        printf(" %d",no->valor);
    }
}



void printT(Tree *t){
    if(t->raiz==NULL){
        printf("()");
    }else{
        print(t->raiz);
    }
    printf("\n");
}

void percurso(No * no,Lista *l){
    if(no!=NULL){
        percurso(no->esq,l);
        addL(l,no->valor);
        percurso(no->dir,l);
    }
}

void embaralha(Lista *l){
    for(int i=0;i<l->top;i++){
        int ran = rand()%l->top;
        int aux = l->v[i];
        l->v[i] = l->v[ran];
        l->v[ran]=aux;
    }
}

int size(No *t){
    if(t==NULL){
        return 0;
    }else{
        int sizeEsq = size(t->esq);
        int sizeDir = size(t->dir);
        return 1+sizeEsq+sizeDir;
    }
}
//size sem recursão
int size(No *t){
    if(t==NULL){
        return 0;
    }
    //criar uma pilha de nós chamada p
    //vou colocar a raiz na pilha
    
    //enquanto pilha não vazia
    
        // no <- desmpilha(p)
        // size++
        //add na pilha no->esq e no->dir se
        //forem diferentes de NULL
    
}





//
int altura(No *t){
    if(t==NULL){
        return -1;
    }else{
        int he = altura(t->esq);
        int hd = altura(t->dir);
        if(he>hd){
            return he+1;
        }else{
            return hd+1;
        }
    }
}

int abs(int a){
    return a>=0 ? a : -a;
}
int max3(int a, int b, int c){
    int maxAB;
    if(a>b){
        maxAB = a;
    }else{
        maxAB = b;
    }
    if(c>maxAB){
        return c;
    }else{
        return maxAB;
    }
}
int balanceamento(No *t){
    if(t==NULL){
        return 0;
    }else{
        int he = altura(t->esq);
        int hd = altura(t->dir);
        
        int be = balanceamento(t->esq);
        int bd = balanceamento(t->dir);
        int bNo =  abs(hd-he);
        return max3(be,bd,bNo);
    }
}

void ordenaL(Lista *l){
    if(l->top==0){
        return;
    }
    Tree * t = newTree();
    embaralha(l);
    for(int i=0;i<l->top;i++){
        addNoT(t,l->v[i]);
    }
    
    printf("ALTURA TREE: %d\n",altura(t->raiz));
    printf("SIZE TREE: %d\n",size(t->raiz));
    
    
    l->top = 0;
    percurso(t->raiz,l);
}


int minT(Tree * t){
    if(t->raiz==NULL){
        printf("Arvore Vazia\n");
        exit(0);
    }
    No * min = t->raiz;
    while(min->esq!=NULL){
        min=min->esq;
    }
    return min->valor;
}

int maxT(Tree * t){
    if(t->raiz==NULL){
        printf("Arvore Vazia\n");
        exit(0);
    }
    No * max = t->raiz;
    while(max->dir!=NULL){
        max=max->dir;
    }
    return max->valor;
}

void printXml(No * no, FILE * fp){
    fprintf(fp,"%d\n",no->valor);
    if(no->esq!=NULL){
        fprintf(fp,"<esq>\n");
        printXml(no->esq,fp);
        fprintf(fp,"</esq>\n");
    }
    if(no->dir!=NULL){
        fprintf(fp,"<dir>\n");
        printXml(no->dir,fp);
        fprintf(fp,"</dir>\n");
    }
}


void printXmlT(Tree *t){
    FILE * fp;
    fp = fopen("Tree.xml","w+");
    fprintf(fp,"<Tree>\n");
    if(t->raiz!=NULL){
        printXml(t->raiz,fp);
    }
    fprintf(fp,"</Tree>\n");
    fclose(fp);
}

int inter(Lista* l1, Lista *l2){
    
    Tree * t = newTree();
    embaralha(l2);
    for(int i=0;i<l2->top;i++){
        addNoT(t,l2->v[i]);
    }
    printf("ALTURA %d\n",altura(t->raiz));
    printXmlT(t);
    int intersec =0;
    for(int i=0;i<l1->top;i++){
        if(buscaIterativa(t->raiz,l1->v[i])!=NULL){
          intersec++;
        }
    }
    
    return intersec;
}

void interseccaoX(){
    int n1 = 100;
    int n2 = 200;
    Lista *l1 = newLista(n1);
    Lista *l2 = newLista(n2);
    for(int i=0;i<n1;i++){
        addL(l1,i*5);
    }
    for(int i=0;i<n2;i++){
        addL(l2,i*5);
    }
    printf("Inter:%d\n",inter(l1,l2));
    exit(0);
    
}



int main()
{
    
    Tree * t = newTree();
    int n=1000;//2^20
    for(int i=0;i<n;i++){
        addNoT(t,rand()%n);
        //addNoT(t,i);
    }
    
    //printT(t);
    
    printf("Altura = %d\n",altura(t->raiz));
    printf("Size = %d\n",size(t->raiz));
    
    /*Tree * t = newTree();
    
    interseccaoX();
    
    //printT(t);
    
    //printf("hellow\n");
    
    int n = 100*1000;
    
    Lista * l = newLista(n);
    for(int i=0;i<n;i++){
        addL(l,i+1);
    }
    
   
   clock_t start, end;
     double cpu_time_used;
     
     start = clock();
   
    
    //printL(l);
    
    
    ordenaL(l);
    
    
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("[%.3lfs]\n",cpu_time_used);
    
    
    
    l->top = 20;
    printL(l);
    */
    
    
}
/**
 Faça um programa que calcula o fator de balanceamento
 de uma ávore. O fator de balanceamento está definido
 abaixo.
 
 O fator de balanceamento de um nó é igual
 a ABS(h(esq)-h(dir)).
 
 O fator de balanceamento de uma árvore é o
 máximo fator considerando todos os nós.
 
 ------------------
 Calcule o número de nós de uma árvore sem usar recursão.
 Você deve usar uma pilha.
 
 */
