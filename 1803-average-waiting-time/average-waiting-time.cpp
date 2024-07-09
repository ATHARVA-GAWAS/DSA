class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_wait_time = 0;
        int curr_time = 0;
        int n=customers.size();

        for (auto& customer : customers) {
            int arrival = customer[0];
            int time_needed = customer[1];
            if (curr_time < arrival) {
                curr_time = arrival;
            }
            int waiting_time = curr_time - arrival + time_needed;
            total_wait_time += waiting_time;
            curr_time += time_needed;
        }

        return total_wait_time/n;
    }
};