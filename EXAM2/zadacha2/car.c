int compareModelAsc(const void* a, const void* b){
    return strcmp(((car*)a) -> model, ((car*)b) -> model);
}

int compareModelDesc(const void* a, const void* b){
    return strcmp(((car*)b) -> model, ((car*)a) -> model);
}
int compareMaxSpeedAsc(const void* a, const void* b){
    return ((car*)a) -> maxspeed - ((car*)b) -> maxspeed;
}

int compareMaxSpeedDesc(const void* a, const void* b){
    return ((car*)b) -> maxspeed - ((car*)a) -> maxspeed;
}

int comparePriceAsc(const void* a, const void* b){
    if(fabs((((car*)a) -> price - ((car*)b) -> price)) < EPS){
        return 0;
    } else if(((car*)a) -> price > ((car*)b) -> price){
        return 1;
    }
    return -1;
}

int comparePriceDesc(const void* a, const void* b){
    if(fabs((((car*)b) -> price - ((car*)a) -> price)) < EPS){
        return 0;
    } else if(((car*)b) -> price > ((car*)a) -> price){
        return 1;
    }
    return -1;
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printCars(car* arr, size_t n){
    for(int i = 0; i < n; i++){
        printf("Model: %s, ", arr[i].model);
        printf("Max Speed: %u km/h, ", arr[i].maxspeed);
        printf("Price: %.2lf lv.\n", arr[i].price);
    }
}

int (*getComparator(int n))(const void*, const void*){ //стигнах до тук при подадено n, различно от 1 до 6 (което е грешно) реално изкарва 10 random коли, но не сортирани по никакъв начин, нямам време да я довърша
    if(n == 1){
        return compareModelAsc;
    } else if(n == 2){
        return compareModelDesc;
    } else if (n == 3){
        return compareMaxSpeedAsc;
    } else if (n == 4){
        return compareMaxSpeedDesc;
    } else if (n == 5){
        return comparePriceAsc;
    } else if (n == 6){
        return comparePriceDesc;
    } else return NULL;
}