#include <iostream>
#include <vector>
#include <algorithm>
 

const int max_deadline {15} ;

struct Job {
    char taskID;
    int deadline, profit;
};
 

void schedulejobs(std::vector<Job> jobs)       
{
    
    int profit = 0;
    std::vector<char> slot(15,1);
    std::sort(jobs.begin(), jobs.end(),[](Job &a, Job &b) 
    {return a.profit > b.profit; });
    for (const Job &job: jobs)
    {
        for (int j = job.deadline - 1; j >= 0; j--)
        {
            if (j < max_deadline && slot[j] == 1 )
            {
                slot[j] = job.taskID;
                profit += job.profit;
                break;
            }
        }
    }

    std::cout << "The scheduled jobs are ";
    for (int i = 0; i < max_deadline; i++)
    {
        if (slot[i] != 1) {
            std::cout << slot[i] << " ";
        }
    }

    std::cout << std::endl <<  "The total profit earned is " << profit;
}
 
int main()
{
    std::vector<Job> jobs {
        { 'a', 9, 15 }, { 'b', 2, 2 }, { 'c', 5, 18 }, { 'd', 7, 1 }, { 'e', 4, 25 },
        { 'f', 2, 20 }, { 'g', 5, 8 }, { 'h', 7, 10 }, { 'i', 4, 12 }, { 'h', 3, 5 }
    };
    schedulejobs(jobs);
    return 0;
}
