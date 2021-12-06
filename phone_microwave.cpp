using namespace std;



int main()
{
    int delta_hrs;
    cin >> delta_hrs;
    cin.ignore();
    string s;
    getline(cin, s);
    struct tm tm;
    std::string s1=s;
    if (strptime(s1.c_str(), "%Y/%m/%d %H:%M:%S", &tm)) {
        int d = tm.tm_mday,
            m = tm.tm_mon + 1,
            y = tm.tm_year + 1900;
    }  
    
    long long timeSinceEpoch = mktime(&tm);

    time_t delta_seconds = delta_hrs * 60*60;
    time_t timeSinceEpoch_new = timeSinceEpoch - delta_seconds;
    
    struct tm tm2;
    memcpy(&tm2, localtime(&timeSinceEpoch_new), sizeof (struct tm));
    std::cout << tm2.tm_year+1900 << "/" << setw(2) << setfill('0') << tm2.tm_mon+1 << "/" << setw(2) << setfill('0') << tm2.tm_mday << " "
                     << setw(2) << setfill('0') << tm2.tm_hour << ":" << setw(2) << setfill('0')<< tm2.tm_min << ":" << setw(2) << setfill('0')<< tm2.tm_sec << endl;   
    
    

}
