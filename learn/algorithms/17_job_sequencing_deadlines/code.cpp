#include <iostream>
#include <vector>
#include <algorithm>

struct Job{
    int profit;
    int deadline;
    Job(int deadline, int profit)
    {
        this->profit = profit;
        this->deadline = deadline;
    }
    Job()
    {
        this->profit = -1;
        this->deadline = -1;
    }
};

int get_num_of_slots(std::vector<Job> &jobs)
{
    int num_of_slots(0);
    for(Job job: jobs)
    {
        if(job.deadline > num_of_slots)
        {
            num_of_slots = job.deadline;
        }
    }
    return num_of_slots;
}

std::pair<int, std::vector<Job>> job_scheduling(std::vector<Job> &jobs)
{
    int slots = get_num_of_slots(jobs);
    std::sort(jobs.begin(), jobs.end(), [](auto &a, auto &b)
    {
        return a.profit > b.profit;
    });
    std::vector<Job> res(slots);
    int total_profits(0);
    for(Job job: jobs)
    {
        int deadline = job.deadline;
        for(int j(deadline - 1); j > -1; j--)
        {
            if(res[j].deadline == -1 && res[j].profit == -1)
            {
                res[j] = job;
                total_profits += job.profit;
                break;
            }
        }
    }
    return std::make_pair(total_profits, res);
}

int main()
{
    std::vector<Job> jobs({Job(2, 100), Job(1, 50), Job(2, 10), 
                Job(1, 20), Job(3, 30)});

    std::pair<int, std::vector<Job>> res = job_scheduling(jobs);
    std::cout << "Total profit: " << res.first << std::endl;
    std::cout << "Jobs:\n";
    for(Job job: res.second)
    {
        std::cout << "Deadline: " << job.deadline;
        std::cout << " Profit: " << job.profit << std::endl;
    }
    return 0;
}