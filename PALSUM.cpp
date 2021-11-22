#include <iostream>

#include <vector>
#include <array>

int constructNthNumber(int group_no, int aux_num, int op)
{
    int INT_SIZE = 32;
    int a[INT_SIZE] = {0};
    int num = 0, len_f;
    int i = 0;

    if (op == 2)
    {

        len_f = 2 * group_no;

        a[len_f - 1] = a[0] = 1;

        while (aux_num)
        {


            a[group_no + i] = a[group_no - 1 - i] = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }

    // Insert bit 0 in the middle
    else if (op == 0)
    {

        len_f = 2 * group_no + 1;

        a[len_f - 1] = a[0] = 1;
        a[group_no] = 0;

        while (aux_num)
        {

            a[group_no + 1 + i] = a[group_no - 1 - i] = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }

    else
    {

        len_f = 2 * group_no + 1;

        a[len_f - 1] = a[0] = 1;
        a[group_no] = 1;

        while (aux_num)
        {

            a[group_no + 1 + i] = a[group_no - 1 - i] = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }

    // Convert the number to decimal from binary
    for (i = 0; i < len_f; i++)
        num += (1 << i) * a[i];

    return num;
}

int getNthNumber(int n)
{
    int group_no = 0, group_offset;
    int count_upto_group = 0, count_temp = 1;
    int op, aux_num;

    while (count_temp < n)
    {
        group_no++;

        count_upto_group = count_temp;
        count_temp += 3 * (1 << (group_no - 1));
    }

    group_offset = n - count_upto_group - 1;

    if ((group_offset + 1) <= (1 << (group_no - 1)))
    {

        op = 2;

        aux_num = group_offset;
    }
    else
    {
        if (((group_offset + 1) -
             (1 << (group_no - 1))) %
            2)
            op = 0;
        else

            // Need to Insert 1 at middle
            op = 1;
        aux_num = ((group_offset) -
                   (1 << (group_no - 1))) /
                  2;
    }
    return constructNthNumber(group_no, aux_num, op);
}



int main()
{
    std::vector<bool> binary_palindrome(10001 , false);
     binary_palindrome[1] = true;
    for (int i{2}; i < 62; i++)
    {
        
        binary_palindrome[getNthNumber(i)] = true ;
    }
    
    // std::cout << binary_palindrome[1];

    int t{};
    std::cin >> t;

    while (t--){
        int n ;
        std::cin >> n ;
        std::vector<int> arr ; 
        
        while(n != 0 ){
            int temp {n};
                while(!binary_palindrome[temp]) temp--;
                
                arr.push_back(temp);
                n -= temp;  
        }
        std::cout << arr.size() <<std::endl;
        for (const auto &a : arr ) std::cout << a << " ";
        std::cout << std::endl;
    }

    return 0;
}
