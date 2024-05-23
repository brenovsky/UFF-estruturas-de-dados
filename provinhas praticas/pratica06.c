void simetrica(TNoA* a){
    if (a!= NULL){
        simetrica(a->esq);
        printf("%c ",a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA* a){
    if (a!= NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c ",a->info);
    }
}