async function bubble_sort3(){
    for (let i = 0 ; i < Arr.length-1 ; i++){
        for (let j = i+1 ; j < Arr.length ; j++){
            if ( await compare(Arr[i], Arr[j]) > 0 ){
                await swap(Arr, i, j);
            }
        }
    }
}