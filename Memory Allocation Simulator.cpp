#include <iostream>
using namespace std;

void First_Fit(int Number_Of_Blocks, int Number_Of_Processes, int *block_sizes, int* processes_sizes)
{
    int* filled = new int[Number_Of_Blocks];
    int* final_arr = new int[Number_Of_Blocks];
    

    for (int i = 0; i < Number_Of_Blocks; i++)
    {
        cout << "enter the block number " << i << " size\n";
        cin >> block_sizes[i];
        filled[i]=0;
    }


    for (int j = 0; j < Number_Of_Processes; j++)
    {
        cout << "enter the Process number " << j << " size\n";
        cin >> processes_sizes[j];
    }

    for (int i = 0; i < Number_Of_Processes; i++)
    {
        for (int j = 0; j < Number_Of_Blocks; j++)
        {
            if (    ( block_sizes[j] >= processes_sizes[i] )     &&      ( filled[j]==0 )  )
            {
                final_arr[j] = processes_sizes[i];
                filled[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < Number_Of_Blocks; i++) 
    {
        if (filled[i] == 1)
       {
            cout << "block No " << i << " contains a process of size " << final_arr[i]<<"\n";
       }
        else
        {
            cout << "block No " << i << " EMPTY " <<"\n";
        }

    }
}

int main()
{
    int Number_Of_Blocks, Number_Of_Processes;
    cout << "enter the number of blocks and then the number of processes\n";
    cin >> Number_Of_Blocks;
    cin >> Number_Of_Processes;
    int *block_sizes = new int[Number_Of_Blocks];
    int *processes_sizes = new int[Number_Of_Processes];

    First_Fit(Number_Of_Blocks, Number_Of_Processes, block_sizes, processes_sizes);
    //while(!)
}
