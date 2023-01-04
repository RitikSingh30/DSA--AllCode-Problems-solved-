int tour(petrolPump p[],int n)
{
    int i = 0 , j = 0 ;
    int sum = 0 , ind = -1 ;
    while(i < n){
        int x = p[j].petrol - p[j].distance ;
        sum += x ;
        bool fang = true ;
        while(sum < 0 and i != j and i < n){
            sum -= (p[i].petrol - p[i].distance) ;
            i++ ;
            fang = false ;
        }
        if(i == j and sum < 0){
            sum -= (p[i].petrol - p[i].distance) ;
            i++ ;
        }
        j++ ;
        if(j == i and fang){
            ind = i ;
            break ;
        }
        if(j >= n) j = 0 ; 
        if(j == i and fang){
            ind = i ;
            break ;
        }
    }  
    return ind ;
}