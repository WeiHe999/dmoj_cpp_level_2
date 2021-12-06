#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int num_levels, t_level, t_start, level_start, level_end, num_persons, tot_time=0;
    cin >> num_levels >> t_level >> num_persons;
    int up_time = num_levels * t_level, period_time = 2 * up_time;
    bool elevator_up = true, person_up;
    for (int x = 0; x < num_persons; x++)
    {
        cin >> t_start >> level_start >> level_end;
        if (level_end > level_start) person_up = true;
        else person_up = false;
        int t_wait, t_travel, t_first, wait_periods;
        if (person_up)
        {
            t_first = t_level * level_start;
            if (t_start<=t_first)
            {
                t_wait = t_first - t_start;
            }
            else
            {
                wait_periods = ceil((t_start - t_first)*1.0/period_time);
                t_wait = wait_periods * period_time + (t_first - t_start);
            }
            t_travel = (level_end - level_start) * t_level;
            tot_time += (t_wait+t_travel);
        }
        else
        {
            t_first = period_time - t_level * level_start;
            if (t_start<=t_first)
            {
                t_wait = t_first - t_start;
            }
            else
            {
                wait_periods = ceil((t_start - t_first)*1.0/period_time);
                t_wait = wait_periods * period_time + (t_first - t_start);
            }
            t_travel = (level_start - level_end) * t_level;
            tot_time += (t_wait+t_travel);
        }
    }
    cout << tot_time << endl;
}
