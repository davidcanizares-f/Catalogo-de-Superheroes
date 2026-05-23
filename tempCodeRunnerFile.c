    while((scanf("%d", ptrnumSupers) !=1) || (*ptrnumSupers)<=0 || (*ptrnumSupers) > 10){
        printf("[ERROR]: DATO INVALIDO. INGRESE NUEVAMENTE.\n");
        while(getchar()!='\n');
        printf("\nIngrese el numero de Superheroes a registrar: ");

    }
    getchar();