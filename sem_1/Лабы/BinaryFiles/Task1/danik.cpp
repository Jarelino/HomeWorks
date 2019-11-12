void BubbleSHPROT(arr)
{
    bool swapped = true;

    while(swapped)
    {
        swapped = false;

        for(int i = 1; i < length; i++)
        {
            if(arr[i-1] > arr[i])
            {
                swap(arr[i-1],arr[i]]);
                swapped = true;
            }
        }
    }
}