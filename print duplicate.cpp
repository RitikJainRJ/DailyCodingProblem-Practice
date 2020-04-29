void printDuplicates(int arr[], int n){
    bool flag = false;

    for(int i = 0; i < n; i++){
        int j = arr[i] % n;
        arr[j] = arr[j] + n;
    }
    for(int i = 0; i < n; i++)
        if(arr[i] / n > 1){
            cout << i << " ";
            flag = true;
        }
    if(!flag)
        cout << -1 << " ";
}
