async function bubble_sort1(){
    for (let end = Arr.length-1 ; end > 0 ; end--){
        for (let i = 0 ; i < end ; i++){
            if ( await compare(Arr[i], Arr[i+1]) > 0 ){
                await swap(Arr, i, i+1);
            }
        }
    }
}